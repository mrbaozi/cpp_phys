#include <cassert>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char **argv)
{
    cout << "Aufgabe 11: Drei kreuz drei\n" << endl;

    assert(argc > 1);
    string file_name {argv[1]};

    ifstream file {file_name};
    assert(file.is_open());

    // Input
    double mat[3][3];
    for (int ii = 0; ii < 3; ++ii)
    {
        for (int jj = 0; jj < 3; ++jj)
        {
            file >> mat[ii][jj];
        }
    }
    file.close();

    // Determinant (Sarrus)
    double det {0};
    for (int ii = 0; ii < 3; ++ii)
    {
        double pr1 {1};
        double pr2 {1};
        for (int jj = 0; jj < 3; ++jj)
        {
            pr1 *= mat[jj][(ii + jj) % 3];
            pr2 *= mat[jj][(ii + 3 - jj) % 3];
        }
        det += pr1 - pr2;
    }

    // Norm
    double norm {0};
    for (int jj = 0; jj < 3; ++jj)
    {
        double sum {0};
        for (int ii = 0; ii < 3; ++ii)
        {
            sum += abs(mat[ii][jj]);
        }
        if (sum >= norm)
        {
            norm = sum;
        }
    }

    // Output
    cout << "Matrix: " << endl;
    for (int ii = 0; ii < 3; ++ii)
    {
        for (int jj = 0; jj < 3; ++jj)
        {
            cout << setw(6) << mat[ii][jj];
        }
        cout << endl;
    }
    cout << "Determinante: " << det << endl;
    cout << "Spaltensummennorm: " << norm << endl;

    return 0;
} //main
