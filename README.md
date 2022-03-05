# MatrixHandler
## Summary
Program for handling matrix operations - 
1. Assign matrix (change values of the matrix, also its size).
2. Add two matrices.
3. Subtract two matrices.
4. Multiply two matrices.
5. Multiply by a scalar from left and from the right.
6. Compare two matrices.
7. Get an index from a matrix.
8. Cast to double (get the sum of the values in the matrix).  

The program supports taking matrix as input with ```std::cin``` and printing matrix with ```std::cout```.  
The program uses the ideas of OOP, operator overloading, and friend functions to enable the use of the operators from the right.

## MyMatrix.h
The deleration of the class - MyMatrix and each methods in the class, and the friend functions.
### MyMarix class
The class MyMatrix is handling all the matrix operators.
#### Members of the class (private)
1. the matrix (double**)
2. number of rows (int)
3. number of columns (int) 

#### Private methods
1. setters.
2. delete matrix.

#### Public methods
1. Constarctors (regular, copy and defualt).
2. Destructor.
3. getters.
4. operators (+, -, *, =, ==, [], double())

#### Friend functions
1. operator * - multiply by scalar from the right.
2. operator << - cout.
3. operator >> - cin.

## MyMatrix.cpp
The code of the methods and friend functions of MyMatrix class.

## Main.cpp
The UI - handles the user - 
1. Take input of the user's matrix, and create an object of Myatrix for the user.
2. Present instructions.
3. Take input for desired action.
4. Call the method for each action (from the user's object).

Do 2, 3 and 4 in a loop until the user press q - means they want to leave.

