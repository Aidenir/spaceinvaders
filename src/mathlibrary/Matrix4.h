//--- (C) 2013 Blankycan ---------------------------------------------------------------------------
// File:	Matrix4.h
// Author:	Blankycan
// Date:	2013-09-04
//--------------------------------------------------------------------------------------------------
#ifndef MATRIX4F_H
#define MATRIX4F_H
//--------------------------------------------------------------------------------------------------
#include "MathLibrary.h"
//--------------------------------------------------------------------------------------------------

/** Matrix4
	A 4 by 4 matrix holding holding T values.
	It can perform various operation such as blowing your mind
 */
template <class T>
class Matrix4{
public:
	// ----------------------------------------------------------
	// Constructors

	/** Matrix4()
		Default constructor, creates an identity matrix.*/
	Matrix4();
	/** Matrix4(16 x T)
		Constructor that takes 16 values that will fill the matrix row wise.*/
	Matrix4(	T n1, T n2, T n3, T n4,
				T n5, T n6, T n7, T n8,
				T n9, T n10, T n11, T n12,
				T n13, T n14, T n15, T n16);
	/** Matrix4(T[16])
		Constructor that takes a 16-long T array. It will be filled row wise.*/
	Matrix4(T mat[16]);
	/** Matrix4(Matrix3f&)
		Constructor/Copy-constructor that takes another Matrix3f as parameter.
		It copies the parameter's values and uses them for it's own matrix.
		Fills the matrix fourth row/column with zeros.*/
	Matrix4(const Matrix3<T>& mat);
	/** Matrix4(Matrix4&)
		Constructor/Copy-constructor that takes another Matrix4 as parameter.
		It copies the parameter's values and uses them for it's own matrix.*/
	Matrix4(const Matrix4f& mat);
	Matrix4(const Matrix4d& mat);

	// ----------------------------------------------------------
	// Other Methods

	/** operator =(Matrix4&)
		A copy function that copies the parameters values to the new matrix's.
		Use: matrix = matrix
		Result: The matrix calling the function have the same values
				as the matrix passed with the function have.*/
	void			operator =	(const Matrix4<T>& mat);
	/** operator ==(Matrix4&)
		Method to check if two matrices have the same values.
		Use: matrix == matrix
		Result: Returns a boolean whether the two matrices are alike*/
	bool			operator ==	(const Matrix4<T>& mat) const;
	/** operator !=(Matrix4&)
		Method to check if two matrices don't have the same x,y,z,w values.
		Use: matrix != matrix
		Result: Returns a boolean whether the two matrices differs*/
	bool			operator !=	(const Matrix4<T>& mat) const;
	/** getContentRowWise(T*)
		Enters the matrix's values into the array row-wise.
		Precondition: Parameter 'arr' must be at least 16 indices long.
		Use: matrix.getContentRowWise(arr)
		Result: Array 'arr' is filled with the matrix's values row-wise.*/
	void			getContentRowWise(T * arr);
	/** getContentRowWise()
		Enters the matrix's values into a array row-wise.
		Postcondition: Must be deleted because it was dynamic allocated.
		Use: matrix.getContentRowWise()
		Result: Returns a T pointer filled with the matrix's values row-wise.*/
	T*			getContentRowWise();
	/** getContentColumnWise(T*)
		Enters the matrix's values into the array column-wise.
		Precondition: Parameter 'arr' must be at least 16 indices long.
		Use: matrix.getContentColumnWise(arr)
		Result: Array 'arr' is filled with the matrix's values column-wise.*/
	void			getContentColumnWise(T * arr);
	/** getContentColumnWise()
		Enters the matrix's values into a array column-wise.
		Use: matrix.getContentColumnWise()
		Result: Returns a T pointer filled with the matrix's values column-wise.*/
	T*			getContentColumnWise();
	/** operator ()(unsigned char, unsigned char) const
		A function to easily find what's in a specific position
		in the matrix.
		Precondition: x and y may never exceed 4.
		Use: matrix(x,y)
		Result: Returns T value in position x,y in matrix.
				If precondition isn't met suspect the unsuspected.*/
	T			operator ()	(unsigned char x, unsigned char y) const;
	/** operator ()(unsigned char, unsigned char)
		Function to make easy changes in the matrix.
		Precondition: x and y may never exceed 4.
					  Only put in T values.
		Use: matrix(x,y) = T
		Result: Inserts the T value into the matrix.
				If precondition isn't met suspect the unsuspected.*/
	T&			operator ()	(unsigned char x, unsigned char y);
	T			operator [](unsigned char n) const;
	T&			operator [](unsigned char n);
	/** getPointer()
		Returns a T pointer to the matrix array.
		Use: matrix.getPointer()
		Result: Pointer to array is returned*/
	T*			getPointer();
	/** initIdentity()
		Makes matrix into a identity matrix.
		Use: matrix.initIdentity()
		Result: Matrix becomes a identity matrix.*/
	void			initIdentity();
	/** getInitIdentity()
		Returns a identity matrix.
		Use: Matrix4::getInitIdentity()
		Result: Returns a identity Matrix4.*/
	static Matrix4<T>	getInitIdentity();
	/** initLookAt(Vertex3f&, Vertex3f&, Vector3f&)
		Method to create a lookAt matrix.
		Use: matrix.initLookAt(vertex1, vertex2, vector)
		Result: Matric becomes a lookAt matrix.**/
	void			initLookAt	(const Vertex3<T>& eyePos, const Vertex3<T>& targetPos, const Vector3<T>& upVec);
	
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
	/** mult(Matrix4&, T)
		Multiplies the matrix with the scalar.
		Use: Matrix4::mult(matrix, value);
		Result: New Matrix4 is returned.*/
	static Matrix4<T>	mult		(const Matrix4<T>& mat, T value);
	/** mult(T, Matrix4&)
		Multiplies the matrix with the scalar.
		Use: Matrix4::mult(value, matrix);
		Result: New Matrix4 is returned.*/
	static Matrix4<T>	mult		(T value, const Matrix4<T>& mat);
	/** operator * (T)
		Multiplies the matrix with the scalar.
		Use: matrix * value
		Result: New Matrix4 is returned.*/
	Matrix4<T>		operator *	(T value);
	/** friend operator * (Matrix4&)
		Multiplies the matrix with the scalar.
		Use: value * matrix
		Result: New Matrix4 is returned.*/
	//friend Matrix4<T>	operator *	(T value, const Matrix4<T>& mat);

	// ----------------------------------------------------------
	// Matrix Multiplication
	
	/** mult(Matrix4&)
		Multiplies the matrices.
		Use: matrix.mult(matrix)
		Result: Matrix calling the method is changed.*/
	void			mult		(const Matrix4<T>& mat);
	/** operator *=(Matrix4&)
		Multiplies the matrices.
		Use: matrix *= matrix
		Result: Matrix calling the method is changed.*/
	void			operator *=	(const Matrix4<T>& mat);
	/** mult(Matrix4&, Matrix4&)
		Multiplies the matrices.
		Use: mult(matrix, matrix)
		Result: A new Matrix4 is returned.*/
	static Matrix4<T>	mult		(const Matrix4<T>& mat1, const Matrix4<T>& mat2);
	/** operator *(Matrix4&)
		Multiplies the matrices.
		Use: matrix * matrix
		Result: A new Matrix4 is returned.*/
	Matrix4<T>		operator *	(const Matrix4<T>& mat);
	
	// ----------------------------------------------------------
	// Vector Multiplication
	
	/** mult(Matrix4&, Vector4f&)
		Multiplies the matrix and the vector.
		Use: mult(matrix, vector)
		Result: A new Vector4f is returned.*/
	static Vector4<T>	mult		(const Matrix4<T>& mat, const Vector4<T>& vec);
	/** mult(Vector4f&)
		Multiplies the matrix and the vector.
		Use: matrix.mult(vector)
		Result: A new Vector4f is returned.*/
	Vector4<T>          mult		(const Vector4<T>& vec);
	/** operator *(Vector4f&)
		Multiplies the matrix and the vector.
		Use: matrix * vector
		Result: A new Vector4f is returned.*/
	Vector4<T>          operator *	(const Vector4<T>& vec);

	// ----------------------------------------------------------
	// Translation
	
