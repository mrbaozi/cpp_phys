#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, const char **argv)
{
    cout << "Aufgabe 11: Drei kreuz drei\n" << endl;

    assert(argc > 1);
    string file_name {argv[1]};

    ifstream file {file_name};
    assert(file.is_open());

    vector<double> mat;
    double num {0};
    while (file >> num)
    {
        mat.emplace_back(num);
    }

    for (auto const& val: mat)
    {
        cout << val << endl;
    }

    return 0;
} //main
