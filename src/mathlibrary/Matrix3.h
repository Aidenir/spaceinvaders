//--- (C) 2013 Blankycan ---------------------------------------------------------------------------
// File:	Matrix3.h
// Author:	Blankycan
// Date:	2013-09-04
//--------------------------------------------------------------------------------------------------
#ifndef MATRIX3F_H
#define MATRIX3F_H
//--------------------------------------------------------------------------------------------------
#include <iostream>
#include <math.h>
//--------------------------------------------------------------------------------------------------
#include "MathLibrary.h"
//--------------------------------------------------------------------------------------------------

/** Matrix3f
	A 3 by 3 matrix holding T values.*/
template <class T>
class Matrix3{
public:
	// ----------------------------------------------------------
	// Constructors

	/** Matrix3()
		Default constructor, creates an identity matrix.*/
	Matrix3();
	/** Matrix3(T, T, T, T, T, T, T, T, T)
		Constructor that takes nine values that will fill the matrix row wise.*/
	Matrix3(	T n1, T n2, T n3,
				T n4, T n5, T n6,
				T n7, T n8, T n9);
	/** Matrix3(T[9])
		Constructor that takes a nine-long T array. It will be filled row wise.*/
	Matrix3(T mat[9]);
	/** Matrix3(Matrix3&)
		Constructor/Copy-constructor that takes another Matrix3 as parameter.
		It copies the parameter's values and uses them for it's own matrix.*/
	Matrix3(const Matrix3f& mat);
	Matrix3(const Matrix3d& mat);
	/** Matrix3(Matrix4f&)
		Constructor/Copy-constructor that takes another Matrix4f as parameter.
		It copies the parameter's values and uses them for it's own matrix.
		It skips the fourth row and column.*/
	Matrix3(const Matrix4<T>& mat);

	// ----------------------------------------------------------
	// Other Methods

	/** operator =(Matrix3&)
		A copy function that copies the parameters values to the new matrix's.
		Use: matrix = matrix
		Result: The matrix calling the function have the same values
				as the matrix passed with the function have.*/
	void operator =(const Matrix3<T>& mat);
	/** operator ==(Matrix3&)
		Method to check if two matrices have the same values.
		Use: matrix == matrix
		Result: Returns a boolean whether the two matrices are alike*/
	bool operator ==(const Matrix3<T>& mat);
	/** operator !=(Matrix3&)
		Method to check if two matrices don't have the same x,y,z,w values.
		Use: matrix != matrix
		Result: Returns a boolean whether the two matrices differs*/
	bool operator !=(const Matrix3<T>& mat);
	/** getContentRowWise(T*)
		Enters the matrix's values into the array row-wise.
		Precondition: Parameter 'arr' must be at least 9 indices long.
		Use: matrix.getContentRowWise(arr)
		Result: Array 'arr' is filled with the matrix's values row-wise.*/
	void getContentRowWise(T * arr);
	/** getContentColumnWise(T*)
		Enters the matrix's values into the array column-wise.
		Precondition: Parameter 'arr' must be at least 9 indices long.
		Use: matrix.getContentColumnWise(arr)
		Result: Array 'arr' is filled with the matrix's values column-wise.*/
	void getContentColumnWise(T * arr);
	/** operator ()(unsigned char, unsigned char) const
		A function to easily find what's in a specific position
		in the matrix.
		Precondition: x and y may never exceed 2.
		Use: matrix(x,y)
		Result: Returns T value in position x,y in matrix.
				If precondition isn't met suspect the unsuspected.*/
	T operator ()(unsigned char x, unsigned char y) const;
	/** operator ()(unsigned char, unsigned char)
		Function to make easy changes in the matrix.
		Precondition: x and y may never exceed 2.
					  Only put in T values.
		Use: matrix(x,y) = T
		Result: Inserts the T value into the matrix.
				If precondition isn't met suspect the unsuspected.*/
	T& operator ()(unsigned char x, unsigned char y);

	// ----------------------------------------------------------
	// Scalar Multiplication

