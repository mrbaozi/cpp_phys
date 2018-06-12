
/*
 * Programmieren fuer Physiker, SS 2018, Blatt 7, Aufg. 17
 *
 * Kubische Splines, normale Randbedingungen
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std ;

int main()
{
    //
    // Teil 0. Deklarationen
    //
    char fname[30] ;
    const int maxsize=300 ;
    double x[maxsize] ;
    double f[maxsize] ;
    double mu[maxsize], lambda[maxsize], d[maxsize] ;
    double m[maxsize] ;
    double alpha[maxsize], beta[maxsize], gamma[maxsize], delta[maxsize] ;

    //
    // Teil 1. Einlesen der Daten
    //
    cout << "Kubische-Spline-Interpolation" << endl ;
    cout << "Datei mit Daten: " ;
    /* cin >> fname ; */

    ifstream dfile("./a16-interpol.dat") ;
    if( !dfile)
    {
        cout << "Kann Datenfile nicht oeffnen. Stop." << endl ;
        exit(1) ;
    }
    int size=0 ;
    while ((dfile >> x[size] >> f[size]))
    {
        cout << "Punkt (x,f(x)): " << x[size] << " " << f[size] << endl ;
        ++size ;
    }
    dfile.close() ;
    cout << "Anzahl der Punkte: " << size << endl ;
    // remember: "size-1" entspricht "n"

    //
    // Teil 2. Spline berechnen
    //
    // 2.1 LGS fuer m aufsetzen
    for (int i=1; i<size-1; ++i)
    {
	lambda[i] = (x[i+1] - x[i]) / (x[i+1] - x[i-1]) ;
	mu[i] =    (x[i] - x[i-1])   / (x[i+1] - x[i-1]) ;
	d[i] = 6.0/(x[i+1]-x[i-1]) *
	    ( (f[i+1]-f[i])/(x[i+1] - x[i]) - (f[i]-f[i-1])/(x[i]-x[i-1])) ;
    }
    lambda[0] = 0 ;
    mu[size-1] = 0 ;
    d[0] = d[size-1] = 0 ;

    // 2.2 LGS fuer m loesen
    mu[0] = 2.0 ;
    for (int k=1; k<size; ++k)
    {
	double f = -mu[k]/mu[k-1] ;
	mu[k] = 2 + f*lambda[k-1] ;
	d[k] += f*d[k-1] ;
    }

    m[size-1] = d[size-1]/mu[size-1] ;
    for (int k=size-2; k>=0; --k)
	m[k] = (d[k] - lambda[k]*m[k+1])/mu[k] ;

    // 2.3 abschinttsweise Koeffizienten explizit
    for( int j=0; j<size-1; ++j)
    {
	alpha[j] = f[j] ;
	gamma[j] = m[j]/2.0 ;
	beta[j] = (f[j+1]-f[j])/(x[j+1] - x[j])
	    - (2.0*m[j] + m[j+1])*(x[j+1]-x[j])/6.0 ;
	delta[j] = (m[j+1] - m[j])/(6.0*(x[j+1]-x[j])) ;
    cout << "alpha_" << j << ": " << alpha[j] << " ";
    cout << "beta_" << j << ": " << beta[j] << " ";
    cout << "gamma_" << j << ": " << gamma[j] << " ";
    cout << "delta_" << j << ": " << delta[j] << endl;
    }

    //
    // 3. Funktionswerte ausrechnen und in Datei schreiben
    //
    ofstream efile("a17-spline-res.dat") ;
    if( !efile)
    {
        cout << "Kann Ergebnisfile nicht oeffnen. Stop." << endl ;
        exit(1) ;
    }

    for (double xstar=x[0]; xstar<=x[size-1];
	     xstar += (x[size-1] - x[0]) / 300.0)
    {
	int j = size-1 ; // suche Intervall ... (besser waere Bisektion)
	while (j>=1 and xstar < x[j])
	    --j ;

	double xd = xstar - x[j] ;
	double fstar =
	    ((delta[j]*xd + gamma[j]) * xd + beta[j]) * xd + alpha[j] ;
	efile << xstar << "  " << fstar << endl ;
    }
    efile.close() ;
}

