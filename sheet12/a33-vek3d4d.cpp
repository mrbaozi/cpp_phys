/*
 * Programmieren fuer Physiker, SS 2018, Blatt 12, Aufgabe 33
 *
 * 3D -> 4D Vektoren, Vererbung
 */


#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std ;

// ------------------------------------- VEC 3D

class Vec3D
{
public:
    Vec3D() {} ;
    Vec3D(double x_, double y_, double z_)
	: x(x_), y(y_), z(z_)
	{ } ;
    double getx() { return x ; } ;
    double gety() { return y ; } ;
    double getz() { return z ; } ;
    double len_sq() { return x*x + y*y + z*z ; } ;
    double angle(Vec3D v2) ;
protected:
    double x,y,z ;
} ;

double Vec3D::angle( Vec3D v2)
{
    double skapro = x*v2.x + y*v2.y + z*v2.z ;
    double normpro = sqrt(v2.len_sq() * len_sq()) ;
    return (normpro!=0 ? acos(skapro/normpro) : 0 ) ;
}

// ------------------------------------- VEC 4D

class Vec4D : public Vec3D
{
public:
    Vec4D() {} ;
    Vec4D(double t_, double x_, double y_, double z_)
	: Vec3D(x_,y_,z_), t(t_)
	{ } ;
    double gett() { return t ; } ;
    // double len_sq() { return sqrt(t*t - x*x - y*y - z*z) ; } ;
    double len_sq() { return t*t - Vec3D::len_sq() ; } ;
protected:
    double t ;
} ;

// ------------------------------------- MAIN

int main()
{
    Vec4D v1 (3.0, 0.0, 1.0, 0.0) ;
    Vec4D v2 (4.0, 0.0, 1.0, 1.0) ;
    cout << "Minkowski-Laengenquadrat v1 : " << v1.len_sq() << endl ;
    cout << "Minkowski-Laengenquadrat v2 : " << v2.len_sq() << endl ;
    cout << "Winkel (im Bogenmass) zwischen v1 und v2 : "
	 << v1.angle(v2) << endl ;
}
