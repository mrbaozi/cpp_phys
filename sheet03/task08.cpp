#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

unsigned binom(unsigned n, unsigned k)
{
    if (k == 0) { return 1; }
    if (2 * k > n) { k = n - k; }

    unsigned result {1};

    for (unsigned ii = 1; ii <= k; ++ii)
    {
        result = result * (n - k + ii) / ii;
    }

    return result;
}

unsigned width(unsigned x)
{
    unsigned count {0};
    for(; x != 0; x /= 10) { ++count; }
    return count;
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 8: Binomialkoeffizienten\n" << endl;

    unsigned rows;
    if (argc < 2)
    {
        cout << "Input: ";
        cin >> rows;
    }
    else
    {
        rows = atoi(argv[1]);
    }

    unsigned space {width(binom(rows, rows / 2)) + 1};

    for (unsigned row = 0; row < rows; ++row)
    {
        cout << setw(space * (rows - row) / 2) << binom(row, 0);
        for (unsigned element = 1; element <= row; ++element)
        {
            cout << setw(space) << binom(row, element);
        }
        cout << endl;
    }

    return 0;
} //main
