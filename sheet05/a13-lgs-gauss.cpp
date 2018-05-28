/*
 * Programmieren fuer Physiker, SS 2018, Blatt 5, Aufgabe 13
 *
 * Gauss-Algorithmus: Einlesen, Loesen, Ausgeben eines LGS
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std ;

int main()
{
    //
    // Teil 0. Deklarationen
    //
    char fname[30] ;
    char sp_input ;
    const int maxsize=20 ;
    double a[maxsize][maxsize] ; // Matrix
    double v[maxsize] ;          // rechte Seite
    double x[maxsize] ;          // Loesungsvektor
    int size ;                   // tatsaechliche Groesse
    bool pivotflg = true ; // Spaltenpivotisierung ja oder nein?

    //
    // Teil 1. Einlesen der Daten
    //
    cout << "Gauss-Demo" << endl ;
    cout << "File: " ;
    cin >> fname ;

    cout << "Spaltenpivotisierung (j/n)?" ;
    cin >> sp_input ;
    pivotflg = (sp_input=='j' || sp_input=='J') ;

    ifstream dfile(fname) ;
    if( !dfile)
    {
        cout << "Kann Datenfile nicht oeffnen. Stop." << endl ;
        exit(1) ;
    }
    dfile >> size ;
    if( size<0 || size>=maxsize)
    {
        cout << "Dimension " << size << " nicht moeglich. Stop." << endl ;
        exit(1) ;
    }
    for(int i=0; i<size; i++)
        for( int j=0; j<size; j++)
            dfile >> a[i][j] ;
    for(int i=0; i<size; i++)
        dfile >> v[i] ;
    dfile.close() ;

    //
    // Teil 2. Ausgeben des Problems
    //
    for(int i=0; i<size; i++)
    {
        cout << "[ " ;
        for( int j=0; j<size; j++)
        {
            cout << setw(9) << setprecision(3) << a[i][j] ;
        }
        cout << " ] [ x" << setw(1) << i << " ] " ;
        if( i==int(size/2.0)) cout << " = " ;
        else cout << "   " ;
        cout << "[ " << setw(8) << v[i] << " ]" << endl ;
    }

    //
    // Teil 3. Dreiecksform
    //
    // aeussere Schleife: gehe alle Zeilen ab
    for(int i=0; i<size; i++)
    {
        if (pivotflg) 	// Falls Spalten-Pivotisierung...
        {
            // Finde maximales Elemente in Spalte unter (i,i)
            int maxind = i ;
            for(int j=i+1; j<size; j++)
                if (abs(a[j][i])>abs(a[maxind][i]))
                    maxind=j ;
            // maxind ist nun Zeilenindex des Pivotelements
            // Tausche die beiden Zeilen und die rechte Seite
            //    (eigentlich besser: nicht Tauschen und in einem Feld
            //     die Permutation der Zeilen aufbewahren)
            for( int j=0; j<size; j++)
            { double tmp=a[i][j] ; a[i][j]=a[maxind][j] ; a[maxind][j]=tmp ; }
            double tmp=v[i] ; v[i]=v[maxind] ; v[maxind]=tmp ;
        }

        if (a[i][i] == 0) // evtl besser: abs(...) < epsilon
        {
            cout << "Problem: eine Null auf Diagonale..." << endl ;
            cout << "Falls Spaltenpivotisierung: LGS nicht eindeutig "
                << "lösbar oder es gibt keine Lösung. Stop." << endl ;
            exit(1) ;
        }

        // Eintraege unterhalb (i,i) eliminieren
        // arbeite zeilenweise durch Zeilen j mit j>i
        for(int j=i+1; j<size; j++)
        {
            // addiere geeignetes Vielfaches der Zeile i zur Zeile j
            double fak = a[j][i]/a[i][i] ;
            for( int k=i; k<size; k++)
                a[j][k] -= fak * a[i][k] ;
            v[j] -= fak*v[i] ;
        }
    }

    //
    // Teil 4. Rueckwaerts einsetzen
    //
    for(int i=size-1; i>=0; i--)
    {
        x[i] = v[i] ;
        for( int j=i+1; j<size; j++)
            x[i] -= a[i][j]*x[j] ;
        x[i] /= a[i][i] ;
    } ;

    //
    // Teil 5. Ergebnisvektor ausgeben
    //
    cout << endl ;
    cout << "Loesungsvektor: " << endl ;
    cout << " [ " ;
    for( int i=0; i<size; i++)
    {
        if( 0!=i) cout << ", " ;
        cout << setw(6) << setprecision(3) << x[i] ;
    }
    cout << " ]" << endl ;
}
