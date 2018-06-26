#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

using namespace std;

class normal_generator
{
    bool has_saved;
    double saved_num;
    unsigned seed;
    mt19937 generator;
    uniform_real_distribution<double> distribution;
    public:
        normal_generator();
        double generate();
        double get();
};

normal_generator::normal_generator():
    has_saved(false),
    saved_num(0.0)
{
    seed = chrono::system_clock::now().time_since_epoch().count();
    generator = mt19937(seed);
    distribution = uniform_real_distribution<double>(-1.0, 1.0);
}

double normal_generator::generate()
{
    return distribution(generator);
}

double normal_generator::get()
{
    if (has_saved)
    {
        has_saved = false;
        return saved_num;
    }

    double v1, v2, s;
    do
    {
        v1 = generate();
        v2 = generate();
        s = v1 * v1 + v2 * v2;
    }
    while (s >= 1 or s == 0);

    double fac = sqrt(-2.0 * log(s) / s);
    saved_num = v2 * fac;

    return v1 * fac;
}

int main(int argc, const char **argv)
{
    cout << "Aufgabe 25: Normalverteilte Zufallszahlen\n" << endl;

    normal_generator ng;
    const long N {10000};
    double mu {0.0};
    double sigma {0.0};

    for (long ii = 0; ii < N; ++ii)
    {
        double x = ng.get();
        mu += x;
        sigma += x * x;
    }

    mu /= double(N);
    sigma = sqrt(sigma / double(N) - mu * mu);

    cout << "mu:    " << mu << endl;
    cout << "sigma: " << sigma << endl << endl;

    long sigma_band[3] {0, 0, 0};
    for (long ii = 0; ii < N; ++ii)
    {
        double x = ng.get();
        for (int jj = 0; jj < 3; ++jj)
        {
            if (abs(x - mu) > double(jj + 1) * sigma)
            {
                ++sigma_band[jj];
            }
        }
    }

    double pct {100.0 / double(N)};
    cout << "1 sigma: " << double(sigma_band[0]) * pct << "%" << endl;
    cout << "2 sigma: " << double(sigma_band[1]) * pct << "%" << endl;
    cout << "3 sigma: " << double(sigma_band[2]) * pct << "%" << endl;
} //main