	/** mult(T)
		Multiplies the matrix with the scalar.
		Use: matrix.mult(value)
		Result: Matrix is changed.*/
	void			mult		(T value);
	/** operator *= (T)
		Multiplies the matrix with the scalar.
		Use: matrix *= value
		Result: Matrix is changed.*/
	void			operator *=	(T value);
	/** mult(Matrix3&, T)
		Multiplies the matrix with the scalar.
		Use: Matrix3::mult(matrix, value);
		Result: New Matrix3 is returned.*/
	static Matrix3<T>	mult		(const Matrix3<T>& mat, T value);
	/** mult(T, Matrix3&)
		Multiplies the matrix with the scalar.
		Use: Matrix3::mult(value, matrix);
		Result: New Matrix3 is returned.*/
	static Matrix3<T>	mult		(T value, const Matrix3<T>& vec);
	/** operator * (T)
		Multiplies the matrix with the scalar.
		Use: matrix * value
		Result: New Matrix3 is returned.*/
	Matrix3<T>		operator *	(T value);
	/** friend operator * (Matrix3&)
		Multiplies the matrix with the scalar.
		Use: value * matrix
		Result: New Matrix3 is returned.*/
	//friend Matrix3<T>	operator *	(T value, const Matrix3<T>& vec);
	
	// ----------------------------------------------------------
	// Matrix Multiplication
	
	/** mult(Matrix3&)
		Multiplies the matrices.
		Use: matrix.mult(matrix)
		Result: Matrix calling the method is changed.*/
	void			mult		(const Matrix3<T>& mat);
	/** operator *=(Matrix3&)
		Multiplies the matrices.
		Use: matrix *= matrix
		Result: Matrix calling the method is changed.*/
	void			operator *=	(const Matrix3<T>& mat);
	/** mult(Matrix3&, Matrix3&)
		Multiplies the matrices.
		Use: mult(matrix, matrix)
		Result: A new Matrix3 is returned.*/
	static Matrix3<T>	mult		(const Matrix3<T>& mat1, const Matrix3<T>& mat2);
	/** operator *(Matrix3&)
		Multiplies the matrices.
		Use: matrix * matrix
		Result: A new Matrix3 is returned.*/
	Matrix3<T>		operator *	(const Matrix3<T>& mat);

	// ----------------------------------------------------------
	// Vector Multiplication
	
	/** mult(Matrix3<T>&, Vector3<T>&)
		Multiplies the matrix and the vector.
		Use: mult(matrix, vector)
		Result: A new Vector3<T> is returned.*/
	static Vector3<T>	mult		(const Matrix3<T>& mat, const Vector3<T>& vec);
	/** mult(Vector3<T>&)
		Multiplies the matrix and the vector.
		Use: matrix.mult(vector)
		Result: A new Vector3<T> is returned.*/
	Vector3<T>		mult		(const Vector3<T>& vec);
	/** operator *(Vector3<T>&)
		Multiplies the matrix and the vector.
		Use: matrix * vector
		Result: A new Vector3<T> is returned.*/
	Vector3<T>		operator *	(const Vector3<T>& vec);
    
	// ----------------------------------------------------------
	// Rotation
	
	/** initRotateX(T)
		Creates a x-rotation matrix. Uses radians.
		Use: matrix.initRotateX(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateX		(T rad);
	/** getRotateX(T)
		Returns a x-rotation matrix. Uses radians.
		Use: Matrix3::getRotateX(T)
		Result: Returns a rotation matrix.*/
	static Matrix3	getRotateX		(T rad);
	/** initRotateY(T)
		Creates a y-rotation matrix. Uses radians.
		Use: matrix.initRotateY(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateY		(T rad);
	/** getRotateY(T)
		Returns a y-rotation matrix. Uses radians.
		Use: Matrix3::getRotateY(T)
		Result: Returns a rotation matrix.*/
	static Matrix3	getRotateY		(T rad);
	/** initRotateZ(T)
		Creates a z-rotation matrix. Uses radians.
		Use: matrix.initRotateZ(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateZ		(T rad);
	/** getRotateZ(T)
		Returns a z-rotation matrix. Uses radians.
		Use: Matrix3::getRotateZ(T)
		Result: Returns a rotation matrix.*/
	static Matrix3	getRotateZ		(T rad);
	
	
	/** initRotateMatrix(T, T, T, T)
		Creates a vector rotation matrix. Uses radians.
		Use: matrix.initRotateMatrix(T, T, T, T)
		Result: Matrix becomes a vector rotation matrix.*/
	void			initRotateMatrix(T rad, T x, T y, T z);
	/** getRotateMatrix(T, T, T, T)
		Returns a vector rotation matrix. Uses radians.
		Use: Matrix3::getRotateMatrix(T, T, T, T)
		Result: Returns a vector rotation matrix*/
	static Matrix3<T>	getRotateMatrix(T rad, T x, T y, T z);