	/** initTranslate(T, T, T)
		Makes matrix calling method into a translation matrix.
		Use: matrix.initTranslation(T, T, T);
		Result: Matrix becomes a translation matrix that can
				be used for translating other things.*/
	void			initTranslation	(T x, T y, T z);
	/** translate(T, T, T)
		Translate the matrix that's calling the method
		Use: matrix.translate(T, T, T);
		Result: Translate a matrix.*/
	void			translate		(T x, T y, T z);
	/** translated(T, T, T)
		Return the translated matrix that's calling the method
		Use: matrix.translated(T, T, T);
		Result: Returns a translated matrix.*/
	Matrix4<T>		translated		(T x, T y, T z);
	/** getTranslation(T, T, T)
		Returns a translation matrix.
		Use: Matrix4::getTranslation(T, T, T)
		Result: Returns a translation matrix.*/
	static Matrix4<T>	getTranslation	(T x, T y, T z);
	/** position()
		Returns a vertex containing position.
		Use: matrix.position()
		Result: A Vertex3f is returned*/
	Vertex3<T> position			();
	/** getPosition(Matrix4 &)
		Returns a vertex containing position.
		Use: Matrix4::getPosition(matrix)
		Result: A Vertex3f is returned*/
	static Vertex3<T> getPosition	(Matrix4<T> &mat);
	
	// ----------------------------------------------------------
	// Scale

	/** initScale (T, T, T)
		Makes matrix calling method into a scale matrix.
		Use: matrix.initScale(T, T, T)
		Result: Matrix becomes a scale matrix that can be
				used to scale other things.*/
	void			initScale		(T x, T y, T z);
	/** scale (T, T, T)
		Scale the matrix that's calling the method.
		Use: matrix.scale(T, T, T)
		Result: Scale the matrix.*/
	void			scale			(T x, T y, T z);
	/** scaled(T, T, T)
		Return the scaled matrix that's calling the method
		Use: matrix.scaled(T, T, T);
		Result: Returns a scaled matrix.*/
	Matrix4<T>		scaled			(T x, T y, T z);
	/** getScale(T, T, T)
		Returns a scale matrix.
		Use: Matrix4::getScale(T, T, T)
		Result: Returns a scale matrix.*/
	static Matrix4<T> getScale		(T x, T y, T z);

	// ----------------------------------------------------------
	// Rotation
	
	/** rotateX(T)
		Rotate matrix around the x-axis. Uses radians.
		Use: matrix.rotateX(T)
		Result: Matrix rotates around x-axis.*/
	void			rotateX			(T rad);
	/** initRotateX(T)
		Creates a x-rotation matrix. Uses radians.
		Use: matrix.initRotateX(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateX		(T rad);
	/** getRotateX(T)
		Returns a x-rotation matrix. Uses radians.
		Use: Matrix4::getRotateX(T)
		Result: Returns a rotation matrix.*/
	static Matrix4<T>	getRotateX		(T rad);
	
	/** rotateY(T)
		Rotate matrix around the y-axis. Uses radians.
		Use: matrix.rotateY(T)
		Result: Matrix rotates around y-axis.*/
	void			rotateY			(T rad);
	/** initRotateY(T)
		Creates a y-rotation matrix. Uses radians.
		Use: matrix.initRotateY(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateY		(T rad);
	/** getRotateY(T)
		Returns a y-rotation matrix. Uses radians.
		Use: Matrix4::getRotateY(T)
		Result: Returns a rotation matrix.*/
	static Matrix4<T>	getRotateY		(T rad);
	
	/** rotateZ(T)
		Rotate matrix around the z-axis. Uses radians.
		Use: matrix.rotateZ(T)
		Result: Matrix rotates around z-axis.*/
	void			rotateZ			(T rad);
	/** initRotateZ(T)
		Creates a z-rotation matrix. Uses radians.
		Use: matrix.initRotateZ(T)
		Result: Matrix becomes a rotation matrix.*/
	void			initRotateZ		(T rad);
	/** getRotateZ(T)
		Returns a z-rotation matrix. Uses radians.
		Use: Matrix4::getRotateZ(T)
		Result: Returns a rotation matrix.*/
	static Matrix4<T>	getRotateZ		(T rad);
	
	/** rotateMatrix(T, T, T, T)
		Rotates a vector with the matrix. Uses radians.
		Use: matrix.rotateMatrix(T, T, T, T)
		Result: Matrix is rotates around a vector.*/
	void			rotateMatrix	(T rad, T x, T y, T z);
	/** initRotateMatrix(T, T, T, T)
		Creates a vector rotation matrix. Uses radians.
		Use: matrix.initRotateMatrix(T, T, T, T)
		Result: Matrix becomes a vector rotation matrix.*/
	void			initRotateMatrix(T rad, T x, T y, T z);
	/** getRotateMatrix(T, T, T, T)
		Returns a vector rotation matrix. Uses radians.
		Use: Matrix4::getRotateMatrix(T, T, T, T)
		Result: Returns a vector rotation matrix*/
	static Matrix4<T>	getRotateMatrix	(T rad, T x, T y, T z);

	// ----------------------------------------------------------
	// Projection Matrices
	
	/** initProjectionOrthogonal(T, T, T, T, T, T)
		Creates an Orthogonal projection matrix.
		Use: matrix.initProjectionOrthogonal(T, ..., T)
		Result: Matrix is set up as an orthogonal projection matrix.*/
	void			initProjectionOrthogonal(T left, T right, T bottom, T top, T zNear, T zFar);
	/** getInitProjectionOrthogonal(T, T, T, T, T, T)
		Creates and returns an Orthogonal projection matrix.
		Use: Matrix4::initProjectionOrthogonal(T, ..., T)
		Result: Returns a matrix that is set up as an orthogonal projection matrix.*/
	static Matrix4<T>	getInitProjectionOrthogonal(T left, T right, T bottom, T top, T zNear, T zFar);

	/** initProjectionOrthogonal(T, T, T, T, T, T)
		Creates a perspective projection matrix.
		Use: matrix.initProjectionPerspective(T, ..., T)
		Result: Matrix is set up as a perspective projection matrix.*/
	void			initProjectionPerspective(T left, T right, T bottom, T top, T zNear, T zFar);
	/** getInitProjectionPerspective((T, T, T, T, T, T)
		Creates a perspective projection matrix.
		Use: Matrix4::getInitProjectionPerspective(T, ..., T)
		Result: Returns a matrix that is set up as a perspective projection matrix.*/
	static Matrix4<T>	getInitProjectionPerspective(T left, T right, T bottom, T top, T zNear, T zFar);
    
	/** initProjectionOtherPerspective(T, T, T, T, T, T)
		Creates a sort of perspective projection matrix.
		Use: matrix.initProjectionOtherPerspective(T, ..., T)
		Result: Matrix is set up as a kind of perspective projection matrix.*/
	void			initProjectionOtherPerspective(T left, T right, T bottom, T top, T zNear, T zFar);

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
	Matrix4<T>		transposed	();
	/** operator ~()
		Transposes the matrix.
		Use: ~matrix
		Result: A new transposed version of the matrix is returned.*/
	Matrix4<T>		operator ~	();

	// ----------------------------------------------------------
	// Inverse
	
	/** getDeterminant()
		Returns the determinant.
		Use: matrix.getDeterminant()
		Result: Returns the determinant as a T.*/
	T			getDeterminant();
	/** inverse()
		Change the current matrix to be it's inverse.
		Precondition: The determinant must not be zero.
		Use: matrix.inverse()
		Result: Inverses the matrix. If precondition isn't met
				an overflow_error will be thrown.*/
	void			inverse		();
	/** inverse()
		Change the parameter matrix to be it's inverse.
		Precondition: The determinant must not be zero.
		Use: Matrix4::inverse(matrix)
		Result: Inverses the matrix. If precondition isn't met
				an overflow_error will be thrown.*/
	static void		inverse		(Matrix4<T>& mat);
	/** inverse()
		Sets the inverse of the matrix 'mat' into the
		destination matrix 'dest'.
		Precondition: The determinant must not be zero.
		Use: Matrix4::inverse(matrix, matrix)
		Result: Inverses the matrix into the destination matrix.
				If precondition isn't met an overflow_error will be thrown.*/
	static void		inverse		(Matrix4<T>& mat, Matrix4<T>& dest);
	/** inverse()
		Inverses the current matrix and returns it.
		Precondition: The determinant must not be zero.
		Use: matrix.inversed()
		Result: Returns a inversed version of the matrix.
				If precondition isn't met an overflow_error will be thrown.*/
	Matrix4<T>		inversed	();
	/** inverse()
		Inverses the parameter matrix and returns it.
		Precondition: The determinant must not be zero.
		Use: Matrix4::inversed(matrix)
		Result: Returns a inversed version of the matrix.
		If precondition isn't met an overflow_error will be thrown.*/
	static Matrix4<T>	inversed	(Matrix4<T>& mat);


