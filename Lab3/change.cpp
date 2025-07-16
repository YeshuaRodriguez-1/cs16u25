#include <iostream>
using namespace std;

void compute_coins(int amount) {
	int original_amount = amount;
	int quarters = amount / 25; 
	amount %= 25;
	int nickels = amount / 5;
	int pennies = amount % 5;

	cout << original_amount << (original_amount == 1 ? " cent" : " cents") << " can be given in ";

	if (quarters > 0)
        cout << quarters << " " << (quarters == 1 ? "quarter" : "quarters");
	if (nickels > 0)
        cout << (quarters > 0 ? ", " : "") << nickels << " " << (nickels == 1 ? "nickel" : "nickels");
	if (pennies > 0)
        cout << ((quarters > 0 || nickels > 0) ? ", " : "") << pennies << " " << (pennies == 1 ? "penny" : "pennies");

	cout << "." << endl;
}

int main() {
int amount;
	while (true) {
        cout << "Enter number of cents (or zero to quit):" << endl;
        cin >> amount;

        if (amount == 0) break;
        if (amount < 1 || amount >= 100) {
            cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
	continue;
        }

	compute_coins(amount);
    }
return 0;
}
