#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool is_prime(int n)
{
    if (n <= 3)
    {
        return n > 1;
    }

    for (int ii = 5; ii * ii <= n; ii += 2)
    {
        if (n % ii == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    long input;
    cout << "Input: " << endl;
    cin >> input;

    bool Zahlen[eingabe];

    for (int i  =  2; i < eingabe; i++){
        Zahlen[i] = true;
    }
    Zahlen[0] = false;
    Zahlen[1] = false;

    for(int n = 3; n<eingabe; n++){
        for(int i = 2; i<n; i++){
            if (n%i == 0){
                Zahlen[n]  =  false;
                break;
            }
        }
    }

    int l = 0;
    int prim[l];
    int p = 0;

    for(int n = 0; n<eingabe; n++){
        if(Zahlen[n]) {
            l++;
            cout << l << "-te Zahl: " << n << endl;
            prim[p] = n;
            p++;

        }
    }
    cout << "Anzahl: " << l << endl;

    int kombzahl = 0;
    int test  =  0;
    for(int i = 0;i<l; i++){
        test = eingabe-prim[i];
        for(int j = 0;j<l;j++){
            if(test == prim[j]){
                kombzahl++;
                cout << "Moeglichkeit " << kombzahl << ": " << test << " + " << prim[i] <<"  =  " << eingabe << endl;
            }
        }
    }
    cout << kombzahl << " Kombinationen" << endl;

    return 0;
}
