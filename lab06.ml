(*
    Lab 6: Introduction to Fold-left and Fold-right
    cc: Akshar Patel (akshar20@uab.edu), Michael Gathara (mikegtr@uab.edu)

    This assignment will help you familiarize yourself with two very
    important functions when it comes to functional programming, fold-left
    and fold-right. You will implement these functions yourself then
    implement various other functions that can use fold-left and fold-right.
    You will first implement each without using fold-left and fold-right
    followed by an implementation that does use fold-left and/or fold-right.

    After implementing these functions, please make a report:
        (1) explaining the differences in your implementations for fold-left
        and fold-right
        (2) discussing which functions required you to use fold-left and 
        which required fold-right, explaining why one was needed over the
        other

    Submission:
    - On Canvas: Required: This file, Report (pdf)
    - On Github: Required: This file  
                 Optional: Report 
*)




(*
    Fold-left: given an operator, accumulator, and list, iterate through
    the list left-to-right. With each iteration the function should
    combine the current value of the list to the accumulator using the
    input operator

    example: myFoldl + 0 [1; 2; 3; 4; 5] will output 15

    Input:
        - op: an operator for combining list value to the accumulator
        - acc: an accumulator
        - lst: a list of values
*)
let rec myFoldl op acc lst =
    match lst with
    | [] -> acc
    | x :: xs -> myFoldl op (op acc x) xs;;

(*
    Fold-right: given an operator, accumulator, and list, iterate through
    the list right-to-left. With each iteration the function should
    combine the current value of the list to the accumulator using the
    input operator

    example: myFoldr + [1; 2; 3; 4; 5] 0 will output 15

    Input:
        - op: an operator for combining list value to the accumulator
        - acc: an accumulator
        - lst: a list of values
*)
let rec myFoldr op lst acc =
    match lst with
    | [] -> acc
    | x :: xs -> op x (myFoldr op xs acc);;


(*
    Reverse: This function takes in a list and returns the reverse 
    of that list

    example: myReverse [1; 2; 3; 4] will output [4; 3; 2; 1]

    myReverse must be implemented without myFoldl and myFoldr while
    myReverseFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myReverse ?(acc=[]) lst =
    match lst with 
    | [] -> []
    | x :: xs -> myReverse xs @ [x];;


let myReverseFold lst =
    myFoldl (fun acc x -> x :: acc) [] lst;;

(*
    Map: This function takes in a list and an operator and returns a
    list where every value has had that operator applied to them

    example: myMap (fun x -> x+1) [1; 2; 3; 4] will output [2; 3; 4; 5]

    myMap must be implemented without myFoldl and myFoldr while
    myMapFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - op: an operator
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myMap ?(acc=[]) op lst =
    match lst with
    | [] -> []
    | x :: xs -> (op x) :: myMap op xs;;


let myMapFold op lst =
    myFoldr (fun x acc -> (op x) :: acc) lst [];;
(*
    Filter: This function takes in a list and a guard condition and returns a
    list only with the values that satisfy the guard condition

    example: myFilter (fun x -> x mod 2 = 0) [1; 2; 3; 4] will output [2; 4]

    myFilter must be implemented without myFoldl and myFoldr while
    myFilterFold must be implemented with myFoldl and/or myFoldr

    Input:
        - acc: an optional accumulator argument (only for non-fold version)
        - guard: an operator that returns a boolean
        - lst: a list of values

    **NOTE: There are two major ways to implement the non-fold version
    of this function. One uses the acc optional argument while the other
    doesn't. We will go into the difference between the two next week,
    but for now just implement whichever makes more sense in your head. 
*)
let rec myFilter ?(acc=[]) guard lst =
    match lst with
    | [] -> []
    | x :: xs -> if guard x then x :: myFilter guard xs else myFilter guard xs;;


let myFilterFold guard lst =
    myFoldr (fun x acc -> if guard x then x :: acc else acc) lst [];;



let () = print_string "myFoldl on [1; 2; 3; 4] ( + )\nResult = ";;
let sum = myFoldl ( + ) 0 [1; 2; 3; 4];;
let () = print_int sum;;
let () = print_endline "";;

let () = print_string "myFoldr on [1; 2; 3; 4] ( - )\nResult = ";;
let subtract = myFoldr ( - ) [1; 2; 3; 4] 0;;
let () = print_int subtract;;
let () = print_endline "";;


(*Helper function to print lists*)
let print_int_list lst =
    List.iter (fun x -> Printf.printf "%d " x) lst;;

let () = print_string "myReverse on [1; 2; 3; 4]\nResult = ";;
let reversedlst = myReverse [1; 2; 3; 4];;
print_int_list reversedlst;;
let () = print_endline "";;

let () = print_string "myMap on [1; 2; 3; 4] (fun x -> x+1)\nResult = ";;
let mappedlst = myMap (fun x -> x+1) [1; 2; 3; 4];;
print_int_list mappedlst;;
let () = print_endline "";;

let () = print_string "myFilter on [1; 2; 3; 4] (fun x -> x mod 2 = 0)\nResult = ";;
let filteredlst = myFilter (fun x -> x mod 2 = 0) [1; 2; 3; 4];;
print_int_list filteredlst;;
let () = print_endline "";;











