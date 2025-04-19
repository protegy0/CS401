/**
 * READ THE README FIRST
 * READ THE README IT HAS IMPORTANT INFORMATION
 * I PROMISE READING THE README FIRST IS BEST!!
 * READ THE README
 *
 * @authors Dr. Sidharth Kumar, Michael Gathara, Akshar Patel & Dr. Mahmut Unan
 * @brief Parallel Image Filtering Stub
 *
 * This file is a stub for parallel image filtering.
 * 
 * TODO:
 *  - Implement file reading using fopen, fseek, ftell, and fread.
 *  - Implement the blurring/filtering operation using the provided stencil size.
 *  - Implement file writing using fopen and fwrite.
 */

#include <ctype.h>
#include <fcntl.h>
#include <mpi.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static void parse_args(int argc, char **argv);

// Global dimension of dataset 2560 x 2560
static int gbs[2] = {2560, 2560};


// Default of 1 (WE WILL CHANGE THIS TO TEST YOUR CODE)
static int stencil_size = 3;

// Name of file to read
static char file_name[512] = "../data/brain_2560_2560.raw";

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank, nprocs;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    parse_args(argc, argv);

    printf("Rank %d nprocs %d\n", rank, nprocs);

    const int global_width = gbs[0];
    const int global_height = gbs[1];

    int rows_per_proc = global_height / nprocs;
    int extra_rows = global_height % nprocs;

    // Compute number of rows assigned to this process
    int local_rows = rows_per_proc + (rank < extra_rows ? 1 : 0);

    // Determine how many rows precede this rank (needed to compute offset)
    int offset_rows = rank * rows_per_proc + (rank < extra_rows ? rank : extra_rows);

    int ghost_above = (rank != 0) ? 1 : 0;
    int ghost_below = (rank != nprocs - 1) ? 1 : 0;
    int total_local_rows = local_rows + ghost_above + ghost_below;
    int buffer_rows = total_local_rows + 2 * stencil_size;

    // Allocate buffer
    unsigned char* buffer = malloc(buffer_rows * global_width * sizeof(unsigned char));
    if (buffer == NULL) {
        printf("Rank %d: Error allocating memoryn\n", rank);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    

    // READ THE FILE IN PARALLEL
    double io_read_start = MPI_Wtime();

    FILE* fp = fopen(file_name, "rb");
    if (!fp) {
        printf("Rank %d: Could not open file %s\n", rank, file_name);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    size_t offset = offset_rows * global_width * sizeof(unsigned char);
    fseek(fp, offset, SEEK_SET);

    // Read local image data
    size_t read_count = fread(buffer + ghost_above * global_width,
                              sizeof(unsigned char),
                              local_rows * global_width,
                              fp);
    if (read_count != (size_t)(local_rows * global_width)) {
        printf("Rank %d: fread error. Expected %zu, got %zu\n", rank, (size_t)(local_rows * global_width), read_count);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    fclose(fp);

    

    

    double io_read_end = MPI_Wtime();
    if (rank == 0) {
        printf("Parallel file read (fread) completed in %f seconds\n", io_read_end - io_read_start);
    }

    // GHOST (HALO) CELL EXCHANGE
    double communication_start = MPI_Wtime();
    

    MPI_Request requests[4];
    int req_count = 0;

    unsigned char *send_top = buffer + stencil_size * global_width;
    unsigned char *recv_top = buffer;
    unsigned char *send_bottom = buffer + (stencil_size + local_rows - stencil_size) * global_width;
    unsigned char *recv_bottom = buffer + (stencil_size + local_rows) * global_width;

    // Send upward, receive from below
    if (rank > 0) {
        // Send top real row to upper neighbor
        MPI_Isend(send_top, stencil_size * global_width, MPI_UNSIGNED_CHAR, rank - 1, 1, MPI_COMM_WORLD, &requests[req_count++]);
        // Receive ghost row from above
        MPI_Irecv(recv_top, stencil_size * global_width, MPI_UNSIGNED_CHAR, rank - 1, 1, MPI_COMM_WORLD, &requests[req_count++]);
    }
    // Send downward, receive from above
    if (rank < nprocs - 1) {
        // Send bottom real row to lower neighbor
        MPI_Isend(send_bottom, stencil_size * global_width, MPI_UNSIGNED_CHAR, rank + 1, 1, MPI_COMM_WORLD, &requests[req_count++]);
        // Receive ghost row from below
        MPI_Irecv(recv_bottom, stencil_size * global_width, MPI_UNSIGNED_CHAR, rank + 1, 1, MPI_COMM_WORLD, &requests[req_count++]);
    }
    // Wait for all non-blocking operations to complete
    MPI_Waitall(req_count, requests, MPI_STATUSES_IGNORE);
    
    double communication_end = MPI_Wtime();

    // PERFORM THE ACTUAL BLURING OPERATION
    double compute_start = MPI_Wtime();
    

    unsigned char *blurred = malloc(buffer_rows * global_width * sizeof(unsigned char));
    // Loop over local data region
    for (int i = stencil_size; i < stencil_size + local_rows; i++) {
        for (int j = stencil_size; j < global_width - stencil_size; j++) {
            int sum = 0;

            for (int di = -stencil_size; di <= stencil_size; di++) {
                for (int dj = -stencil_size; dj <= stencil_size; dj++) {
                    int ni = i + di;
                    int nj = j + dj;
                    sum += buffer[ni * global_width + nj];
                }
            }

            int count = (2 * stencil_size + 1) * (2 * stencil_size + 1);
            blurred[i * global_width + j] = sum / count;
        }
    }

    double compute_end = MPI_Wtime();

    // WRITE THE FILE IN PARALLEL (EXACT OPPOSITE of THE FIRST STEP)
    MPI_Barrier(MPI_COMM_WORLD); // Sync before writing
    double io_write_start = MPI_Wtime();
    

    FILE *fp_out = fopen("data/brain_2560_2560_blurred.raw", "wb");
    if (!fp_out) {
        printf("Process %d: Failed to open output.raw\n", rank);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }
    // Each process writes its chunk
    int write_rows = local_rows;
    size_t write_offset = rank * local_rows * global_width;

    fseek(fp_out, write_offset, SEEK_SET);

    // Pointer to the start of the valid blurred data
    unsigned char *valid_blur_start = blurred + (stencil_size * global_width);

    // Write the valid portion only
    fwrite(valid_blur_start, sizeof(unsigned char), write_rows * global_width, fp_out);

    fclose(fp_out);
    
    

    

    double io_write_end = MPI_Wtime();

    double total_time = io_write_end - io_read_start;
    double max_time;
    MPI_Allreduce(&total_time, &max_time, 1, MPI_DOUBLE, MPI_MAX,
                  MPI_COMM_WORLD);
    if (max_time == total_time) {
        printf(
            "Time take to blur %d x %d image is %f\n"
            "Time decomposistion (IO + COMM + COMP + IO): %f + %f + %f + %f\n",
            gbs[0], gbs[1], max_time, (io_read_end - io_read_start),
            (communication_end - communication_start),
            (compute_end - compute_start), (io_write_end - io_write_start));
    }

    
    free(buffer);
    free(blurred);
    MPI_Finalize();
    return 0;
}

static void parse_args(int argc, char **argv) {
    char flags[] = "g:s:f:";
    int one_opt = 0;
    int with_rst = 0;

    while ((one_opt = getopt(argc, argv, flags)) != EOF) {
        /* postpone error checking for after while loop */
        switch (one_opt) {
            case ('g'):  // global dimension
                if ((sscanf(optarg, "%dx%dx%d", &gbs[0], &gbs[1], &gbs[2]) ==
                     EOF))
                    exit(-1);
                break;

            case ('s'):  // local dimension
                if ((sscanf(optarg, "%d", &stencil_size) == EOF)) exit(-1);
                break;

            case ('f'):  // input file name
                if (sprintf(file_name, "%s", optarg) < 0) exit(-1);
                break;
        }
    }
}