#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include <string>

using namespace std;

double lagrange(const double xi, const vector<double>& x, const vector<double>& f)
{
    double result {0};
    for (size_t ii = 0; ii < x.size(); ++ii)
        {
            double prod = f[ii];
            for (size_t jj = 0; jj < x.size(); ++jj)
            {
                if (ii != jj)
                {
                    prod *= (xi - x[jj]) / (x[ii] - x[jj]);
                }
            }
            result += prod;
        }
    return result;
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 16: Polynom-Interpolation\n" << endl;

    ifstream ifile {argv[1]};
    assert(ifile.is_open());

    vector<double> x;
    vector<double> f;
    {
        double xi {0};
        double yi {0};
        while (ifile >> xi >> yi)
        {
            x.push_back(xi);
            f.push_back(yi);
            cout << "f(" << xi << ") = " << yi << endl;
        }
    }
    ifile.close();
    assert(x.size() == f.size());

    cout << "\nInsgesamt " << x.size() << " Datenpunkte\n" << endl;

    ofstream ofile {argv[2]};
    assert(ofile.is_open());

    while (true)
    {
        double z {0};
        cout << "Stützstelle angeben:" << endl;
        cin >> z;
        if (z == 0) break;
        double interp = lagrange(z, x, f);
        ofile << z << " " << interp << endl;
        cout << "f(z) = " << interp << endl;
    }
    ofile.close();

    /* // Generate output for plotting (sample data range) */
    /* for (int z = -30; z <= 30; ++z) */
    /* { */
    /*     double interp = lagrange(static_cast<double>(z) / 10., x, f); */
    /*     ofile << static_cast<double>(z) / 10. << " " << interp << endl; */
    /*     cout << "f(z) = " << interp << endl; */
    /* } */
    /* ofile.close(); */

    return 0;
} //main
