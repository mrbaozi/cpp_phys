/*
 * Das hier ist die meiner Meinung nach im Klausurkontext optimale Loesung der
 * Aufgabe.
 * Das Programm ist logisch aufgebaut, leicht nachvollziehbar (die Korrektoren
 * werden es euch danken) und tut genau das was es soll.
 * Man kann diskutieren ob die Funktion noetig ist oder ob man den Primzahltest
 * nicht auch einfach in die main() packen kann - ich finde es so besser.
 * Beides ist aber voellig in Ordnung.
 */

#include <iostream>

using namespace std;

bool is_prime(int n)
{
    for (int i = 2; i < n; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main()
{
    int input;
    cin >> input;

    for (int i = 2; i <= input / 2; ++i)
    {
        if (is_prime(i) && is_prime(input - i))
        {
            cout << i << " + " << input - i << endl;
        }
    }
}
