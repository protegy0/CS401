#include <iostream>
using namespace std;

int funcCall = 0;

struct ArrayValues {
    double average;
    int sum;
    int maximum;
};

ArrayValues arrFunction(int* arr, int size) {
    ArrayValues av;
    int sum = 0;
    int max = *arr; // Initializing max as first value in array

    for (int i = 0; i < size; i++) { // For loop that iterates through array, adding all numbers together and also finding the maximum value
        sum += *(arr + i);
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    double avg = static_cast<double>(sum) / static_cast<double>(size); // Computing average with sum and size variables, casting them both to double in order to receive a double

    av.sum = sum;
    av.maximum = max;
    av.average = avg;
    funcCall++; // Iterating total num of function calls

    return av;

}

int main() {

    int size = 0;
    while (size <= 0) { // Gathering user input to create array of specified size
        cout << "Enter size of array: ";
        cin >> size;
        if (size == 0) {
            cout << "Array size cannot be zero, please enter a number above zero." << endl;
        } else if (size < 0) {
            cout << "Array size cannot be negative, please enter a number above zero." << endl;
        }
    }
    

    int num[size];

    for (int i = 0; i < size; i++) { // Gathering user input to give each array index a specified value
        cout << "Enter array value at index " << i << ": ";
        cin >> num[i];
    }

    ArrayValues av = arrFunction(num, size);

    cout << "Sum = " << av.sum << "\nAverage = " << av.average << "\nMaximum = " << av.maximum << endl; // Displaying average, maximum, and sum using struct ArrayValues

    cout << "Unsorted array: ";
    for (int i = 0; i < size; i++) { // Displaying unsorted array
        cout << num[i] << ", ";
    }
    cout << endl;

    auto sort = [&num, size]() { // Sorting array using lambda function via insertion sort
        int temp, currLoc;
        for (int i = 1; i < size; i++) {
            currLoc = i;
            while (currLoc > 0 && *(num + (currLoc - 1)) < *(num + currLoc)) {
                temp = *(num + currLoc);
                *(num + currLoc) = *(num + (currLoc - 1));
                *(num + (currLoc - 1)) = temp;
                currLoc--;
            }
        }
    };

    sort();

    cout << "Sorted array: "; // Displaying sorted array
    for (int i = 0; i < size; i++) {
        cout << num[i] << ", ";
    }
    cout << endl;

    return 0;
}