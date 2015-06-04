// vec.cpp - implements Vec3 functions
// YOUR NAME(s), DATE

#include <iostream>
#include "vec.h"
using namespace std;

// constructors done
Vec3::Vec3() : x(0), y(0), z(0) { }
Vec3::Vec3(double x, double y, double z) : x(x), y(y), z(z) { }
/* Do not modify the following line. If you see the message "Pass by value
   fail." in your output, it means you aren't using a reference somewhere
   that you should be. */
Vec3::Vec3(const Vec3 &other) { cout << "Pass by value fail."; }

// getters and setters done
double Vec3::get_x() const { return x; }
double Vec3::get_y() const { return y; }
double Vec3::get_z() const { return z; }
void Vec3::set_x(double value) { x = value; }
void Vec3::set_y(double value) { y = value; }
void Vec3::set_z(double value) { z = value; }

// YOUR WORK GOES HERE
ostream& operator<< (ostream &out, const Vec3 &Vec)
{
	out << "(" << Vec.x << "," << Vec.y << "," << Vec.z << ")";
	return out;
}

istream& operator>> (istream &in, Vec3 &Vec)
{
	in >> Vec.x;
	in >> Vec.y;
	in >> Vec.z;

	return in;

}

Vec3 operator+ (const Vec3 &Vec0, const Vec3 &Vec1)
{
	double x = Vec0.x + Vec1.x;
	double y = Vec0.y + Vec1.y;
	double z = Vec0.z + Vec1.z;
	
	return Vec3(x, y, z);
}

Vec3 operator* (const Vec3 &Vec0, const int n)
{
	double x = Vec0.x * n;
	double y = Vec0.y * n;
	double z = Vec0.z * n;
	
	return Vec3(x,y,z);
	
}

Vec3 operator+= (Vec3 &Vec0, const Vec3 &Vec1)
{
	double x = Vec0.x + Vec1.x;
	double y = Vec0.y + Vec1.y;
	double z = Vec0.z + Vec1.z;
	
	Vec0.set_x(x);
	Vec0.set_y(y);
	Vec0.set_z(z);

	return Vec3(x,y,z);
}

Vec3 operator++ (Vec3 &Vec0)
{
	double x = Vec0.x + 1.0;
	double y = Vec0.y + 1.0;
	double z = Vec0.z + 1.0;
	
	Vec0.set_x(x);
	Vec0.set_y(y);
	Vec0.set_z(z);

	return Vec3(x,y,z);
}

Vec3 operator++ (Vec3 &Vec0, int n)
{
	double x = Vec0.x;
	double y = Vec0.y;
	double z = Vec0.z;
	
	Vec0.set_x(x+1.0);
	Vec0.set_y(y+1.0);
	Vec0.set_z(z+1.0);

	return Vec3(x,y,z);

}

Vec3& Vec3::operator=(Vec3 &Vec0, const Vec3 &Vec0) const
{
	
	
}

double Vec3::operator[] (int n) const

{
	if (n==0)
		return x;
	if (n==1)
		return y;
	if (n==2)
		return z;

	
}

double& Vec3::operator[] (int n)

{
	if (n==0)
		return x;
	if (n==1)
		return y;
	if (n==2)
		return z;

	
}






	
