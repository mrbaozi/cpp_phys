/*
 * Programmieren fuer Physiker, SS 2018, Blatt 12, Aufgabe 32
 *
 * Pointer-Jongliererei:
 * Demo fuer: Pointer, ++ Pre-/Postfix, Operatorprioritaet
 */

#include <iostream>
using namespace std ;

int main()
{
    char zeile[] = "Ist das ein Stuss!" ;
    char* p = zeile ;
    while (*p++ != 'S') ;
    --------*p ;
    *++p = *(zeile+5) ;
    cout << zeile << endl ;
}
