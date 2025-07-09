#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int terms = 1;
    double pivalue = 0;

    while (true) {
        cout << "Enter the number of terms to approximate (or zero to quit):" << endl;
        cin >> terms;

        if (terms == 0)
            break;

        pivalue = 0.0;

        for (int i = 0; i < terms; i++) {
            double term = pow(-1, i) / (2 * i + 1);
            pivalue += term;
        }

        pivalue *= 4;

        cout << "The approximation for Leibniz's Formula is " << pivalue
             << " using " << terms << " terms." << endl;
    }

    return 0;
}
