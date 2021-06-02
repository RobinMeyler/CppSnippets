#ifndef MYVECTOR3 
#define MYVECTOR3


/// Name: Robin Meyler


#include <iostream>
#include <string>
//#include <SFML/Graphics.hpp>


class MyVector3
{
public:
	double x;
	double y;
	double z;

	/// <summary>
	/// default destructor
	/// nothing to release because we only have
	/// primitive type data
	/// </summary>
	MyVector3();
	~MyVector3();
	
	/// <summary>
	/// Setting up the a string
	/// </summary>
	std::string toString();

	/// Defautl constructor set all 3 values to zero
	/// </summary>
	MyVector3(double x, double y, double z);
	
	/// 
	/// Construtors for:
	/// 3f, 3i, 2u, 2i, 2f
	/// </summary>

	///  Check for equality
	///  Check for inequality
	/// 
	/// </summary>
	bool operator == (const MyVector3 t_right) const;
	bool operator != (const MyVector3 t_right) const;

	/// Basic operations:
	/// Addition, Subtraction, Multiplication, Divison
	/// Plus equals, Minus equals
	/// </summary>
	MyVector3 operator +(const MyVector3 t_right) const;
	MyVector3 operator -(const MyVector3 t_right) const;
	MyVector3 operator *(const double t_scalar) const;
	MyVector3 operator /(const double t_divisor) const;
	MyVector3 operator +=(const MyVector3 t_right);
	MyVector3 operator -=(const MyVector3 t_right);

	/// Negative of a vector
	/// </summary>
	MyVector3 operator -();

	/// Length
	/// LengthSquared
	/// </summary>
	double length()const;
	double lengthSquared()const;
	
	
	/// The sum of the product of the components of the vectors
	/// </summary>
	double dot(const MyVector3 t_other) const;
	
	/// Cross product of two vectors
	MyVector3 crossProduct(const MyVector3 t_other)const;
	
	/// Angle between two vectors in degrees
	/// </summary>
	double angleBetween(const MyVector3 t_other)const;
	
	
	
	/// Unit vector of a vector
	/// Changing a vector to it's unit vector
	/// </summary>
	MyVector3 unit() const;
	void normalise();
	
	
	/// Projection of on vector onto another
	/// Rejection left after a projection
	/// </summary>
	MyVector3 projection(const MyVector3 t_other)const;
	MyVector3 rejection(const MyVector3 t_other)const;
	void reverseX() ;
	void reverseY() ;

};



#endif // !MYVECTOR3