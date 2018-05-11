#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int collatz(int a, vector<int>& results)
{
    results.push_back(a);
    if (a == 1)
    {
        return results.size();
    }
    if (a % 2 == 0)
    {
        return collatz(a / 2, results);
    }
    else
    {
        return collatz(3 * a + 1, results);
    }
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 10: 3n+1 - Problem\n" << endl;

    int a {0};
    vector<int> collatz_results;
    if (argc < 2)
    {
        vector<int> lengths;
        for (int a = 2; a < 100; ++a)
        {
            lengths.push_back(collatz(a, collatz_results));
            collatz_results.clear();
        }
        a = distance(lengths.begin(), max_element(lengths.begin(), lengths.end())) + 2;
        cout << "Longest sequence for a = " << a << endl;
    }
    else
    {
        a = atoi(argv[1]);
        assert(a > 1);
        cout << "Start value: " << a << endl;
    }

    collatz(a, collatz_results);

    cout << "Length of sequence: " << collatz_results.size() << endl;
    cout << "Maximum value: ";
    cout << *max_element(collatz_results.begin() + 1, collatz_results.end()) << endl;

    return 0;
} //main
