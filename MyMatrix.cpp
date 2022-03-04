#include "MyMatrix.h"

// friend functions
MyMatrix operator*(double scalar, const MyMatrix& matrix) {
	// multiply matrix with scalar from the left - scalar*matrix
	MyMatrix m(matrix.getM(), matrix.getN());
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {
			m.getMatrix()[i][j] = matrix.getMatrix()[i][j] * scalar;
		}
	}
	return m;
}

ostream& operator<<(ostream& out, const MyMatrix& matrix) {
	// print out to the computer the matrix class - the size and the matrix's values
	out << "The size of the matrix is: " << endl << matrix.getM() << "*" << matrix.getN() << endl;
	out << "The matrix is:" << endl;
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {
			out << matrix.getMatrix()[i][j] << " ";
		}
		out << endl;
	}
	out << endl;
	return out;
}

istream& operator>>(istream& in, MyMatrix& matrix) {
	// get the matrix's valuse from the user

	// get size
	int m, n;

	cout << "Enter the rows number: ";
	in >> m;
	if (in.fail() or m <= 0) {
		in.clear();
		throw "Not a valid input.";
	}

	cout << "Enter the columns number: ";
	in >> n;
	if (in.fail() or n <= 0) {
		in.clear();
		throw "Not a valid input.";
	}

	// get matrix's values - create temp matrix to save the data in - new pointer to ref, for the new matrix
	double** temp = new double* [m];
	for (int i = 0; i < m; i++) {
		temp[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "Enter the value in place (" << i << ", " << j << "): ";
			in >> temp[i][j];
			if (in.fail()) {
				in.clear();
				throw "Not a valid input.";
			}
		}
	}

	// put in the matrix
	matrix.clear();
	matrix.setMatrix(temp);
	matrix.setM(m);
	matrix.setN(n);
	return in;
}

// class methods
void MyMatrix::clear() {
	// delete the current matrix
	if (this->_matrix) {
		// if not null, delete the current matrix
		for (int i = 0; i < this->getM(); i++) {
			if (this->_matrix[i]) {
				delete[] this->_matrix[i];
			}
		}
		delete[] this->_matrix;
	}
}

double* MyMatrix::operator[](int i) const {
	// get the i_th line of the matrix
	if (i >= this->getM())
		throw "Index out of range.";
	return this->getMatrix()[i];
}

MyMatrix MyMatrix::operator+(const MyMatrix& other) const {
	// add two matrices
	if ((other.getM() != this->getM() || (other.getN() != this->getN())))  // not same size
		throw "Invalid sizes, cannot sum.";

	// add them
	MyMatrix m(this->getM(), this->getN());
	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < this->getN(); j++)
			m[i][j] = this->getMatrix()[i][j] + other.getMatrix()[i][j];
	}
	return m;
}

MyMatrix MyMatrix::operator-(const MyMatrix& other) const {
	// substruct two matrices
	if ((other.getM() != this->getM() || (other.getN() != this->getN())))  // not same size
		throw "Invalid sizes, cannot subtruct.";


	// sub them
	MyMatrix m(this->getM(), this->getN());
	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < this->getN(); j++)
			m[i][j] = this->getMatrix()[i][j] - other.getMatrix()[i][j];
	}
	return m;
}

MyMatrix MyMatrix::operator*(double scalar) const {
	// multiply matrix with scalar from the right - matrix*scalar
	MyMatrix m(this->getM(), this->getN());
	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < this->getN(); j++) {
			m.getMatrix()[i][j] = this->getMatrix()[i][j] * scalar;
		}
	}
	return m;
}

MyMatrix MyMatrix::operator*(const MyMatrix& other) const {
	// multiply two matrices
	if (this->getN() != other.getM())
		throw "Not valid sizes, cannot multiply.";

	// create new matrix for result of the multiplication
	MyMatrix mul_res(this->getM(), other.getN());

	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < other.getN(); j++) {
			for (int k = 0; k < this->getN(); k++) {
				mul_res[i][j] += this->getMatrix()[i][k] * other.getMatrix()[k][j];
			}
		}
	}
	return mul_res;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other) {
	// copy data from other (param of the function) to our matrix - assaign.

	// copy the data
	int m = other.getM();
	int n = other.getN();

	// create temp matrix to save the data in - new pointer to ref, for the new matrix
	double** matrix = new double* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = other.getMatrix()[i][j];
		}
	}


	// set the new matrix
	this->clear();
	this->setMatrix(matrix);
	this->setM(m);
	this->setN(n);
	return *this;
}

bool MyMatrix::operator==(const MyMatrix& other) const {
	// decide whether two matrices are the same or not
	if ((this->getM() != other.getM()) || (this->getN() != other.getN()))
		return false;  //not the same size

	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < this->getN(); j++) {
			if (this->getMatrix()[i][j] != other.getMatrix()[i][j])
				return false;
		}
	}
	return true;
}

MyMatrix::operator double() const {
	// return the sum of the matrix values
	double sum = 0;
	for (int i = 0; i < this->getM(); i++) {
		for (int j = 0; j < this->getN(); j++)
			sum += this->getMatrix()[i][j];
	}
	return sum;
}

MyMatrix::MyMatrix(const MyMatrix& other) {
	// copy constractor
	int m = other.getM();
	int n = other.getN();

	// set size
	this->setM(m);
	this->setN(n);

	// initilize the matrix - new pointer to ref, for the new matrix
	double** matrix = new double* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = other.getMatrix()[i][j];
		}
	}
	this->setMatrix(matrix);
}

MyMatrix::MyMatrix(int m, int n) {
	// constarctor - builds m*n matrix and fills it with zeros
	if (m <= 0 or n <= 0)
		throw "Not valid sizes.";
	// set size
	this->setM(m);
	this->setN(n);

	// initilize the matrix - new pointer to ref, for the new matrix
	double** matrix = new double* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new double[n];
	}

	// fill with zeros
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}

	// put in our matrix
	this->setMatrix(matrix);
}

MyMatrix::MyMatrix() : MyMatrix(3, 3) {
	// default constractor - builds 3*3 matrix and fills it with zeros
}

MyMatrix::~MyMatrix() {
	// destructor - delete the matrix
	this->clear();
}