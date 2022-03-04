#pragma once
#include <iostream>

using namespace std;

class MyMatrix {
private:
	double** _matrix;
	int _m;
	int _n;

	// setters
	void setM(int m) { this->_m = m; }
	void setN(int n) { this->_n = n; }
	void setMatrix(double** matrix) { this->_matrix = matrix; }

	// delete matrix
	void clear();

public:
	// constractors and destructor
	MyMatrix(const MyMatrix& other);
	MyMatrix(int m, int n);
	MyMatrix();
	~MyMatrix();
	
	// getters
	int getM() const { return _m; }
	int getN() const { return _n; }
	double** getMatrix() const { return _matrix; }

	// operators
	MyMatrix operator+(const MyMatrix& other) const;
	MyMatrix operator-(const MyMatrix& other) const;
	MyMatrix operator*(const MyMatrix& other) const;
	MyMatrix operator*(double scalar) const;  // mul from right
	MyMatrix& operator=(const MyMatrix& other);
	bool operator==(const MyMatrix& other) const;
	double* operator[](int i) const;
	operator double() const;

	// friends
	friend MyMatrix operator*(double scalar, const MyMatrix& matrix);  // mul from left
	friend ostream& operator<<(ostream& out, const MyMatrix& matrix);
	friend istream& operator>>(istream& out, MyMatrix& matrix);
};