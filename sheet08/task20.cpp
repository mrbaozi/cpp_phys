/*
 * Programmieren fuer Physiker, SS 2018, Blatt 8, Aufgabe 20
 *
 * Struct fuer Rechteck
 */

#include <iostream>

using namespace std ;

struct rechteck
{
    float x, y;
};

bool bedeckt(rechteck r1, rechteck r2)
{
    return (r1.x >= r2.x && r1.y >= r2.y);
}

rechteck rotation(rechteck r1)
{
    return {r1.y, r1.x};
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 20: Rechteck-Struct\n" << endl;
    rechteck r1 = {3.3, 2.0} ;
    rechteck r2 = {1.8, 2.7} ;

    cout << "Vor Rotation: " ;
    if (bedeckt(r1,r2))	cout << "r1 bedeckt r2." ;
    else cout << "r1 bedeckt r2 nicht." ;
    cout << endl ;

    rechteck r3 = rotation(r2) ;

    cout << "Nach Rotation: " ;
    if (bedeckt(r1,r3))	cout << "r1 bedeckt r3." ;
    else cout << "r1 bedeckt r3 nicht." ;
    cout << endl ;
}