	// ----------------------------------------------------------
	// Transpose

	/** transpose()
		Transposes the matrix.
		Use: matrix.transpose()
		Result: Matrix using method gets transposed.*/
	void			transpose	();
	/** transposed()
		Transposes the matrix.
		Use: matrix.transposed()
		Result: A new transposed version of the matrix is returned.*/
	Matrix3<T>		transposed	();
	/** operator ~()
		Transposes the matrix.
		Use: ~matrix
		Result: A new transposed version of the matrix is returned.*/
	Matrix3<T>		operator ~	();

	// ----------------------------------------------------------
	// Inverse
	
	/** inverse()
		Change the current matrix to be it's inverse.
		Precondition: The determinant must not be zero.
		Use: matrix.inverse()
		Result: Inverses the matrix. If precondition isn't met
				an overflow_error will be thrown.*/
	void			inverse		();
	/** inverse(Matrix3&)
		Change the parameter matrix to be it's inverse.
		Precondition: The determinant must not be zero.
		Use: Matrix3::inverse(matrix)
		Result: Inverses the matrix. If precondition isn't met
				an overflow_error will be thrown.*/
	static void		inverse		(const Matrix3<T>& mat);
	/** inverse()
		Inverses the current matrix and returns it.
		Precondition: The determinant must not be zero.
		Use: matrix.inversed()
		Result: Returns a inversed version of the matrix.
				If precondition isn't met an overflow_error will be thrown.*/
	Matrix3<T>		inversed	();
	/** inverse()
		Inverses the parameter matrix and returns it.
		Precondition: The determinant must not be zero.
		Use: Matrix3::inversed(matrix)
		Result: Returns a inversed version of the matrix.
		If precondition isn't met an overflow_error will be thrown.*/
	static Matrix3<T>	inversed	(const Matrix3<T>& mat);


	// ----------------------------------------------------------
	// Variables
	
	/** coord[9]
		An array representing a matrix three rows and three columns.
		In Matrix3 the values are T type values.
		[0][3][6]
		[1][4][7]
		[2][5][8]*/
	T coord[9];
};

//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------

// ----------------------------------------------------------
// Constructors
template <class T>
Matrix3<T>::Matrix3(){
	coord[0] = 1; coord[3] = 0; coord[6] = 0;
	coord[1] = 0; coord[4] = 1; coord[7] = 0;
	coord[2] = 0; coord[5] = 0; coord[8] = 1;
}
template <class T>
Matrix3<T>::Matrix3(	T n1, T n2, T n3,
			T n4, T n5, T n6,
			T n7, T n8, T n9){
	coord[0] = n1; coord[3] = n2; coord[6] = n3;
	coord[1] = n4; coord[4] = n5; coord[7] = n6;
	coord[2] = n7; coord[5] = n8; coord[8] = n9;
}
template <class T>
Matrix3<T>::Matrix3(T mat[9]){
	coord[0] = mat[0]; coord[3] = mat[1]; coord[6] = mat[2];
	coord[1] = mat[3]; coord[4] = mat[4]; coord[7] = mat[5];
	coord[2] = mat[6]; coord[5] = mat[7]; coord[8] = mat[8];
}
template <class T>
Matrix3<T>::Matrix3(const Matrix3f& mat){
	coord[0] = (T)mat.coord[0]; coord[3] = (T)mat.coord[3]; coord[6] = (T)mat.coord[6];
	coord[1] = (T)mat.coord[1]; coord[4] = (T)mat.coord[4]; coord[7] = (T)mat.coord[7];
	coord[2] = (T)mat.coord[2]; coord[5] = (T)mat.coord[5]; coord[8] = (T)mat.coord[8];
}
template <class T>
Matrix3<T>::Matrix3(const Matrix3d& mat){
	coord[0] = (T)mat.coord[0]; coord[3] = (T)mat.coord[3]; coord[6] = (T)mat.coord[6];
	coord[1] = (T)mat.coord[1]; coord[4] = (T)mat.coord[4]; coord[7] = (T)mat.coord[7];
	coord[2] = (T)mat.coord[2]; coord[5] = (T)mat.coord[5]; coord[8] = (T)mat.coord[8];
}
template <class T>
Matrix3<T>::Matrix3(const Matrix4<T>& mat){
	coord[0] = (T)mat.coord[0]; coord[3] = (T)mat.coord[4]; coord[6] = (T)mat.coord[8];
	coord[1] = (T)mat.coord[1]; coord[4] = (T)mat.coord[5]; coord[7] = (T)mat.coord[9];
	coord[2] = (T)mat.coord[2]; coord[5] = (T)mat.coord[6]; coord[8] = (T)mat.coord[10];
}

