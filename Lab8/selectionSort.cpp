#include <iostream>
#include <fstream>
#include "headers.hpp"

using namespace std;

int main() {
ifstream ifs;
int size = MAXSIZE;
int array[MAXSIZE];

getArray(ifs, FILENAME, array, size);

cout << "Original array:\n\n";
for (int i = 0; i < size; ++i) {
cout << array[i];
if (i + 1 < size) cout << ' ';
}
cout << "\n\n";

cout << "Ascending (0) or Descending (1): ";
int choice = 0;
cin >> choice;
cout << "\n";

bool descending = (choice == 1);
sort(descending, array, size, 0);

cout << "Sorted array:\n\n";
for (int i = 0; i < size; ++i) {
cout << array[i];
if (i + 1 < size) cout << ' ';
}
cout << '\n';
return 0;
}
