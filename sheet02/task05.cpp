#include <iostream>
#include <cstdlib>

using namespace std;

double pair_n(int n)
{
    if (n == 0) return 1.;
    return (1. + static_cast<double>(n) / (2. * static_cast<double>(n) + 1.) * pair_n(n - 1));
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 5: Von Innen nach Außen\n" << endl;

    int pairs;
    if (argc < 2)
    {
        cout << "Input: ";
        cin >> pairs;
    }
    else
    {
        pairs = atoi(argv[1]);
    }

    cout << "p(" << pairs << ") = " << pair_n(pairs) << endl;
    cout << "2p(" << pairs << ") = " << 2. * pair_n(pairs) << endl;

    return 0;
} //main