// ----------------------------------------------------------
// Other Methods
template <class T>
void Matrix3<T>::operator =(const Matrix3& mat){
	for(int i = 0; i < 9; ++i)
		coord[i] = mat.coord[i];
}
template <class T>
bool Matrix3<T>::operator ==(const Matrix3& mat){
	bool result = true;
	for(int i = 0; i < 9; ++i){
		if(coord[i] != mat.coord[i]){
			result = false;
			break;
		}
	}
	return result;
}
template <class T>
bool Matrix3<T>::operator !=(const Matrix3& mat){
	char count = 0;
	for(int i = 0; i < 9; ++i){
		if(coord[i] == mat.coord[i]){
			++count;
		}
	}
	if(count == 9)
		return false;
	return true;
}

template <class T>
void Matrix3<T>::getContentRowWise(T * arr){
	arr[0] = coord[0]; arr[3] = coord[1]; arr[6] = coord[2];
	arr[1] = coord[3]; arr[4] = coord[4]; arr[7] = coord[5];
	arr[2] = coord[6]; arr[5] = coord[7]; arr[8] = coord[8];
}
template <class T>
void Matrix3<T>::getContentColumnWise(T * arr){
	for(int i = 0; i < 9; ++i){
		arr[i] = coord[i];
	}
}
template <class T>
T Matrix3<T>::operator ()(unsigned char x, unsigned char y) const{
	return coord[x*3+y];
}
template <class T>
T& Matrix3<T>::operator ()(unsigned char x, unsigned char y){
	return coord[x*3+y];
}

// ----------------------------------------------------------
// Scalar Multiplication

