#include <iostream>

using namespace std;

int main(){
    cout << "Bitte eine Zahl eingeben" << endl;
    long eingabe;
    cin >> eingabe;

    bool* Zahlen = new bool[eingabe];

    Zahlen[0] = false;
    Zahlen[1] = false;
    Zahlen[2] = true;

    for (int n = 3; n < eingabe; n++)
    {
        Zahlen[n] = true;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                Zahlen[n] = false;
                break;
            }
        }
    }

    int kombzahl = 0;

    for (int i = 0; i <= eingabe / 2; ++i)
    {
        if (Zahlen[i] && Zahlen[eingabe - i])
        {
            kombzahl++;
            cout << "Moeglichkeit " << kombzahl << ": " << i << " + "
                << eingabe - i << " = " << eingabe << endl;
        }
    }

    return 0;
}
