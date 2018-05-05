#include <iostream>
#include <cstdlib>

using namespace std;

float dsum(int n)
{
    float sum {0};
    for (int ii = 1; ii <= n; ++ii)
    {
        for (int jj = 1; jj <= ii; ++jj)
        {
            sum += 1.0f / static_cast<float>(ii * jj);
        }
    }
    return sum;
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 4: Doppelsumme\n" << endl;

    int N;
    if (argc < 2)
    {
        cout << "Input: ";
        cin >> N;
    }
    else
    {
        N = atoi(argv[1]);
    }

    cout << "S(" << N << ") = " << dsum(N) << endl;

    return 0;
} //main