template <class T>
void Matrix3<T>::mult(T value){
	coord[0] *= value; coord[3] *= value; coord[6] *= value;
	coord[1] *= value; coord[4] *= value; coord[7] *= value;
	coord[2] *= value; coord[5] *= value; coord[8] *= value;
}
template <class T>
void Matrix3<T>::operator *=(T value){
	coord[0] *= value; coord[3] *= value; coord[6] *= value;
	coord[1] *= value; coord[4] *= value; coord[7] *= value;
	coord[2] *= value; coord[5] *= value; coord[8] *= value;
}
template <class T>
Matrix3<T> Matrix3<T>::mult(const Matrix3& mat, T value){
	Matrix3 matrix(mat.coord[0] * value, mat.coord[3] * value, mat.coord[6] * value,
					mat.coord[1] * value, mat.coord[4] * value, mat.coord[7] * value,
					mat.coord[2] * value, mat.coord[5] * value, mat.coord[8] * value);
    return matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::mult(T value, const Matrix3& mat){
	Matrix3 matrix(mat.coord[0] * value, mat.coord[3] * value, mat.coord[6] * value,
					mat.coord[1] * value, mat.coord[4] * value, mat.coord[7] * value,
					mat.coord[2] * value, mat.coord[5] * value, mat.coord[8] * value);
    return matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::operator *(T value){
	Matrix3 matrix(coord[0] * value, coord[3] * value, coord[6] * value,
					coord[1] * value, coord[4] * value, coord[7] * value,
					coord[2] * value, coord[5] * value, coord[8] * value);
    return matrix;
}
template <class T>
Matrix3<T> operator *(T value, const Matrix3<T>& mat){
	Matrix3<T> matrix(mat.coord[0] * value, mat.coord[3] * value, mat.coord[6] * value,
					mat.coord[1] * value, mat.coord[4] * value, mat.coord[7] * value,
					mat.coord[2] * value, mat.coord[5] * value, mat.coord[8] * value);
    return matrix;
}

// ----------------------------------------------------------
// Matrix Multiplication

template <class T>
void Matrix3<T>::mult(const Matrix3& mat){
	Matrix3 matrix(
		((coord[0] * mat.coord[0]) + (coord[3] * mat.coord[1]) + (coord[6] * mat.coord[2])),
		((coord[0] * mat.coord[3]) + (coord[3] * mat.coord[4]) + (coord[6] * mat.coord[5])),
		((coord[0] * mat.coord[6]) + (coord[3] * mat.coord[7]) + (coord[6] * mat.coord[8])),

		((coord[1] * mat.coord[0]) + (coord[4] * mat.coord[1]) + (coord[7] * mat.coord[2])),
		((coord[1] * mat.coord[3]) + (coord[4] * mat.coord[4]) + (coord[7] * mat.coord[5])),
		((coord[1] * mat.coord[6]) + (coord[4] * mat.coord[7]) + (coord[7] * mat.coord[8])),

		((coord[2] * mat.coord[0]) + (coord[5] * mat.coord[1]) + (coord[8] * mat.coord[2])),
		((coord[2] * mat.coord[3]) + (coord[5] * mat.coord[4]) + (coord[8] * mat.coord[5])),
		((coord[2] * mat.coord[6]) + (coord[5] * mat.coord[7]) + (coord[8] * mat.coord[8])));
    *this = matrix;
}
template <class T>
void Matrix3<T>::operator *=(const Matrix3& mat){
	Matrix3 matrix(
		((coord[0] * mat.coord[0]) + (coord[3] * mat.coord[1]) + (coord[6] * mat.coord[2])),
		((coord[0] * mat.coord[3]) + (coord[3] * mat.coord[4]) + (coord[6] * mat.coord[5])),
		((coord[0] * mat.coord[6]) + (coord[3] * mat.coord[7]) + (coord[6] * mat.coord[8])),

		((coord[1] * mat.coord[0]) + (coord[4] * mat.coord[1]) + (coord[7] * mat.coord[2])),
		((coord[1] * mat.coord[3]) + (coord[4] * mat.coord[4]) + (coord[7] * mat.coord[5])),
		((coord[1] * mat.coord[6]) + (coord[4] * mat.coord[7]) + (coord[7] * mat.coord[8])),

		((coord[2] * mat.coord[0]) + (coord[5] * mat.coord[1]) + (coord[8] * mat.coord[2])),
		((coord[2] * mat.coord[3]) + (coord[5] * mat.coord[4]) + (coord[8] * mat.coord[5])),
		((coord[2] * mat.coord[6]) + (coord[5] * mat.coord[7]) + (coord[8] * mat.coord[8])));
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::mult(const Matrix3& mat1, const Matrix3& mat2){
	Matrix3 matrix(
		((mat1.coord[0] * mat2.coord[0]) + (mat1.coord[3] * mat2.coord[1]) + (mat1.coord[6] * mat2.coord[2])),
		((mat1.coord[0] * mat2.coord[3]) + (mat1.coord[3] * mat2.coord[4]) + (mat1.coord[6] * mat2.coord[5])),
		((mat1.coord[0] * mat2.coord[6]) + (mat1.coord[3] * mat2.coord[7]) + (mat1.coord[6] * mat2.coord[8])),

		((mat1.coord[1] * mat2.coord[0]) + (mat1.coord[4] * mat2.coord[1]) + (mat1.coord[7] * mat2.coord[2])),
		((mat1.coord[1] * mat2.coord[3]) + (mat1.coord[4] * mat2.coord[4]) + (mat1.coord[7] * mat2.coord[5])),
		((mat1.coord[1] * mat2.coord[6]) + (mat1.coord[4] * mat2.coord[7]) + (mat1.coord[7] * mat2.coord[8])),

		((mat1.coord[2] * mat2.coord[0]) + (mat1.coord[5] * mat2.coord[1]) + (mat1.coord[8] * mat2.coord[2])),
		((mat1.coord[2] * mat2.coord[3]) + (mat1.coord[5] * mat2.coord[4]) + (mat1.coord[8] * mat2.coord[5])),
		((mat1.coord[2] * mat2.coord[6]) + (mat1.coord[5] * mat2.coord[7]) + (mat1.coord[8] * mat2.coord[8])));
    return matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::operator *(const Matrix3& mat){
	Matrix3 matrix(
		((coord[0] * mat.coord[0]) + (coord[3] * mat.coord[1]) + (coord[6] * mat.coord[2])),
		((coord[0] * mat.coord[3]) + (coord[3] * mat.coord[4]) + (coord[6] * mat.coord[5])),
		((coord[0] * mat.coord[6]) + (coord[3] * mat.coord[7]) + (coord[6] * mat.coord[8])),

		((coord[1] * mat.coord[0]) + (coord[4] * mat.coord[1]) + (coord[7] * mat.coord[2])),
		((coord[1] * mat.coord[3]) + (coord[4] * mat.coord[4]) + (coord[7] * mat.coord[5])),
		((coord[1] * mat.coord[6]) + (coord[4] * mat.coord[7]) + (coord[7] * mat.coord[8])),

		((coord[2] * mat.coord[0]) + (coord[5] * mat.coord[1]) + (coord[8] * mat.coord[2])),
		((coord[2] * mat.coord[3]) + (coord[5] * mat.coord[4]) + (coord[8] * mat.coord[5])),
		((coord[2] * mat.coord[6]) + (coord[5] * mat.coord[7]) + (coord[8] * mat.coord[8])));
    return matrix;
}

// ----------------------------------------------------------
// Vector Multiplication

template <class T>
Vector3<T> Matrix3<T>::mult(const Matrix3& mat, const Vector3<T>& vec){
	Vector3<T> vector(
		((mat.coord[0] * vec.coord[0]) + (mat.coord[3] * vec.coord[1]) + (mat.coord[6] * vec.coord[2])),
		((mat.coord[1] * vec.coord[0]) + (mat.coord[4] * vec.coord[1]) + (mat.coord[7] * vec.coord[2])),
		((mat.coord[2] * vec.coord[0]) + (mat.coord[5] * vec.coord[1]) + (mat.coord[8] * vec.coord[2])));
    return vector;
}
template <class T>
Vector3<T> Matrix3<T>::mult(const Vector3<T>& vec){
	Vector3<T> vector(
		((coord[0] * vec.coord[0]) + (coord[3] * vec.coord[1]) + (coord[6] * vec.coord[2])),
		((coord[1] * vec.coord[0]) + (coord[4] * vec.coord[1]) + (coord[7] * vec.coord[2])),
		((coord[2] * vec.coord[0]) + (coord[5] * vec.coord[1]) + (coord[8] * vec.coord[2])));
    return vector;
}
template <class T>
Vector3<T> Matrix3<T>::operator *(const Vector3<T>& vec){
	Vector3<T> vector(
		((coord[0] * vec.coord[0]) + (coord[3] * vec.coord[1]) + (coord[6] * vec.coord[2])),
		((coord[1] * vec.coord[0]) + (coord[4] * vec.coord[1]) + (coord[7] * vec.coord[2])),
		((coord[2] * vec.coord[0]) + (coord[5] * vec.coord[1]) + (coord[8] * vec.coord[2])));
    return vector;
}

// ----------------------------------------------------------
// Rotation

// X
template <class T>
void Matrix3<T>::initRotateX(T rad){
	Matrix3 matrix(
		1			, 0			, 0			,
		0			, cos(rad)	, -sin(rad)	,
		0			, sin(rad)	, cos(rad)	);
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::getRotateX(T rad){
	Matrix3 matrix(
		1			, 0			, 0			,
		0			, cos(rad)	, -sin(rad)	,
		0			, sin(rad)	, cos(rad)	);
    return matrix;
}
// Y
template <class T>
void Matrix3<T>::initRotateY(T rad){
	Matrix3 matrix(
		cos(rad)	, 0			, sin(rad)	,
		0			, 1			, 0			,
		-sin(rad)	, 0			, cos(rad)	);
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::getRotateY(T rad){
	Matrix3 matrix(
		cos(rad)	, 0			, sin(rad)	,
		0			, 1			, 0			,
		-sin(rad)	, 0			, cos(rad)	);
    return matrix;
}
// Z
template <class T>
void Matrix3<T>::initRotateZ(T rad){
	Matrix3 matrix(
		cos(rad)	, -sin(rad)	, 0			,
		sin(rad)	, cos(rad)	, 0			,
		0			, 0			, 1			);
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::getRotateZ(T rad){
	Matrix3 matrix(
		cos(rad)	, -sin(rad)	, 0			,
		sin(rad)	, cos(rad)	, 0			,
		0			, 0			, 1			);
    return matrix;
}
// All
template <class T>
void Matrix3<T>::initRotateMatrix(T rad, T x, T y, T z){
	T c = cos(rad);
	T s = sin(rad);

	Vector3<T> vec(x,y,z);
	vec.normalize();

	x = vec.coord[X];
	y = vec.coord[Y];
	z = vec.coord[Z];

	Matrix3 matrix(
		x*x*(1-c)+c		, x*y*(1-c)-z*s	, x*z*(1-c)+y*s	,
		y*x*(1-c)+z*s	, y*y*(1-c)+c	, y*z*(1-c)-x*s	,
		x*z*(1-c)-y*s	, y*z*(1-c)+x*s	, z*z*(1-c)+c	);
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::getRotateMatrix(T rad, T x, T y, T z){
	T c = cos(rad);
	T s = sin(rad);

	Vector3<T> vec(x,y,z);
	vec.normalize();

	x = vec.coord[X];
	y = vec.coord[Y];
	z = vec.coord[Z];

	Matrix3 matrix(
		x*x*(1-c)+c		, x*y*(1-c)-z*s	, x*z*(1-c)+y*s	,
		y*x*(1-c)+z*s	, y*y*(1-c)+c	, y*z*(1-c)-x*s	,
		x*z*(1-c)-y*s	, y*z*(1-c)+x*s	, z*z*(1-c)+c	);
    return matrix;
}

// ----------------------------------------------------------
// Transpose

template <class T>
void Matrix3<T>::transpose(){
	Matrix3 matrix(
		coord[0], coord[1], coord[2],
		coord[3], coord[4], coord[5],
		coord[6], coord[7], coord[8]);
    *this = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::transposed(){
	Matrix3 matrix(
		coord[0], coord[1], coord[2],
		coord[3], coord[4], coord[5],
		coord[6], coord[7], coord[8]);
    return matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::operator ~(){
	Matrix3 matrix(
		coord[0], coord[1], coord[2],
		coord[3], coord[4], coord[5],
		coord[6], coord[7], coord[8]);
    return matrix;
}

// ----------------------------------------------------------
// Inverse

template <class T>
void Matrix3<T>::inverse(){
	T detA =	 coord[0]*((coord[4] * coord[8]) - (coord[7] * coord[5]))
					-coord[3]*((coord[8] * coord[1]) - (coord[7] * coord[2]))
					+coord[6]*((coord[1] * coord[5]) - (coord[4] * coord[2]));
	if(detA == 0.0f)
		return;
	Matrix3 matrix(
		(coord[4]*coord[8] - coord[7]*coord[5]), //A
		(coord[6]*coord[5] - coord[3]*coord[8]), //D
		(coord[3]*coord[7] - coord[6]*coord[4]), //G

		(coord[7]*coord[2] - coord[1]*coord[8]), //B
		(coord[0]*coord[8] - coord[6]*coord[2]), //E
		(coord[6]*coord[1] - coord[0]*coord[7]), //H

		(coord[1]*coord[5] - coord[4]*coord[2]), //C
		(coord[2]*coord[3] - coord[0]*coord[5]), //F
		(coord[0]*coord[4] - coord[3]*coord[1]));//K
    matrix *= (1.0f / detA);
    *this = matrix;
}

template <class T>
void Matrix3<T>::inverse(const Matrix3& mat){
	T detA =	 mat.coord[0]*((mat.coord[4] * mat.coord[8]) - (mat.coord[7] * mat.coord[5]))
		-mat.coord[3]*((mat.coord[8] * mat.coord[1]) - (mat.coord[7] * mat.coord[2]))
		+mat.coord[6]*((mat.coord[1] * mat.coord[5]) - (mat.coord[4] * mat.coord[2]));
	if(detA == 0.0f)
		return;
	Matrix3 matrix(
		(mat.coord[4]*mat.coord[8] - mat.coord[7]*mat.coord[5]), //A
		(mat.coord[6]*mat.coord[5] - mat.coord[3]*mat.coord[8]), //D
		(mat.coord[3]*mat.coord[7] - mat.coord[6]*mat.coord[4]), //G

		(mat.coord[7]*mat.coord[2] - mat.coord[1]*mat.coord[8]), //B
		(mat.coord[0]*mat.coord[8] - mat.coord[6]*mat.coord[2]), //E
		(mat.coord[6]*mat.coord[1] - mat.coord[0]*mat.coord[7]), //H

		(mat.coord[1]*mat.coord[5] - mat.coord[4]*mat.coord[2]), //C
		(mat.coord[2]*mat.coord[3] - mat.coord[0]*mat.coord[5]), //F
		(mat.coord[0]*mat.coord[4] - mat.coord[3]*mat.coord[1]));//K
    matrix *= (1.0f / detA);
    mat = matrix;
}
template <class T>
Matrix3<T> Matrix3<T>::inversed(){
	T detA =	 coord[0]*((coord[4] * coord[8]) - (coord[7] * coord[5]))
		-coord[3]*((coord[8] * coord[1]) - (coord[7] * coord[2]))
		+coord[6]*((coord[1] * coord[5]) - (coord[4] * coord[2]));
	if(detA == 0.0f){
		Matrix3 matrix;
        return matrix;
    }
	Matrix3 matrix(
		(coord[4]*coord[8] - coord[7]*coord[5]), //A
		(coord[6]*coord[5] - coord[3]*coord[8]), //D
		(coord[3]*coord[7] - coord[6]*coord[4]), //G

		(coord[7]*coord[2] - coord[1]*coord[8]), //B
		(coord[0]*coord[8] - coord[6]*coord[2]), //E
		(coord[6]*coord[1] - coord[0]*coord[7]), //H

		(coord[1]*coord[5] - coord[4]*coord[2]), //C
		(coord[2]*coord[3] - coord[0]*coord[5]), //F
		(coord[0]*coord[4] - coord[3]*coord[1]));//K
    matrix *= (1.0f / detA);
    return matrix;
}

template <class T>
Matrix3<T> Matrix3<T>::inversed(const Matrix3& mat){
	T detA =	 mat.coord[0]*((mat.coord[4] * mat.coord[8]) - (mat.coord[7] * mat.coord[5]))
		-mat.coord[3]*((mat.coord[8] * mat.coord[1]) - (mat.coord[7] * mat.coord[2]))
		+mat.coord[6]*((mat.coord[1] * mat.coord[5]) - (mat.coord[4] * mat.coord[2]));
	if(detA == 0.0f){
		Matrix3 matrix;
        return matrix;
    }
	Matrix3 matrix(
		(mat.coord[4]*mat.coord[8] - mat.coord[7]*mat.coord[5]), //A
		(mat.coord[6]*mat.coord[5] - mat.coord[3]*mat.coord[8]), //D
		(mat.coord[3]*mat.coord[7] - mat.coord[6]*mat.coord[4]), //G

		(mat.coord[7]*mat.coord[2] - mat.coord[1]*mat.coord[8]), //B
		(mat.coord[0]*mat.coord[8] - mat.coord[6]*mat.coord[2]), //E
		(mat.coord[6]*mat.coord[1] - mat.coord[0]*mat.coord[7]), //H

		(mat.coord[1]*mat.coord[5] - mat.coord[4]*mat.coord[2]), //C
		(mat.coord[2]*mat.coord[3] - mat.coord[0]*mat.coord[5]), //F
		(mat.coord[0]*mat.coord[4] - mat.coord[3]*mat.coord[1]));//K
    matrix *= (1.0f / detA);
    return matrix;
}

#endif