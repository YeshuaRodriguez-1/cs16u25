#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void cleanAndUppercase(string &input, string &cleaned, int &removedCount) {
	cleaned = "";
	removedCount = 0;

for (char c : input) {
if (isalpha(c)) {
cleaned += toupper(c);
} else {
removedCount++; }
}
}
void bubbleSort(string &str) {
int n = str.length();
	for (int i = 0; i < n - 1; i++) {
	for (int j = 0; j < n - i - 1; j++) {
		if (str[j] > str[j + 1]) {
		char temp = str[j];
		str[j] = str[j + 1];
		str[j + 1] = temp;
}
}
}
}

void countFrequencies(const string &str) {
for (char letter = 'A'; letter <= 'Z'; ++letter) {
	int count = 0;
	for (char c : str) {
	if (c == letter) count++;
}
if (count > 0) {
cout << letter << ": " << count << endl;
}
}
}

int main(){
string input, cleaned;
int removed = 0;
	cout << "Enter sentence: ";
	getline(cin, input);
	cleanAndUppercase(input, cleaned, removed);
	bubbleSort(cleaned);
	cout << "Sorted and cleaned-up sentence: " << cleaned << endl;
	countFrequencies(cleaned);
cout << "removed: " << removed << endl;
    return 0;
}

