#include <iostream>

// Nur includes benutzen die ihr auch wirklich braucht!
// Allerdings denke ich nicht, dass es in der Klausur dafuer Abzug gibt.
/* #include <cmath> */

using namespace std;

int main(){
    cout << "Bitte eine Zahl eingeben" << endl;
    long eingabe; // Naja, long...? Schon ok, aber ein int tut's auch.
    cin >> eingabe;

    /*
     * Arrays, deren Größe zur Kompilierzeit nicht bekannt sind, sind laut
     * C++ Standard nicht erlaubt und führen zu undefiniertem Verhalten.
     * GCC (und damit g++) erlaubt diese Art der Initialisierung
     * als "feature". Andere Compiler i.d.R. nicht (z.B. clang).
     * Hier die Fehlermeldung:
     *   ISO C++ forbids variable length array ‘Zahlen’ [-Werror=vla]
     *
     * Ich habe nochmal mit Herrn Mildenberger gesprochen und er meinte, das
     * wird nicht als Fehler gewertet. Ist also in der Klausur so ok.
     *
     * Richtig macht man es aber so: Entweder man allokiert den Speicher selbst
     * mit "new" und schiebt die Daten damit auf den sog. "heap", oder man
     * benutzt std::vector. Im ersteren Fall muss man sich dann selbst darum
     * kümmern, dass der Speicher wieder freigegeben wird (mit "delete").
     * Deshalb ist std::vector eigentlich angenehmer, da passiert das
     * automatisch. Um den unrsprünglichen Quellcode nicht zu stark zu
     * verändern bleiben wir jetzt mal beim "new".
     */

    // bool Zahlen[eingabe];  // undefined behavior
    bool* Zahlen = new bool[eingabe];  // das ist per C++ Standard erlaubt

    /*
     * Die Initialisierungs-Schleife ist überflüssig, das kann man auch in der
     * anderen Schleife machen. Nur die 2 muss man noch extra initialisieren.
     */

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

    /*
     * Folgend sind zwei Sachen falsch. Zum einen wird hier wieder ein array mit
     * variabler Länger definiert (s.o.), zum anderen wird ein array der Länge
     * null definiert. Beides ist in C++ verboten. Beides sind "features" von
     * gcc. Beides sollte man nicht benutzen.
     * Hier die Fehlermeldung zum 0-array:
     *   ISO C++ forbids zero-size array 'prim'
     *
     * Klausurtechnisch ist das aber beides noch in Ordnung und gibt keinen
     * Abzug. Felder mit Laenge null sind zwar nicht nuetzlich, aber sie tun
     * auch keinem was. Was aber ganz sicher falsch ist und in der Klausur
     * Abzug gibt ist, wenn ihr auf Feldelemente zugreifen wollt die es nicht
     * gibt. C++ (und C) prueft Grenzen von arrays nicht und ihr seid selbst
     * dafuer verantwortlich, auf Elemente zuzugreifen die es auch wirklich
     * gibt. Wenn ihr ein array der Groesse zehn definiert, duerft ihr auf
     * keinen Fall auf das 11. Element zugreifen. Wenn das array mit einer
     * Groesse null definiert wurde, dann duerft ihr streng genommen auf gar
     * kein Element zugreifen.
     *
     * | <- array grenzen -> |        |<- zugriff hier (nicht ok)
     * 01010101010101100000101010100101011010
     */

    /*
     * Warum erst eine bool-Liste generieren und dann nochmal iterieren um die
     * Primzahlen reinzuschreiben? Warum kann ich die Zahlen nicht direkt in
     * eine Liste schreiben? Oder besser noch, warum nicht einfach die
     * bool-Liste unten in der Berechnung verwenden und den Index als Primzahl
     * verwenden? Ich mach jetzt mal nur mit der bool-Liste weiter.
     */

    /* int l = 0; */
    /* int prim[l]; */
    /* int p = 0; */

    /* for(int n=0; n<eingabe; n++){ */
    /*     if(Zahlen[n]) { */
    /*         l++; */
    /*         cout << l << "-te Zahl: " << n << endl; */
    /*         prim[p]=n; */
    /*         p++; */
    /*     } */
    /* } */
    /* cout << "Anzahl: " << l << endl; */

    int kombzahl = 0;
    int test = 0;

    /*
     * Der obere Teil des Codes hier (der Teil nach dem "if") ist die
     * urspruengliche Version des Codes, die ich so angepasst habe, dass sie
     * funktioniert. Vorher hat das Programm naemlich nicht alle Zerlegungen
     * gefunden. Teste dein altes Programm selber mit z.B. 30: Das Programm
     * findet nur 17 + 13. 30 kann man aber auf drei unterschiedliche Arten
     * zerlegen.
     *
     * Statt des oben definierten prim-arrays benutze ich nur die Zahlen-Liste
     * vom Anfang.
     *
     * Der untere Teil (nach dem "else") ist die von mir ueberarbeitete
     * Version der Schleife.
     */

    // Nicht verwirren lassen, das if/else hier dient nur zum wechseln zwischen
    // den beiden Methoden. Man kann die Schleifen stattdessen auch
    // auskommentieren.
    // Einfach false reinschreiben um den Code nach dem else zu verwenden.
    if (true)  // true/false
    {

    // Alle Zahlen bis zur Eingabezahl durchgegehen
    for (int i = 0; i < eingabe; i++)
    {
        // Falls die Zahl prim ist -> testen
        if (Zahlen[i])
        {
            test = eingabe - i;
            // Zweiter Summand (nur bis i gehen, sonst haben wir alles doppelt.
            // Waere allerdings kein Fehler.
            // Kleiner gleich benutzen um auch zwei Mal die gleiche Primzahl
            // zuzulassen (prim + prim = gesuchte Zahl). Wird auch so in der
            // Aufgabe verlangt (siehe Beispielrechnung).
            for (int j = 0; j <= i; j++)
            {
                // Falls die Zahl prim ist und unser Summand auch haben wir
                // ein Ergebnis gefunden.
                if (Zahlen[j] && test == j)
                {
                    kombzahl++;
                    cout << "Moeglichkeit " << kombzahl << ": " << test << " + " << i <<" = " << eingabe << endl;
                }
            }
        }
    }
    cout << kombzahl << " Kombinationen" << endl;

    } else {   // Andere Version der Schleife

    /*
     * Hier habe ich die Schleifen angepasst, sodass zwar das gleiche Ergebnis
     * rauskommt, das ganze aber etwas "eleganter" passiert.
     * Ich generiere nur einen Summanden i. Weil beide Summanden zusammen die
     * gesuchte Zahl ergeben muessen, muss der zweite Summand eingabe - i sein.
     * Dann muss ich nur noch ueberpruefen, ob beide Summanden prim sind und
     * habe mein Ergebnis.
     */
    for (int i = 0; i <= eingabe / 2; ++i)
    {
            if (Zahlen[i] && Zahlen[eingabe - i])
            {
                kombzahl++;
                cout << "Moeglichkeit " << kombzahl << ": " << i << " + "
                     << eingabe - i << " = " << eingabe << endl;
            }
    }

    }

    return 0;
}
