/*
 * Programmieren fuer Physiker, SS 2018. Blatt 12, Aufg. 31
 *
 * Binaerer Baum (der sortiert ist):
 * Einfuegen in Baum. Mimimum feststellen. Alles sortiert ausgeben.
 * (Destruktor)
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std ;

class Node {

private:
    double value ;  // Wert des Knoten
    Node* left ;    // Zeiger auf linken Ast
    Node* right ;   // Zeiger auf rechten Ast

public:
    // Node(double x) : value(x), left(0), right(0) {} ; // Konstruktor
    Node(double x) { value=x ; left=0; right=0 ; } ; // Konstruktor
    ~Node() ; // Destruktor
    void insert(double x) ;
    double min() ;
    double min_v2() ;
    friend ostream & operator<< (ostream & str, const Node & n) ;
} ;

Node::~Node()
{
    // hier einfach, da delete den Destruktor des Objekts aufruft.
    // Damit ist die rekursive Loeschung gewaehrleistet.
    // Der Stamm des Baumes darf nicht mit delete geloscht werden.
    // cout << this << endl ;
    if (0 != left) delete(left) ;
    if (0 != right) delete(right) ;
}

// void Node::insert( double x)
// // iterative Variante
// {
//     Node* newleaf = new Node(x) ;  // Erzeuge neuen Node mit Wert x ;
//     // cout << newleaf << endl ;
//     // cout << "inserted: " << x << endl ;
//     Node* pos = this ;  // haenge den neuen Node in den Baum...
//     while (true)
//     {
// 	if (x <= pos->value)               // links oder rechts anhaengen?
// 	    if (0 != pos->left)            // .. haengt schon was links?
// 		pos = pos->left  ;         //   ..ja: dann links weitergehen
// 	    else
// 		{
// 		    pos->left = newleaf ;  //   ..nein: da muss es hin
// 		    break ;                //           (und fertig)
// 		}
// 	else                               // .. haengt schon was rechts?
// 	    if (0 != pos->right)
// 		pos = pos->right  ;        //    .. ja: rechts weitergehen
// 	    else
// 		{
// 		    pos->right = newleaf ; //    .. nein: da muss es hin
// 		    break ;                //             (und fertig)
// 		}
//     }
// }

void Node::insert( double x)
// rein rekursive Variante
{
    if (x <= value)              // linker Ast oder rechter Ast?
	if (left==0)               // Ast frei?
	    left=new Node (x) ;    // ..ja: einhaengen (mit Konstr.aufruf!)
	else
	    left->insert(x) ;      // ..nein: mit neuer "Wurzel" aufrufen
    else                         // hier: x > value: rechter Ast
	if (right==0)              // Ast frei?
	    right=new Node (x) ;   // ..ja: einhaengen (mit Konstr. aufruf!)
	else
	    right->insert(x) ;     // ..nein: mit neuer "Wurzel" aufrufen
    return ;
}

double Node::min()
{
    // kleinstes Element finden:
    //    nach links im Baum gehen, solange es geht.
    Node* Aktuell=this ;
    while (0 != Aktuell->left) Aktuell=Aktuell->left ;
    return Aktuell->value ;
}

double Node::min_v2()
{
    // kleinstes Element finden: (rekursive Version)
    //    nach links im Baum gehen, solange es geht.
    if (0 == left) return value ;
    else return left->min_v2() ;
}

ostream & operator<< (ostream & str, const Node & n)
{
    // Strategie: schau nach links, gib Knotenwert aus, schau nach rechts
    // (dabei nach links und recht rekursiv mit neuer "Baumbasis"
    if (0 != n.left) str << *(n.left) ;  // (.) nicht notwendig
    str << n.value << " " ;
    if (0 != n.right) str << *(n.right) ;
    return str ;
}

int main()
{
    srand ((unsigned int)time(0)) ;
    Node tree(1.0) ; // Basiselement.
    for(int i=0; i<10; i++) // 10 Zufallszahlen in den Baum einhaengen...
    {
	double x = 2.0*double(rand())/RAND_MAX ;
	cout << "Einzufuegen: " << x << endl ;
	tree.insert(x) ;
    }
    cout << "Die minimale Zahl im Baum ist: " << tree.min() << endl ;
    cout << "Die minimale Zahl im Baum ist: " << tree.min_v2() << endl ;
    cout << "Alle Eintraege sortiert: " << endl << "  " << tree << endl ;
}
