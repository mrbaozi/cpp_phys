#include <iostream>
#include <cmath>     // warum?

using namespace std;

int main(){
    cout << "Bitte eine Zahl eingeben" << endl;
    long eingabe;
    cin >> eingabe;

    /*
     * Arrays, deren Größe zur Kompilierzeit nicht bekannt sind, sind laut
     * C++-Standard nicht erlaubt und führen zu undefiniertem Verhalten.
     * GCC (und damit g++) erlaubt diese Art der Initialisierung
     * als "feature". Andere Compiler i.d.R. nicht (z.B. clang).
     * Hier die Fehlermeldung:
     *   ISO C++ forbids variable length array ‘Zahlen’ [-Werror=vla]
     *
     * Ich weiß nicht, wie das in der Klausur gehandhabt wird. Eigentlich ist
     * es ein Fehler, aber vielleicht geht's auch durch... keine Ahnung.
     * Es gibt zwei Alternativen. Entweder man allokiert den Speicher selbst
     * mit "new" und schiebt die Daten damit auf den sog. "heap", oder man
     * benutzt std::vector. Im ersteren Fall muss man sich dann selbst darum
     * kümmern, dass der Speicher, den man sich "genommen" hat, wieder
     * freigegeben wird (mit "delete"). Deshalb ist std::vector eigentlich
     * angenehmer, da passiert das automatisch. Um den unrsprünglichen
     * Quellcode nicht zu stark zu verändern bleiben wir jetzt mal beim "new".
     */

    // bool Zahlen[eingabe];  // undefined behavior
    bool* Zahlen = new bool[eingabe];  // OK, aber unschön

    /*
     * Die Initialisierungs-Schleife ist überflüssig, das kann man auch in der
     * anderen Schleife machen. Nur die 2 muss man noch extra initialisieren.
     */

    Zahlen[0]=false;
    Zahlen[1]=false;
    Zahlen[2]=false;

    for(int n=3; n<eingabe; n++){
        Zahlen[n] = true;
        for(int i=2; i<n; i++){
            if (n%i==0){
                Zahlen[n] = false;
                break;
            }
        }
    }

    /*
     * Hier sind zwei Sachen falsch. Zum einen wird hier wieder ein array mit
     * variabler Länger definiert (s.o.), zum anderen wird ein array der Länge
     * null definiert. Beides ist in C++ verboten. Beides sind "features" von
     * gcc. Beides sollte man nicht benutzen.
     * Hier die Fehlermeldung zum 0-array:
     *   ISO C++ forbids zero-size array 'prim'
     *
     * 
     */

    int l=0;
    int prim[l];
    int p=0;

    for(int n=0; n<eingabe; n++){
        if(Zahlen[n]) {
            l++;
            cout << l << "-te Zahl: " << n << endl;
            prim[p]=n;
            p++;

        }
    }
    cout << "Anzahl: " << l << endl;

    int kombzahl=0;
    int test = 0;
    for(int i=0;i<l; i++){
        test=eingabe-prim[i];
        for(int j=0;j<l;j++){
            if(test==prim[j]){
                kombzahl++;
                cout << "Moeglichkeit " << kombzahl << ": " << test << " + " << prim[i] <<" = " << eingabe << endl;
            }
        }
    }
    cout << kombzahl << " Kombinationen" << endl;

    return 0;
}
