/*
 * This program is intended as a simple demonstration of some of the common
 * pitfalls involved with floating point arithmetic.
 * Use however you see fit, provided "AS IS", no warranty of any kind, yada yada...
 */

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main(int argc, char** argv)
{
    cout << "\nPrecision of float/double:\n" << endl;

    // general info
    cout.precision(numeric_limits<float>::digits10);
    cout << "Decimal precision (float): " << numeric_limits<float>::digits10 << endl;
    cout << "minimum: " << numeric_limits<float>::min() << endl;
    cout << "lowest:  " << numeric_limits<float>::lowest() << endl;
    cout << "highest: " << numeric_limits<float>::max() << endl;
    cout << "epsilon: " << numeric_limits<float>::epsilon() << endl << endl;

    cout.precision(numeric_limits<double>::digits10);
    cout << "Decimal precision (double): " << numeric_limits<double>::digits10 << endl;
    cout << "minimum: " << numeric_limits<double>::min() << endl;
    cout << "lowest:  " << numeric_limits<double>::lowest() << endl;
    cout << "highest: " << numeric_limits<double>::max() << endl;
    cout << "epsilon: " << numeric_limits<double>::epsilon() << endl;

    // float/double comparisons
    cout << "\nFloating point comparisons (float/double):\n" << endl;
    cout.precision(numeric_limits<float>::digits10);
    float a1 = 0.1f;
    float a2 = 0.1f;
    double b1 = 0.1;
    double b2 = 0.1;
    cout << "float a1 =  " << a1 << endl;
    cout << "float a2 =  " << a2 << endl;
    cout << "double b1 = " << b1 << endl;
    cout << "double b2 = " << b2 << endl;
    cout << "a1 == a2: " << (a1 == a2 ? "true" : "false") << endl;
    cout << "b1 == b2: " << (b1 == b2 ? "true" : "false") << endl;
    cout << "a1 == b1: " << (a1 == b1 ? "true" : "false") << endl;

    // precision loss
    cout << "\nPrecision loss:\n" << endl;
    cout.precision(numeric_limits<float>::digits10);
    float c1 = 1.00000000f;
    float c2 = 0.00000001f;
    float c3 = c1 + c2;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = c1 + c2" << endl;
    cout << "c1 == c3: " << (c1 == c3 ? "true" : "false") << endl;  // ...oops.

    // narrowing
    cout << "\nNarrowing:\n" << endl;
    cout.precision(numeric_limits<float>::digits10);
    double overfloat = numeric_limits<float>::max() + 1e38;
    float d1 = overfloat;  // implicit narrowing, bad!
    float d2 {overfloat};  // narrowing with compiler warning, better
    cout << "double d1 = " << overfloat << endl;
    cout << "double d2 = " << overfloat << endl;
    cout << "float d1 = " << d1 << endl;
    cout << "float d2 = " << d2 << endl;

    // error accumulation
    cout << "\nError accumulation:\n" << endl;
    cout.precision(numeric_limits<float>::digits10);
    auto err_acc = [] (int k)
    {
        float c = 0.0f;
        for (int ii = 0; ii < k; ++ii) { c += 0.1f; }
        return 0.1f * static_cast<float>(k) - c;
    };

    cout << "f(k) = 0.1 * k - sum(0.1, [0, k])" << endl;
    for (int k = 1; k <= 100000; k *= 10)
    {
        cout << "f(" << setw(6) << k << ") = " << err_acc(k) << endl;
    }

    // Now for something fun. The below loop never terminates. Uncomment at your own risk ;)
    /* for (float ii = 0; ii != 0.3; ii += 0.1); */

    return 0;
}
