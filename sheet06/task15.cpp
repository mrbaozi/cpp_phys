#include <iostream>
#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, const char **argv)
{
    cout << "Aufgabe 15: Abzählreim - wer geht, wer bleibt?\n" << endl;

    int n {0};  // players
    int k {0};  // syllables
    if (argc < 3)
    {
        cout << "Input: ";
        cin >> n >> k;
    }
    else
    {
        n = atof(argv[1]);
        k = atof(argv[2]);
    }
    assert(n > 0);
    assert(k > 0);

    vector<bool> players;
    for (int ii = 0; ii < n; ++ii)
    {
        players.emplace_back(true);
    }

    int idx = n - 1;
    for (int lost = 0; lost < n; ++lost)
    {
        for (int steps = 0; steps < k; ++steps)
        {
            do
            {
                idx = (idx + 1) % n;
            }
            while (!players[idx]);
        }
        players[idx] = false;
        if (lost < n - 1)
        {
            cout << "Spieler " << idx + 1 << " geht." << endl;
        }
    }

    cout << "Spieler " << idx + 1 << " bleibt." << endl;

    return 0;
} //main
