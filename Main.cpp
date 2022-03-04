#include "MyMatrix.h"
#include <string>

/*int main() {
	// initilizing matrices
	MyMatrix matrix1;  // 3*3
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix1[i][j] = 3;
		}
	}
	cout << "Here is matrix1:" << endl;
	cout << matrix1;
	MyMatrix matrix2(1, 3);
	cout << "Enter matrix2 data:" << endl;
	try {
		cin >> matrix2;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}
	cout << "Here is matrix2:" << endl;
	cout << matrix2;
	MyMatrix matrix3(matrix1);
	cout << "Here is matrix3 (copy of matrix1):" << endl;
	cout << matrix3;

	// operators
	MyMatrix sum;
	try {
		cout << "Trying to add matrix1 and matrix3..." << endl;
		sum = matrix1 + matrix3;
		cout << "Here is the sum result:" << endl;
		cout << sum;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}

	MyMatrix sub;
	try {
		cout << "Trying to sub matrix1 and matrix2..." << endl;
		sub = matrix1 - matrix2;
		cout << "Here is the sub result:" << endl;
		cout << sub;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}

	MyMatrix mul;
	try {
		cout << "Trying to multiply matrix1 and matrix2..." << endl;
		mul = matrix1 * matrix2;
		cout << "Here is the muliply result:" << endl;
		cout << mul;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}
	try {
		cout << "Trying to multiply like this: matrix2*(matrix1*matrix3)..." << endl;
		mul = matrix2 * (matrix1 * matrix3);
		cout << "Here is the muliply result:" << endl;
		cout << mul;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}

	cout << "Here is matrix2 multiply by 3 from the left (3*matrix2):" << endl;
	matrix2 = 3.0 * matrix2;
	cout << matrix2;
	cout << "Now let's multiply it again by 3, but from the right (matrix2*3):" << endl;
	matrix2 = matrix2 * 3.0;
	cout << matrix2;

	cout << "Assigning matrix2 to matrix3..." << endl;
	matrix3 = matrix2;
	cout << "Here is matrix3:" << endl;
	cout << matrix3;

	cout << "Let's check if matrix2 and matrix3 are equal:" << endl;
	if (matrix2 == matrix3)
		cout << "Yes, they are!" << endl;
	else
		cout << "No, they are not!" << endl;
	cout << endl;

	cout << "Let's get the value in place (3, 2) in matrix1:" << endl;
	try {
		cout << "The value in place (3, 2) is: " << matrix1[3][2] << endl << endl;
	}
	catch (const char* e) {
		cout << e << endl << endl;
	}

	cout << "And finally, let's cast matrix1 to double:" << endl;
	double matrix_cast = (double)matrix1;
	cout << "The result of the casting is: " << matrix_cast << endl;

	return 0; // here it calls to all the destructors
}*/

bool isNumber(string input) {
	/* 
	check if a string is a number 
	get a string and returns boolean expression 
	*/
	for (int i = 0; i < input.length(); i++)
		if (isdigit(input[i]) == false)  // one char is not digit
			return false;
	return true;
}

void assignMatrix(MyMatrix my_matrix) {
	/*
	* handle the assign matrix action
	* get and return None
	*/
	cout << "Enter the new matrix:" << endl;
	MyMatrix matrix;
	cin >> matrix;
	my_matrix = matrix;
	cout << "Successfully assigned the matrix! Here it is:" << endl;
	cout << my_matrix;
}