	// ----------------------------------------------------------
	// Variables
	
	/** coord[16]
		An array representing a matrix three rows and three columns.
		In Matrix4 the values are T type values.
		[0 ][4 ][8 ][12]
		[1 ][5 ][9 ][13]
		[2 ][6 ][10][14]
		[3 ][7 ][11][15]*/
	T coord[16];
};


//--------------------------------------------------------------------------------------------------
//	Implementation
//--------------------------------------------------------------------------------------------------


// ----------------------------------------------------------
// Constructors

template <class T>
Matrix4<T>::Matrix4(){
	coord[0] = 1; coord[4] = 0; coord[8 ] = 0; coord[12] = 0;
	coord[1] = 0; coord[5] = 1; coord[9 ] = 0; coord[13] = 0;
	coord[2] = 0; coord[6] = 0; coord[10] = 1; coord[14] = 0;
	coord[3] = 0; coord[7] = 0; coord[11] = 0; coord[15] = 1;
}
template <class T>
Matrix4<T>::Matrix4(T n1, T n2, T n3, T n4,
				   T n5, T n6, T n7, T n8,
				   T n9, T n10, T n11, T n12,
				   T n13, T n14, T n15, T n16){
	coord[0] = n1; coord[4] = n2; coord[8 ] = n3; coord[12] = n4;
	coord[1] = n5; coord[5] = n6; coord[9 ] = n7; coord[13] = n8;
	coord[2] = n9; coord[6] = n10; coord[10] = n11; coord[14] = n12;
	coord[3] = n13; coord[7] = n14; coord[11] = n15; coord[15] = n16;
}
template <class T>
Matrix4<T>::Matrix4(T mat[16]){
	coord[0] = mat[0]; coord[4] = mat[1]; coord[8 ] = mat[2]; coord[12] = mat[3];
	coord[1] = mat[4]; coord[5] = mat[5]; coord[9 ] = mat[6]; coord[13] = mat[7];
	coord[2] = mat[8]; coord[6] = mat[9]; coord[10] = mat[10]; coord[14] = mat[11];
	coord[3] = mat[12]; coord[7] = mat[13]; coord[11] = mat[14]; coord[15] = mat[15];
}
template <class T>
Matrix4<T>::Matrix4(const Matrix3<T>& mat){
	coord[0] = (T)mat.coord[0]; coord[4] = (T)mat.coord[3]; coord[8 ] = (T)mat.coord[6];	coord[12] = 0;
	coord[1] = (T)mat.coord[1]; coord[5] = (T)mat.coord[4]; coord[9 ] = (T)mat.coord[7];	coord[13] = 0;
	coord[2] = (T)mat.coord[2]; coord[6] = (T)mat.coord[5]; coord[10] = (T)mat.coord[8];	coord[14] = 0;
	coord[3] = 0;				coord[7] = 0;				coord[11] = 0;					coord[15] = 1;
}
template <class T>
Matrix4<T>::Matrix4(const Matrix4f& mat){
	coord[0] = (T)mat.coord[0]; coord[4] = (T)mat.coord[4]; coord[8] = (T)mat.coord[8]; coord[12] = (T)mat.coord[12];
	coord[1] = (T)mat.coord[1]; coord[5] = (T)mat.coord[5]; coord[9] = (T)mat.coord[9]; coord[13] = (T)mat.coord[13];
	coord[2] = (T)mat.coord[2]; coord[6] = (T)mat.coord[6]; coord[10] = (T)mat.coord[10]; coord[14] = (T)mat.coord[14];
	coord[3] = (T)mat.coord[3]; coord[7] = (T)mat.coord[7]; coord[11] = (T)mat.coord[11]; coord[15] = (T)mat.coord[15];
}
template <class T>
Matrix4<T>::Matrix4(const Matrix4d& mat){
	coord[0] = (T)mat.coord[0]; coord[4] = (T)mat.coord[4]; coord[8] = (T)mat.coord[8]; coord[12] = (T)mat.coord[12];
	coord[1] = (T)mat.coord[1]; coord[5] = (T)mat.coord[5]; coord[9] = (T)mat.coord[9]; coord[13] = (T)mat.coord[13];
	coord[2] = (T)mat.coord[2]; coord[6] = (T)mat.coord[6]; coord[10] = (T)mat.coord[10]; coord[14] = (T)mat.coord[14];
	coord[3] = (T)mat.coord[3]; coord[7] = (T)mat.coord[7]; coord[11] = (T)mat.coord[11]; coord[15] = (T)mat.coord[15];
}

// ----------------------------------------------------------
// Other Implementations

