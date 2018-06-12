#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

double f1(double x)
{
    return (cos(x) - x);
}

double f2(double x)
{
    return (exp(x) - pow(x, 3));
}

double nullstelle(
        double f(double),
        double x0, double x1,
        double eps_interval, double eps_function)
{
    double x_test, f_test;
    int its = 0;
    do
    {
        ++its;
        x_test = (x0 + x1) / 2.;
        f_test = f(x_test);

        cout << "Schritt: " << its << endl;
        cout << "Intervall: x0 = " << x0 << ", x1 = " << x1 << endl;
        cout << "f(" << x_test << ") = " << f_test << endl << endl;

        (f_test * f(x0) > 0) ? x0 = x_test : x1 = x_test;
        x_test = (x0 + x1) / 2.;
    }
    while (abs(x0 - x1) >= eps_interval && abs(f_test) >= eps_function);

    return x_test;
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 19: Nullstellenbestimmung\n" << endl;

    string fun;
    double x0, x1, eps1, eps2;
    if (argc < 6)
    {
        cout << "Funktion (f1, f2): ";
        cin >> fun;
        cout << "x0: ";
        cin >> x0;
        cout << "x1: ";
        cin >> x1;
        cout << "eps (interval): ";
        cin >> eps1;
        cout << "eps (function): ";
        cin >> eps2;
    }
    else
    {
        fun = argv[1];
        x0 = atof(argv[2]);
        x1 = atof(argv[3]);
        eps1 = atof(argv[4]);
        eps2 = atof(argv[5]);
    }

    double result;
    if (fun == "f1")
    {
        result = nullstelle(f1, x0, x1, eps1, eps2);
    }
    if (fun == "f2")
    {
        result = nullstelle(f2, x0, x1, eps1, eps2);
    }

    cout << "Nullstelle bei x = " << result << endl;

    return 0;
} //main
