#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char **argv)
{
    cout << "Aufgabe 10: 3n+1 - Problem\n" << endl;

    double x;
    if (argc < 2)
    {
        cout << "Input: ";
        cin >> x;
    }
    else
    {
        x = atof(argv[1]);
    }

    return 0;
} //main