template <class T>
void Matrix4<T>::operator =(const Matrix4& vec){
	for(int i = 0; i < 16; ++i)
		coord[i] = vec.coord[i];
}
template <class T>
bool Matrix4<T>::operator ==(const Matrix4& mat) const{
	bool result = true;
	for(int i = 0; i < 16; ++i){
		if(coord[i] != mat.coord[i]){
			result = false;
			break;
		}
	}
	return result;
}
template <class T>
bool Matrix4<T>::operator !=(const Matrix4& mat) const{
	char count = 0;
	for(int i = 0; i < 16; ++i){
		if(coord[i] == mat.coord[i]){
			++count;
		}
	}
	if(count == 16)
		return false;
	return true;
}
template <class T>
void Matrix4<T>::getContentRowWise(T * arr){
	arr[0] = coord[0]; arr[4] = coord[1]; arr[8 ] = coord[2]; arr[12] = coord[3];
	arr[1] = coord[4]; arr[5] = coord[5]; arr[9 ] = coord[6]; arr[13] = coord[7];
	arr[2] = coord[8]; arr[6] = coord[9]; arr[10] = coord[10]; arr[14] = coord[11];
	arr[3] = coord[12]; arr[7] = coord[13]; arr[11] = coord[14]; arr[15] = coord[15];
}
template <class T>
T* Matrix4<T>::getContentRowWise(){
	T* arr = new T[16];
	arr[0] = coord[0]; arr[4] = coord[1]; arr[8 ] = coord[2]; arr[12] = coord[3];
	arr[1] = coord[4]; arr[5] = coord[5]; arr[9 ] = coord[6]; arr[13] = coord[7];
	arr[2] = coord[8]; arr[6] = coord[9]; arr[10] = coord[10]; arr[14] = coord[11];
	arr[3] = coord[12]; arr[7] = coord[13]; arr[11] = coord[14]; arr[15] = coord[15];
	return arr;
}
template <class T>
void Matrix4<T>::getContentColumnWise(T * arr){
	arr[0] = coord[0]; arr[4] = coord[4]; arr[8 ] = coord[8 ]; arr[12] = coord[12];
	arr[1] = coord[1]; arr[5] = coord[5]; arr[9 ] = coord[9 ]; arr[13] = coord[13];
	arr[2] = coord[2]; arr[6] = coord[6]; arr[10] = coord[10]; arr[14] = coord[14];
	arr[3] = coord[3]; arr[7] = coord[7]; arr[11] = coord[11]; arr[15] = coord[15];
}
template <class T>
T* Matrix4<T>::getContentColumnWise(){
	return coord;
}
template <class T>
T Matrix4<T>::operator ()(unsigned char x, unsigned char y) const{
	return coord[x*4+y];
}
template <class T>
T& Matrix4<T>::operator ()(unsigned char x, unsigned char y){
	return coord[x*4+y];
}
template <class T>
T Matrix4<T>::operator [](unsigned char n) const{
    return coord[n];
}
template <class T>
T& Matrix4<T>::operator [](unsigned char n){
    return coord[n];
}
template <class T>
T* Matrix4<T>::getPointer(){
	return coord;
}
template <class T>
void Matrix4<T>::initIdentity(){
	coord[0] = 1; coord[4] = 0; coord[8 ] = 0; coord[12] = 0;
	coord[1] = 0; coord[5] = 1; coord[9 ] = 0; coord[13] = 0;
	coord[2] = 0; coord[6] = 0; coord[10] = 1; coord[14] = 0;
	coord[3] = 0; coord[7] = 0; coord[11] = 0; coord[15] = 1;
}
template <class T>
Matrix4<T> Matrix4<T>::getInitIdentity(){
	Matrix4 matrix(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
    return matrix;
}
template <class T>
void Matrix4<T>::initLookAt(const Vertex3<T>& eyePos, const Vertex3<T>& targetPos, const Vector3<T>& upVec){
	Vector3<T> zAxis = (Vector3<T>(Vector3<T>(targetPos) - Vector3<T>(eyePos))).normalized();
	Vector3<T> xAxis = (Vector3<T>::cross(upVec, zAxis)).normalized();
	Vector3<T> yAxis = (Vector3<T>::cross(zAxis, xAxis)).normalized();

	coord[0] = xAxis.coord[0];		coord[4] = yAxis.coord[0];		coord[8 ] = zAxis.coord[0];		//coord[12] = 0;
	coord[1] = xAxis.coord[1];		coord[5] = yAxis.coord[1];		coord[9 ] = zAxis.coord[1];		//coord[13] = 0;
	coord[2] = xAxis.coord[2];		coord[6] = yAxis.coord[2];		coord[10] = zAxis.coord[2];		//coord[14] = 0;
	//coord[3] = 0;					//coord[7] = 0;					//coord[11] = 0;					//coord[15] = 1;
	
	/*
	Vector3f forward = Vector3f(targetPos, eyePos);
	forward.normalize();

	Vector3f side = Vector3f::cross(forward, upVec);
	side.normalize();

	Vector3f up = Vector3f::cross(side, forward);

	coord[0] = side[0];			coord[4] = side[1];			coord[8 ] = side[2];			coord[12] = 0;
	coord[1] = up[0];			coord[5] = up[1];			coord[9 ] = up[2];				coord[13] = 0;
	coord[2] = -forward[0];		coord[6] = -forward[1];		coord[10] = -forward[2];		coord[14] = 0;
	coord[3] = 0;				coord[7] = 0;				coord[11] = 0;					coord[15] = 1;
	*/
	/*

	Vector3f forward = center - eye;
	forward.normalize();

	Vector3f side = forward.cross(up);
	side.normalize();

	Vector3f rightUp = side.cross(forward);

	view = Matrix4d();

	view[0][0] = side[0];		view[1][0] = side[1];		view[2][0] = side[2];
	view[0][1] = rightUp[0];	view[1][1] = rightUp[1];	view[2][1] = rightUp[2];
	view[0][2] = -forward[0];	view[1][2] = -forward[1];	view[2][2] = -forward[2];

	*/

/*
	Vector3f zAxis = Vector3f::normalized(Vector3f((targetPos - eyePos)));
	Vector3f xAxis = Vector3f::normalized(Vector3f::cross(upVec, zAxis));
	Vector3f yAxis = Vector3f::normalized(Vector3f::cross(zAxis, xAxis));

	coord[0] = xAxis.coord[0];							coord[4] = yAxis.coord[0];							coord[8 ] = zAxis.coord[0];							 coord[12] = 0;
	coord[1] = xAxis.coord[1];							coord[5] = yAxis.coord[1];							coord[9 ] = zAxis.coord[1];							 coord[13] = 0;
	coord[2] = xAxis.coord[2];							coord[6] = yAxis.coord[2];							coord[10] = zAxis.coord[2];							 coord[14] = 0;
	coord[3] = -Vector3f::dot(xAxis, Vector3f(eyePos)); coord[7] = -Vector3f::dot(yAxis, Vector3f(eyePos)); coord[11] = -Vector3f::dot(zAxis, Vector3f(eyePos)); coord[15] = 1;
	*/
}


// ----------------------------------------------------------
// Scalar Multiplication

template <class T>
void Matrix4<T>::mult(T value){
	coord[0] *= value; coord[4] *= value; coord[8 ] *= value; coord[12] *= value;
	coord[1] *= value; coord[5] *= value; coord[9 ] *= value; coord[13] *= value;
	coord[2] *= value; coord[6] *= value; coord[10] *= value; coord[14] *= value;
	coord[3] *= value; coord[7] *= value; coord[11] *= value; coord[15] *= value;
}
template <class T>
void Matrix4<T>::operator *=(T value){
	coord[0] *= value; coord[4] *= value; coord[8 ] *= value; coord[12] *= value;
	coord[1] *= value; coord[5] *= value; coord[9 ] *= value; coord[13] *= value;
	coord[2] *= value; coord[6] *= value; coord[10] *= value; coord[14] *= value;
	coord[3] *= value; coord[7] *= value; coord[11] *= value; coord[15] *= value;
}
template <class T>
Matrix4<T> Matrix4<T>::mult(const Matrix4& mat, T value){
	Matrix4 matrix(
		mat.coord[0] * value, mat.coord[4] * value, mat.coord[8 ] * value, mat.coord[12] * value,
		mat.coord[1] * value, mat.coord[5] * value, mat.coord[9 ] * value, mat.coord[13] * value,
		mat.coord[2] * value, mat.coord[6] * value, mat.coord[10] * value, mat.coord[14] * value,
		mat.coord[3] * value, mat.coord[7] * value, mat.coord[11] * value, mat.coord[15] * value);
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::mult(T value, const Matrix4& mat){
	Matrix4 matrix(
		mat.coord[0] * value, mat.coord[4] * value, mat.coord[8 ] * value, mat.coord[12] * value,
		mat.coord[1] * value, mat.coord[5] * value, mat.coord[9 ] * value, mat.coord[13] * value,
		mat.coord[2] * value, mat.coord[6] * value, mat.coord[10] * value, mat.coord[14] * value,
		mat.coord[3] * value, mat.coord[7] * value, mat.coord[11] * value, mat.coord[15] * value);
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::operator *(T value){
	Matrix4 matrix(
		coord[0] * value, coord[4] * value, coord[8 ] * value, coord[12] * value,
		coord[1] * value, coord[5] * value, coord[9 ] * value, coord[13] * value,
		coord[2] * value, coord[6] * value, coord[10] * value, coord[14] * value,
		coord[3] * value, coord[7] * value, coord[11] * value, coord[15] * value);
    return matrix;
}
template <class T>
Matrix4<T> operator *(T value, const Matrix4<T>& mat){
	Matrix4<T> matrix(
		mat.coord[0] * value, mat.coord[4] * value, mat.coord[8 ] * value, mat.coord[12] * value,
		mat.coord[1] * value, mat.coord[5] * value, mat.coord[9 ] * value, mat.coord[13] * value,
		mat.coord[2] * value, mat.coord[6] * value, mat.coord[10] * value, mat.coord[14] * value,
		mat.coord[3] * value, mat.coord[7] * value, mat.coord[11] * value, mat.coord[15] * value);
    return matrix;
}

// ----------------------------------------------------------
// Matrix Multiplication

template <class T>
void Matrix4<T>::mult(const Matrix4& mat){
	Matrix4 matrix(
		((coord[0] * mat.coord[0 ]) + (coord[4] * mat.coord[1 ]) + (coord[8] * mat.coord[2 ]) + (coord[12] * mat.coord[3 ])),
		((coord[0] * mat.coord[4 ]) + (coord[4] * mat.coord[5 ]) + (coord[8] * mat.coord[6 ]) + (coord[12] * mat.coord[7 ])),
		((coord[0] * mat.coord[8 ]) + (coord[4] * mat.coord[9 ]) + (coord[8] * mat.coord[10]) + (coord[12] * mat.coord[11])),
		((coord[0] * mat.coord[12]) + (coord[4] * mat.coord[13]) + (coord[8] * mat.coord[14]) + (coord[12] * mat.coord[15])),

		((coord[1] * mat.coord[0 ]) + (coord[5] * mat.coord[1 ]) + (coord[9] * mat.coord[2 ]) + (coord[13] * mat.coord[3 ])),
		((coord[1] * mat.coord[4 ]) + (coord[5] * mat.coord[5 ]) + (coord[9] * mat.coord[6 ]) + (coord[13] * mat.coord[7 ])),
		((coord[1] * mat.coord[8 ]) + (coord[5] * mat.coord[9 ]) + (coord[9] * mat.coord[10]) + (coord[13] * mat.coord[11])),
		((coord[1] * mat.coord[12]) + (coord[5] * mat.coord[13]) + (coord[9] * mat.coord[14]) + (coord[13] * mat.coord[15])),

		((coord[2] * mat.coord[0 ]) + (coord[6] * mat.coord[1 ]) + (coord[10] * mat.coord[2 ]) + (coord[14] * mat.coord[3 ])),
		((coord[2] * mat.coord[4 ]) + (coord[6] * mat.coord[5 ]) + (coord[10] * mat.coord[6 ]) + (coord[14] * mat.coord[7 ])),
		((coord[2] * mat.coord[8 ]) + (coord[6] * mat.coord[9 ]) + (coord[10] * mat.coord[10]) + (coord[14] * mat.coord[11])),
		((coord[2] * mat.coord[12]) + (coord[6] * mat.coord[13]) + (coord[10] * mat.coord[14]) + (coord[14] * mat.coord[15])),

		((coord[3] * mat.coord[0 ]) + (coord[7] * mat.coord[1 ]) + (coord[11] * mat.coord[2 ]) + (coord[15] * mat.coord[3 ])),
		((coord[3] * mat.coord[4 ]) + (coord[7] * mat.coord[5 ]) + (coord[11] * mat.coord[6 ]) + (coord[15] * mat.coord[7 ])),
		((coord[3] * mat.coord[8 ]) + (coord[7] * mat.coord[9 ]) + (coord[11] * mat.coord[10]) + (coord[15] * mat.coord[11])),
		((coord[3] * mat.coord[12]) + (coord[7] * mat.coord[13]) + (coord[11] * mat.coord[14]) + (coord[15] * mat.coord[15])));
    *this = matrix;
}
template <class T>
void Matrix4<T>::operator *=(const Matrix4& mat){
	Matrix4 matrix(
		((coord[0] * mat.coord[0 ]) + (coord[4] * mat.coord[1 ]) + (coord[8] * mat.coord[2 ]) + (coord[12] * mat.coord[3 ])),
		((coord[0] * mat.coord[4 ]) + (coord[4] * mat.coord[5 ]) + (coord[8] * mat.coord[6 ]) + (coord[12] * mat.coord[7 ])),
		((coord[0] * mat.coord[8 ]) + (coord[4] * mat.coord[9 ]) + (coord[8] * mat.coord[10]) + (coord[12] * mat.coord[11])),
		((coord[0] * mat.coord[12]) + (coord[4] * mat.coord[13]) + (coord[8] * mat.coord[14]) + (coord[12] * mat.coord[15])),

		((coord[1] * mat.coord[0 ]) + (coord[5] * mat.coord[1 ]) + (coord[9] * mat.coord[2 ]) + (coord[13] * mat.coord[3 ])),
		((coord[1] * mat.coord[4 ]) + (coord[5] * mat.coord[5 ]) + (coord[9] * mat.coord[6 ]) + (coord[13] * mat.coord[7 ])),
		((coord[1] * mat.coord[8 ]) + (coord[5] * mat.coord[9 ]) + (coord[9] * mat.coord[10]) + (coord[13] * mat.coord[11])),
		((coord[1] * mat.coord[12]) + (coord[5] * mat.coord[13]) + (coord[9] * mat.coord[14]) + (coord[13] * mat.coord[15])),

		((coord[2] * mat.coord[0 ]) + (coord[6] * mat.coord[1 ]) + (coord[10] * mat.coord[2 ]) + (coord[14] * mat.coord[3 ])),
		((coord[2] * mat.coord[4 ]) + (coord[6] * mat.coord[5 ]) + (coord[10] * mat.coord[6 ]) + (coord[14] * mat.coord[7 ])),
		((coord[2] * mat.coord[8 ]) + (coord[6] * mat.coord[9 ]) + (coord[10] * mat.coord[10]) + (coord[14] * mat.coord[11])),
		((coord[2] * mat.coord[12]) + (coord[6] * mat.coord[13]) + (coord[10] * mat.coord[14]) + (coord[14] * mat.coord[15])),

		((coord[3] * mat.coord[0 ]) + (coord[7] * mat.coord[1 ]) + (coord[11] * mat.coord[2 ]) + (coord[15] * mat.coord[3 ])),
		((coord[3] * mat.coord[4 ]) + (coord[7] * mat.coord[5 ]) + (coord[11] * mat.coord[6 ]) + (coord[15] * mat.coord[7 ])),
		((coord[3] * mat.coord[8 ]) + (coord[7] * mat.coord[9 ]) + (coord[11] * mat.coord[10]) + (coord[15] * mat.coord[11])),
		((coord[3] * mat.coord[12]) + (coord[7] * mat.coord[13]) + (coord[11] * mat.coord[14]) + (coord[15] * mat.coord[15])));
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::mult(const Matrix4& mat1, const Matrix4& mat2){
	Matrix4 matrix(
		((mat1.coord[0] * mat2.coord[0 ]) + (mat1.coord[4] * mat2.coord[1 ]) + (mat1.coord[8] * mat2.coord[2 ]) + (mat1.coord[12] * mat2.coord[3 ])),
		((mat1.coord[0] * mat2.coord[4 ]) + (mat1.coord[4] * mat2.coord[5 ]) + (mat1.coord[8] * mat2.coord[6 ]) + (mat1.coord[12] * mat2.coord[7 ])),
		((mat1.coord[0] * mat2.coord[8 ]) + (mat1.coord[4] * mat2.coord[9 ]) + (mat1.coord[8] * mat2.coord[10]) + (mat1.coord[12] * mat2.coord[11])),
		((mat1.coord[0] * mat2.coord[12]) + (mat1.coord[4] * mat2.coord[13]) + (mat1.coord[8] * mat2.coord[14]) + (mat1.coord[12] * mat2.coord[15])),

		((mat1.coord[1] * mat2.coord[0 ]) + (mat1.coord[5] * mat2.coord[1 ]) + (mat1.coord[9] * mat2.coord[2 ]) + (mat1.coord[13] * mat2.coord[3 ])),
		((mat1.coord[1] * mat2.coord[4 ]) + (mat1.coord[5] * mat2.coord[5 ]) + (mat1.coord[9] * mat2.coord[6 ]) + (mat1.coord[13] * mat2.coord[7 ])),
		((mat1.coord[1] * mat2.coord[8 ]) + (mat1.coord[5] * mat2.coord[9 ]) + (mat1.coord[9] * mat2.coord[10]) + (mat1.coord[13] * mat2.coord[11])),
		((mat1.coord[1] * mat2.coord[12]) + (mat1.coord[5] * mat2.coord[13]) + (mat1.coord[9] * mat2.coord[14]) + (mat1.coord[13] * mat2.coord[15])),

		((mat1.coord[2] * mat2.coord[0 ]) + (mat1.coord[6] * mat2.coord[1 ]) + (mat1.coord[10] * mat2.coord[2 ]) + (mat1.coord[14] * mat2.coord[3 ])),
		((mat1.coord[2] * mat2.coord[4 ]) + (mat1.coord[6] * mat2.coord[5 ]) + (mat1.coord[10] * mat2.coord[6 ]) + (mat1.coord[14] * mat2.coord[7 ])),
		((mat1.coord[2] * mat2.coord[8 ]) + (mat1.coord[6] * mat2.coord[9 ]) + (mat1.coord[10] * mat2.coord[10]) + (mat1.coord[14] * mat2.coord[11])),
		((mat1.coord[2] * mat2.coord[12]) + (mat1.coord[6] * mat2.coord[13]) + (mat1.coord[10] * mat2.coord[14]) + (mat1.coord[14] * mat2.coord[15])),

		((mat1.coord[3] * mat2.coord[0 ]) + (mat1.coord[7] * mat2.coord[1 ]) + (mat1.coord[11] * mat2.coord[2 ]) + (mat1.coord[15] * mat2.coord[3 ])),
		((mat1.coord[3] * mat2.coord[4 ]) + (mat1.coord[7] * mat2.coord[5 ]) + (mat1.coord[11] * mat2.coord[6 ]) + (mat1.coord[15] * mat2.coord[7 ])),
		((mat1.coord[3] * mat2.coord[8 ]) + (mat1.coord[7] * mat2.coord[9 ]) + (mat1.coord[11] * mat2.coord[10]) + (mat1.coord[15] * mat2.coord[11])),
		((mat1.coord[3] * mat2.coord[12]) + (mat1.coord[7] * mat2.coord[13]) + (mat1.coord[11] * mat2.coord[14]) + (mat1.coord[15] * mat2.coord[15])));
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::operator *(const Matrix4& mat){
	Matrix4 matrix(
		((coord[0] * mat.coord[0 ]) + (coord[4] * mat.coord[1 ]) + (coord[8] * mat.coord[2 ]) + (coord[12] * mat.coord[3 ])),
		((coord[0] * mat.coord[4 ]) + (coord[4] * mat.coord[5 ]) + (coord[8] * mat.coord[6 ]) + (coord[12] * mat.coord[7 ])),
		((coord[0] * mat.coord[8 ]) + (coord[4] * mat.coord[9 ]) + (coord[8] * mat.coord[10]) + (coord[12] * mat.coord[11])),
		((coord[0] * mat.coord[12]) + (coord[4] * mat.coord[13]) + (coord[8] * mat.coord[14]) + (coord[12] * mat.coord[15])),

		((coord[1] * mat.coord[0 ]) + (coord[5] * mat.coord[1 ]) + (coord[9] * mat.coord[2 ]) + (coord[13] * mat.coord[3 ])),
		((coord[1] * mat.coord[4 ]) + (coord[5] * mat.coord[5 ]) + (coord[9] * mat.coord[6 ]) + (coord[13] * mat.coord[7 ])),
		((coord[1] * mat.coord[8 ]) + (coord[5] * mat.coord[9 ]) + (coord[9] * mat.coord[10]) + (coord[13] * mat.coord[11])),
		((coord[1] * mat.coord[12]) + (coord[5] * mat.coord[13]) + (coord[9] * mat.coord[14]) + (coord[13] * mat.coord[15])),

		((coord[2] * mat.coord[0 ]) + (coord[6] * mat.coord[1 ]) + (coord[10] * mat.coord[2 ]) + (coord[14] * mat.coord[3 ])),
		((coord[2] * mat.coord[4 ]) + (coord[6] * mat.coord[5 ]) + (coord[10] * mat.coord[6 ]) + (coord[14] * mat.coord[7 ])),
		((coord[2] * mat.coord[8 ]) + (coord[6] * mat.coord[9 ]) + (coord[10] * mat.coord[10]) + (coord[14] * mat.coord[11])),
		((coord[2] * mat.coord[12]) + (coord[6] * mat.coord[13]) + (coord[10] * mat.coord[14]) + (coord[14] * mat.coord[15])),

		((coord[3] * mat.coord[0 ]) + (coord[7] * mat.coord[1 ]) + (coord[11] * mat.coord[2 ]) + (coord[15] * mat.coord[3 ])),
		((coord[3] * mat.coord[4 ]) + (coord[7] * mat.coord[5 ]) + (coord[11] * mat.coord[6 ]) + (coord[15] * mat.coord[7 ])),
		((coord[3] * mat.coord[8 ]) + (coord[7] * mat.coord[9 ]) + (coord[11] * mat.coord[10]) + (coord[15] * mat.coord[11])),
		((coord[3] * mat.coord[12]) + (coord[7] * mat.coord[13]) + (coord[11] * mat.coord[14]) + (coord[15] * mat.coord[15])));
    return matrix;
}

// ----------------------------------------------------------
// Vector Multiplication

template <class T>
Vector4<T> Matrix4<T>::mult (const Matrix4& mat, const Vector4<T>& vec){
	Vector4<T> vector(
		((mat.coord[0] * vec.coord[0]) + (mat.coord[4] * vec.coord[1]) + (mat.coord[8] * vec.coord[2]) + (mat.coord[12] * vec.coord[3])),
		((mat.coord[1] * vec.coord[0]) + (mat.coord[5] * vec.coord[1]) + (mat.coord[9] * vec.coord[2]) + (mat.coord[13] * vec.coord[3])),
		((mat.coord[2] * vec.coord[0]) + (mat.coord[6] * vec.coord[1]) + (mat.coord[10] * vec.coord[2]) + (mat.coord[14] * vec.coord[3])),
		((mat.coord[3] * vec.coord[0]) + (mat.coord[7] * vec.coord[1]) + (mat.coord[11] * vec.coord[2]) + (mat.coord[15] * vec.coord[3])));
    return vector;
}
template <class T>
Vector4<T> Matrix4<T>::mult (const Vector4<T>& vec){
	Vector4<T> vector(
		((coord[0] * vec.coord[0]) + (coord[4] * vec.coord[1]) + (coord[8] * vec.coord[2]) + (coord[12] * vec.coord[3])),
		((coord[1] * vec.coord[0]) + (coord[5] * vec.coord[1]) + (coord[9] * vec.coord[2]) + (coord[13] * vec.coord[3])),
		((coord[2] * vec.coord[0]) + (coord[6] * vec.coord[1]) + (coord[10] * vec.coord[2]) + (coord[14] * vec.coord[3])),
		((coord[3] * vec.coord[0]) + (coord[7] * vec.coord[1]) + (coord[11] * vec.coord[2]) + (coord[15] * vec.coord[3])));
    return vector;
}
template <class T>
Vector4<T> Matrix4<T>::operator *(const Vector4<T>& vec){
	Vector4<T> vector(
		((coord[0] * vec.coord[0]) + (coord[4] * vec.coord[1]) + (coord[8] * vec.coord[2]) + (coord[12] * vec.coord[3])),
		((coord[1] * vec.coord[0]) + (coord[5] * vec.coord[1]) + (coord[9] * vec.coord[2]) + (coord[13] * vec.coord[3])),
		((coord[2] * vec.coord[0]) + (coord[6] * vec.coord[1]) + (coord[10] * vec.coord[2]) + (coord[14] * vec.coord[3])),
		((coord[3] * vec.coord[0]) + (coord[7] * vec.coord[1]) + (coord[11] * vec.coord[2]) + (coord[15] * vec.coord[3])));
    return vector;
}

// ----------------------------------------------------------
// Translation

template <class T>
void Matrix4<T>::initTranslation(T x, T y, T z){
	Matrix4 matrix(
		1		, 0		, 0		, x		,
		0		, 1		, 0		, y		,
		0		, 0		, 1		, z		,
		0		, 0		, 0		, 1		);
    *this = matrix;
}
template <class T>
void Matrix4<T>::translate(T x, T y, T z){
	Matrix4 matrix(
		1		, 0		, 0		, x		,
		0		, 1		, 0		, y		,
		0		, 0		, 1		, z		,
		0		, 0		, 0		, 1		);
    *this *= matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::translated(T x, T y, T z){
	Matrix4 matrix(*this * Matrix4(
		1		, 0		, 0		, x		,
		0		, 1		, 0		, y		,
		0		, 0		, 1		, z		,
		0		, 0		, 0		, 1		));
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getTranslation(T x, T y, T z){
	Matrix4 matrix(
		1		, 0		, 0		, x		,
		0		, 1		, 0		, y		,
		0		, 0		, 1		, z		,
		0		, 0		, 0		, 1		);
    return matrix;
}
template <class T>
Vertex3<T> Matrix4<T>::position(){
	Vertex3<T> vector(coord[12], coord[13], coord[14]);
    return vector;
}
template <class T>
Vertex3<T> Matrix4<T>::getPosition(Matrix4 &mat){
	Vertex3<T> vector(mat.coord[12], mat.coord[13], mat.coord[14]);
    return vector;
}

// ----------------------------------------------------------
// Scale

template <class T>
void Matrix4<T>::initScale(T x, T y, T z){
	Matrix4 matrix(
		x		, 0		, 0		, 0		,
		0		, y		, 0		, 0		,
		0		, 0		, z		, 0		,
		0		, 0		, 0		, 1		);
    *this = matrix;
}
template <class T>
void Matrix4<T>::scale(T x, T y, T z){
	Matrix4 matrix(
		x		, 0		, 0		, 0		,
		0		, y		, 0		, 0		,
		0		, 0		, z		, 0		,
		0		, 0		, 0		, 1		);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::scaled(T x, T y, T z){
	Matrix4 matrix(*this * Matrix4(
		x		, 0		, 0		, 0		,
		0		, y		, 0		, 0		,
		0		, 0		, z		, 0		,
		0		, 0		, 0		, 1		));
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getScale(T x, T y, T z){
	Matrix4 matrix(
		x		, 0		, 0		, 0		,
		0		, y		, 0		, 0		,
		0		, 0		, z		, 0		,
		0		, 0		, 0		, 1		);
    return matrix;
}

// ----------------------------------------------------------
// Rotation

// X
template <class T>
void Matrix4<T>::rotateX(T rad){
	Matrix4 matrix(
		1			, 0			, 0			, 0			,
		0			, cos(rad)	, -sin(rad)	, 0			,
		0			, sin(rad)	, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    *this *= matrix;
}
template <class T>
void Matrix4<T>::initRotateX(T rad){
	Matrix4 matrix(
		1			, 0			, 0			, 0			,
		0			, cos(rad)	, -sin(rad)	, 0			,
		0			, sin(rad)	, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getRotateX(T rad){
	Matrix4 matrix(
		1			, 0			, 0			, 0			,
		0			, cos(rad)	, -sin(rad)	, 0			,
		0			, sin(rad)	, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    return matrix;
}
// Y
template <class T>
void Matrix4<T>::rotateY(T rad){
	Matrix4 matrix(
		cos(rad)	, 0			, sin(rad)	, 0			,
		0			, 1			, 0			, 0			,
		-sin(rad)	, 0			, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    *this *= matrix;
}
template <class T>
void Matrix4<T>::initRotateY(T rad){
	Matrix4 matrix(
		cos(rad)	, 0			, sin(rad)	, 0			,
		0			, 1			, 0			, 0			,
		-sin(rad)	, 0			, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getRotateY(T rad){
	Matrix4 matrix(
		cos(rad)	, 0			, sin(rad)	, 0			,
		0			, 1			, 0			, 0			,
		-sin(rad)	, 0			, cos(rad)	, 0			,
		0			, 0			, 0			, 1			);
    return matrix;
}
// Z
template <class T>
void Matrix4<T>::rotateZ(T rad){
	Matrix4 matrix(
		cos(rad)	, -sin(rad)	, 0			, 0			,
		sin(rad)	, cos(rad)	, 0			, 0			,
		0			, 0			, 1			, 0			,
		0			, 0			, 0			, 1			);
    *this *= matrix;
}
template <class T>
void Matrix4<T>::initRotateZ(T rad){
	Matrix4 matrix(
		cos(rad)	, -sin(rad)	, 0			, 0			,
		sin(rad)	, cos(rad)	, 0			, 0			,
		0			, 0			, 1			, 0			,
		0			, 0			, 0			, 1			);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getRotateZ(T rad){
	Matrix4 matrix(
		cos(rad)	, -sin(rad)	, 0			, 0			,
		sin(rad)	, cos(rad)	, 0			, 0			,
		0			, 0			, 1			, 0			,
		0			, 0			, 0			, 1			);
    return matrix;
}
// All
template <class T>
void Matrix4<T>::rotateMatrix(T rad, T x, T y, T z){
	T c = cos(rad);
	T s = sin(rad);

	Vector4<T> vec(x,y,z,0);
	vec.normalize();

	x = vec.coord[X];
	y = vec.coord[Y];
	z = vec.coord[Z];

	Matrix4 matrix(
		x*x*(1-c)+c		, x*y*(1-c)-z*s	, x*z*(1-c)+y*s	, 0,
		y*x*(1-c)+z*s	, y*y*(1-c)+c	, y*z*(1-c)-x*s	, 0,
		x*z*(1-c)-y*s	, y*z*(1-c)+x*s	, z*z*(1-c)+c	, 0,
		0				, 0				, 0				, 1);
    *this *= matrix;
}
template <class T>
void Matrix4<T>::initRotateMatrix(T rad, T x, T y, T z){
	T c = cos(rad);
	T s = sin(rad);

	Vector4<T> vec(x,y,z,0);
	vec.normalize();

	x = vec.coord[X];
	y = vec.coord[Y];
	z = vec.coord[Z];

	Matrix4 matrix(
		x*x*(1-c)+c		, x*y*(1-c)-z*s	, x*z*(1-c)+y*s	, 0,
		y*x*(1-c)+z*s	, y*y*(1-c)+c	, y*z*(1-c)-x*s	, 0,
		x*z*(1-c)-y*s	, y*z*(1-c)+x*s	, z*z*(1-c)+c	, 0,
		0				, 0				, 0				, 1);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getRotateMatrix(T rad, T x, T y, T z){
	T c = cos(rad);
	T s = sin(rad);

	Vector4<T> vec(x,y,z,0);
	vec.normalize();

	x = vec.coord[X];
	y = vec.coord[Y];
	z = vec.coord[Z];

	Matrix4 matrix(
		x*x*(1-c)+c		, x*y*(1-c)-z*s	, x*z*(1-c)+y*s	, 0,
		y*x*(1-c)+z*s	, y*y*(1-c)+c	, y*z*(1-c)-x*s	, 0,
		x*z*(1-c)-y*s	, y*z*(1-c)+x*s	, z*z*(1-c)+c	, 0,
		0				, 0				, 0				, 1);
    return matrix;
}

// ----------------------------------------------------------
// Projection Matrices
template <class T>
void Matrix4<T>::initProjectionOrthogonal(T left, T right, T bottom, T top, T zNear, T zFar){
	T tx = -((right+left)/(right-left));
	T ty = -((top+bottom)/(top-bottom));
	T tz = -((zFar+zNear)/(zFar-zNear));

	Matrix4 matrix(
		2.0f/(right-left)	, 0					, 0					, tx			,
		0					, 2.0f/(top-bottom)	, 0					, ty			,
		0					, 0					, -2.0f/(zFar-zNear), tz			,
		0					, 0					, /*-1.0f*/0		, 1.0f			);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getInitProjectionOrthogonal(T left, T right, T bottom, T top, T zNear, T zFar){
	T tx = -((right+left)/(right-left));
	T ty = -((top+bottom)/(top-bottom));
	T tz = -((zFar+zNear)/(zFar-zNear));

	Matrix4 matrix(
		2.0f/(right-left)	, 0					, 0					, tx			,
		0					, 2.0f/(top-bottom)	, 0					, ty			,
		0					, 0					, -2.0f/(zFar-zNear), tz			,
		0					, 0					, /*-1.0f*/0		, 1.0f			);
    return matrix;
}
template <class T>
void Matrix4<T>::initProjectionPerspective(T left, T right, T bottom, T top, T zNear, T zFar){
	Matrix4 matrix(
		(2.0f*-(zNear))/(right-left), 0								, (right+left)/(right-left)					, 0												,
		0							, (2.0f*-(zNear))/(top-bottom)	, (top+bottom)/(top-bottom)					, 0												,
		0							, 0								, -(((-zFar)+(-zNear))/((-zFar)-(-zNear)))	, -((2.0f*(-zFar)*(-zNear))/((-zFar)-(-zNear)))	,
		0							, 0								, -1.0f										, 0												);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::getInitProjectionPerspective(T left, T right, T bottom, T top, T zNear, T zFar){
    Matrix4 matrix(
		(2.0f*(zNear))/(right-left)	, 0								, (right+left)/(right-left)				, 0											,
		0							, (2.0f*(zNear))/(top-bottom)	, (top+bottom)/(top-bottom)				, 0											,
		0							, 0								, -(((zFar)+(zNear))/((zFar)-(zNear)))	, -((2.0f*(zFar)*(zNear))/((zFar)-(zNear)))	,
		0							, 0								, -1.0f									, 0											);
    return matrix;
}
template <class T>
void Matrix4<T>::initProjectionOtherPerspective(T left, T right, T bottom, T top, T zNear, T zFar){
	T tx = -((right+left)/(right-left));
	T ty = -((top+bottom)/(top-bottom));
	T tz = -((zFar+zNear)/(zFar-zNear));

	Matrix4 matrix(
		2.0f/(right-left)	, 0					, 0					, tx			,
		0					, 2.0f/(top-bottom)	, 0					, ty			,
		0					, 0					, -2.0f/(zFar-zNear), tz			,
		0					, 0					, -1.0f     		, 1.0f			);
    *this = matrix;
}

// ----------------------------------------------------------
// Transpose

template <class T>
void Matrix4<T>::transpose(){
	Matrix4 matrix(
		coord[0], coord[1], coord[2], coord[3],
		coord[4], coord[5], coord[6], coord[7],
		coord[8], coord[9], coord[10], coord[11],
		coord[12], coord[13], coord[14], coord[15]);
    *this = matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::transposed(){
	Matrix4 matrix(
		coord[0], coord[1], coord[2], coord[3],
		coord[4], coord[5], coord[6], coord[7],
		coord[8], coord[9], coord[10], coord[11],
		coord[12], coord[13], coord[14], coord[15]);
    return matrix;
}
template <class T>
Matrix4<T> Matrix4<T>::operator ~(){
	Matrix4 matrix(
		coord[0], coord[1], coord[2], coord[3],
		coord[4], coord[5], coord[6], coord[7],
		coord[8], coord[9], coord[10], coord[11],
		coord[12], coord[13], coord[14], coord[15]);
    return matrix;
}

// ----------------------------------------------------------
// Inverse

template <class T>
T Matrix4<T>::getDeterminant(){
	T	 dst[16];
	T    src[16];
	T    tmp[12];
	for (int i = 0; i < 4; i++) {
		src[i]        = coord[i*4];
		src[i + 4]    = coord[i*4 + 1];
		src[i + 8]    = coord[i*4 + 2];
		src[i + 12]   = coord[i*4 + 3];
	}

	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];

	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];

	return (src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3]);
}

/** I did not write these inverse functions myself.
  * It was found at ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
  * 2012-10-04, it says:
  * "The following C code performs 4x4-matrix inversion with Cramer's Rule
  * (without Streaming SIMD Extensions)."*/
template <class T>
void Matrix4<T>::inverse(){
	T	 dst[16];
	T    tmp[12]; /* temp array for pairs                      */
	T    src[16]; /* array of transpose source matrix */
	T    det;     /* determinant                                  */
	/* transpose matrix */
	for (int i = 0; i < 4; i++) {
		src[i]        = coord[i*4];
		src[i + 4]    = coord[i*4 + 1];
		src[i + 8]    = coord[i*4 + 2];
		src[i + 12]   = coord[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];
	/* calculate first 8 elements (cofactors) */
	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dst[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dst[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dst[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dst[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];
	/* calculate second 8 elements (cofactors) */
	dst[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	det = 1/det;
	for (int j = 0; j < 16; j++){
		dst[j] *= det;
		coord[j] = dst[j];
	}
}

/** I did not write these inverse functions myself.
  * It was found at ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
  * 2012-10-04, it says:
  * "The following C code performs 4x4-matrix inversion with Cramer's Rule
  * (without Streaming SIMD Extensions)."*/
template <class T>
void Matrix4<T>::inverse(Matrix4& mat){
	T	 dst[16];
	T    tmp[12]; /* temp array for pairs                      */
	T    src[16]; /* array of transpose source matrix */
	T    det;     /* determinant                                  */
	/* transpose matrix */
	for (int i = 0; i < 4; i++) {
		src[i]        = mat.coord[i*4];
		src[i + 4]    = mat.coord[i*4 + 1];
		src[i + 8]    = mat.coord[i*4 + 2];
		src[i + 12]   = mat.coord[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];
	/* calculate first 8 elements (cofactors) */
	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dst[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dst[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dst[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dst[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];
	/* calculate second 8 elements (cofactors) */
	dst[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	det = 1/det;
	for (int j = 0; j < 16; j++){
		dst[j] *= det;
		mat.coord[j] = dst[j];
	}
}

/** I did not write these inverse functions myself.
  * It was found at ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
  * 2012-10-04, it says:
  * "The following C code performs 4x4-matrix inversion with Cramer's Rule
  * (without Streaming SIMD Extensions)."*/
template <class T>
void Matrix4<T>::inverse(Matrix4& mat, Matrix4& dest){
	T    tmp[12]; /* temp array for pairs                      */
	T    src[16]; /* array of transpose source matrix */
	T    det;     /* determinant                                  */
	/* transpose matrix */
	for (int i = 0; i < 4; i++) {
		src[i]        = mat.coord[i*4];
		src[i + 4]    = mat.coord[i*4 + 1];
		src[i + 8]    = mat.coord[i*4 + 2];
		src[i + 12]   = mat.coord[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];
	/* calculate first 8 elements (cofactors) */
	dest.coord[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dest.coord[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dest.coord[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dest.coord[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dest.coord[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dest.coord[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dest.coord[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dest.coord[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dest.coord[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dest.coord[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dest.coord[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dest.coord[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dest.coord[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dest.coord[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dest.coord[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dest.coord[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];
	/* calculate second 8 elements (cofactors) */
	dest.coord[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dest.coord[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dest.coord[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dest.coord[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dest.coord[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dest.coord[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dest.coord[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dest.coord[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dest.coord[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dest.coord[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dest.coord[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dest.coord[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dest.coord[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dest.coord[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dest.coord[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dest.coord[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	/* calculate determinant */
	det=src[0]*dest.coord[0]+src[1]*dest.coord[1]+src[2]*dest.coord[2]+src[3]*dest.coord[3];
	/* calculate matrix inverse */
	det = 1/det;
	for (int j = 0; j < 16; j++)
		dest.coord[j] *= det;
}

/** I did not write these inverse functions myself.
  * It was found at ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
  * 2012-10-04, it says:
  * "The following C code performs 4x4-matrix inversion with Cramer's Rule
  * (without Streaming SIMD Extensions)."*/
template <class T>
Matrix4<T> Matrix4<T>::inversed(){
	T	 dst[16];
	T    tmp[12]; /* temp array for pairs                      */
	T    src[16]; /* array of transpose source matrix */
	T    det;     /* determinant                                  */
	/* transpose matrix */
	for (int i = 0; i < 4; i++) {
		src[i]        = coord[i*4];
		src[i + 4]    = coord[i*4 + 1];
		src[i + 8]    = coord[i*4 + 2];
		src[i + 12]   = coord[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];
	/* calculate first 8 elements (cofactors) */
	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dst[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dst[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dst[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dst[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];
	/* calculate second 8 elements (cofactors) */
	dst[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	Matrix4 newMat;
	det = 1/det;
	for (int j = 0; j < 16; j++){
		dst[j] *= det;
		newMat.coord[j] = dst[j];
	}
	return newMat;
}

/** I did not write these inverse functions myself.
  * It was found at ftp://download.intel.com/design/PentiumIII/sml/24504301.pdf
  * 2012-10-04, it says:
  * "The following C code performs 4x4-matrix inversion with Cramer's Rule
  * (without Streaming SIMD Extensions)."*/
template <class T>
Matrix4<T> Matrix4<T>::inversed(Matrix4& mat){
	T	 dst[16];
	T    tmp[12]; /* temp array for pairs                      */
	T    src[16]; /* array of transpose source matrix */
	T    det;     /* determinant                                  */
	/* transpose matrix */
	for (int i = 0; i < 4; i++) {
		src[i]        = mat.coord[i*4];
		src[i + 4]    = mat.coord[i*4 + 1];
		src[i + 8]    = mat.coord[i*4 + 2];
		src[i + 12]   = mat.coord[i*4 + 3];
	}
	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];
	/* calculate first 8 elements (cofactors) */
	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dst[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dst[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dst[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dst[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];
	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];
	/* calculate second 8 elements (cofactors) */
	dst[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];
	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
	/* calculate matrix inverse */
	Matrix4 newMat;
	det = 1/det;
	for (int j = 0; j < 16; j++){
		dst[j] *= det;
		newMat.coord[j] = dst[j];
	}
	return newMat;
}

#endif