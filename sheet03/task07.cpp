#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>

using namespace std;

int main(int argc, const char **argv)
{
    cout << "Aufgabe 7: Kubische Gleichung\n" << endl;

    double a, b, c, d;
    if (argc < 2)
    {
        cout << "Input: ";
        cin >> a >> b >> c >> d;
    }
    else
    {
        a = atof(argv[1]);
        b = atof(argv[2]);
        c = atof(argv[3]);
        d = atof(argv[4]);
    }

    double p {(3. * a * c - b * b) / (3. * a * a)};
    double q {(2. * b * b * b) / (27. * a * a * a) - (b * c) / (3. * a * a) + d / a};
    double D {(q * q / 4.) + (p * p * p / 27.)};

    double eps {numeric_limits<double>::epsilon()};

    cout << "D = " << D << endl;

    if (D > eps)
    {
        cout << "D > 0: Einfache reelle Lösung x1" << endl;
        double D1 {cbrt(-q / 2. + sqrt(D))};
        double D2 {cbrt(-q / 2. - sqrt(D))};
        double x1 {D1 + D2 - b / (3. * a)};
        cout << "x1 = " << x1 << endl;
    }
    if (abs(D) <= eps)
    {
        if (abs(q) <= eps)
        {
            cout << "D = 0, q = 0: Dreifache reelle Lösung x1" << endl;
            double x1 {-b / (3. * a)};
            cout << "x1 = " << x1 << endl;
        }
        else
        {
            cout << "D = 0, q != 0: Doppelte Nullstelle x1 und einfache Nullstelle x2" << endl;
            double x1 {cbrt(q / 2.) - b / (3. * a)};
            double x2 {cbrt(-4. * q) - b / (3. * a)};
            cout << "x1 = " << x1 << endl;
            cout << "x2 = " << x2 << endl;
        }
    }
    if (D < -eps)
    {
        cout << "D < 0: Drei einfache reelle Nullstellen" << endl;
        double h {acos(-q / 2. * sqrt(-27. / (p * p * p)))};
        double x1 {-sqrt(-4. * p / 3.) * cos(h / 3. + M_PI / 3.) - b / (3. * a)};
        double x2 {-sqrt(-4. * p / 3.) * cos(h / 3. - M_PI / 3.) - b / (3. * a)};
        double x3 {sqrt(-4. * p / 3.) * cos(h / 3.) - b / (3. * a)};
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    }

    return 0;
} //main
