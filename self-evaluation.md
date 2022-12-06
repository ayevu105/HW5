# Self-Evaluation

## Name(s): Anthony Vu

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Done (Anthony Vu)
History: Done (Anthony Vu)
Borrow: Done (Anthony Vu)
Return: Done (Anthony Vu)


Q: -1 for each compilation warning, min -3: 0

Could not figure how to remove parameter without breaking the code, as it is needed to print out to the system. 

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: -2

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: This can be found in the borroworreturn class where processError is in charge of whether a command is valid or not and prints it to the system. 

invalid movie type: This can be found in the borroworreturn class where processError is in charge of whether a  movie type is valid or not and prints it to the system. 

invalid customer ID: This can be found in the borroworreturn class where processError is in charge of whether a  customer ID is valid or not and prints it to the system. 
 
invalid movie: The borrow and return classes work to ensure that the movie is actually checked out by a customer. 

factory classes: 

hashtable: This can be found in the hashtable class where both the declarations and implmentations of a hashtable are. The hashtable is used to store values and their keys into an array type structure. 

container used for comedy movies: The BST class is used to store comedy movies

function for sorting comedy movies: This can be found in the comedy class, there are operator functions that sort comedy movies by title then the year it was released. 

function where comedy movies are sorted: This can be found in the comedy class, there are operator functions that sort comedy movies by title then the year it was released. 

functions called when retrieving a comedy movie based on title and year: setData retrives a comedy movie information and stores it into the system. 

functions called for retrieving and printing customer history: This can be found in the customer class where getHistories retrieves the history of the customer. 

container used for customer history: customer contains a vector that holds all customer history. 

functions called when borrowing a movie: This can be found in the borrow class where processBorrow checks the inventory and then processes the borrow command when it is made. 

explain borrowing a movie that does not exist: When a movie that does not exist is trying to be borrowed, the borrow class prints out a phrase stating that the media is not in the store database. 

explain borrowing a movie that has 0 stock: When a movie that does not exist is trying to be borrowed, the borrow class prints out a phrase stating that the movie has no stock. 

explain returning a movie that customer has not checked out: When a customer is trying to return a movie that they have not checked out the return class prints out a phrase stating that the customer does not have the movie. 

any static_cast or dynamic_cast used: Used in operation functions in classic, comedy, drama as well as process in command. 


Q: Total points: 22