void operateTwoMatrices(MyMatrix my_matrix, char op) {
	/*
	* handle the operations of 2 matrices
	* get the user's matrix and the operation and return None
	*/
	// vars
	bool done = false;
	string input;
	MyMatrix matrix1, matrix2;

	// get matrix(ces)
	while (!done) {
		cout << "Do you want to use your matrix? (Y/N):" << endl;
		cin >> input;
		if (input == "Y" || input == "y") {
			done = true;
			matrix1 = my_matrix;
			cout << "Ok. You need to enter only one matrix." << endl;
			cout << "Enter the matrix:" << endl;
			cin >> matrix2;
			cout << "\nSuccessfully entered the matrix! Here it is:" << endl;
			cout << matrix2;
		}
		else if (input == "N" || input == "n") {
			done = true;
			cout << "Ok. You need to enter 2 matrices." << endl;
			cout << "Enter the first:" << endl;
			cin >> matrix1;
			cout << "\nSuccessfully entered the matrix! Here it is:" << endl;
			cout << matrix1;
			cout << "Now enter the second:" << endl;
			cin >> matrix2;
			cout << "\nSuccessfully entered the matrix! Here it is:" << endl;
			cout << matrix2;
		}
		else {
			cout << "Invalid." << endl;
		}
	}

	// calc result
	MyMatrix output_matrix;
	if (op == '+') {  // sum
		try {
			output_matrix = matrix1 + matrix2;
			cout << "\nSuccessfully added the matrices! Here is the sum result:" << endl;
			cout << output_matrix;
			return;
		}
		catch (const char* error) {  // diffrent sizes
			cout << error << endl;
			return;
		}
	}
	if (op == '-') {  // sub
		try {
			output_matrix = matrix1 - matrix2;
			cout << "\nSuccessfully added the matrices! Here is the subtruction result:" << endl;
			cout << output_matrix;
		}
		catch (const char* error) {  // diffrent sizes
			cout << error << endl;
		}
	}
	if (op == '*') {  // mul
		try {
			output_matrix = matrix1 * matrix2;
			cout << "\nSuccessfully added the matrices! Here is the multiplication result:" << endl;
			cout << output_matrix;
		}
		catch (const char* error) {  // invalid sizes
			cout << error << endl;
		}
	}	
}

void scalarMul(MyMatrix my_matrix) {
	/*
	* handle the multipication by scalar (left and right)
	* get the matrix and scalar and return None
	*/
}

int main() {
	bool done = false;
	// initilize
	cout << "Welcome to matrix handler!" << endl;
	cout << "Fisrt you need to enter your matrix:" << endl;
	MyMatrix matrix;
	cin >> matrix;
	cout << "\nSuccessfully entered the matrix! Here it is:" << endl;
	cout << matrix;
	cout << "Now let's start!" << endl;
	
	// build intructions
	string intructions;
	intructions += "\nChoose want you want to do:\n";
	intructions += "1 - assign the matrix (change values of a matrix)\n";
	intructions += "2 - add 2 matrices\n";
	intructions += "3 - subtruct 2 matrices\n";
	intructions += "4 - multiply 2 matrices\n";
	intructions += "5 - multiply by scalar from the left\n";
	intructions += "6 - multiply by scalar from the right\n";
	intructions += "7 - compare 2 matrices\n";
	intructions += "8 - return value in specific location of your matrix\n";
	intructions += "9 - cast to double (returns the sum of the values in the matrix)\n";
	intructions += "10 - present the matrix\n";
	intructions += "Press the number of the action you want to take or press q to leave (press enter in the end):";
	
	// start
	while (!done) {
		// get input
		string action;
		cout << intructions << endl;
		cin >> action;
		// check if valid
		if (!isNumber(action)) {  // not a number
			if (action == "q") {  // want to leave
				cout << "Bye! See you next time!" << endl;
				done = true;
			}
			else
				cout << "Invalid." << endl;
		}
		else {  // number
			int action_num = stoi(action);
			switch (action_num) {
			case 1:  // assign
				assignMatrix(matrix);
				break;
			case 2:  // add
				operateTwoMatrices(matrix, '+');
				break;
			case 3:  // sub
				operateTwoMatrices(matrix, '-');
				break;
			case 4: // mul mat
				operateTwoMatrices(matrix, '*');
				break;
			case 5: // mul scal left
				break;
			case 6:  // mul scal right
				break;
			case 7:  // comp
				break;
			case 8:  // index
				break;
			case 9:  // cast
				break;
			case 10:  // print
				break;
			default:  // not valid number
				cout << "Invalid." << endl;
			}
		}
	}
}