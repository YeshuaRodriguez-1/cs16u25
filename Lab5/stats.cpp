#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double calculateMean(double arr[], int size) {
double sum = 0;
for(int i = 0; i < size; i++) {
	sum += arr[i];}
return sum / size;
}

void bubbleSort(double arr[], int size) {
	for(int i = 0; i < size - 1; i++) {
	for(int j = 0; j < size - i - 1; j++) {
	if(arr[j] > arr[j+1]) {
		double temp = arr[j];
		arr[j] = arr[j+1];
		arr[j+1] = temp;
}
}
}
}

double calculateMedian(double arr[], int size) {
bubbleSort(arr, size);
	if(size % 2 == 0) {
	return (arr[size/2 - 1] + arr[size/2]) / 2;
} else {
return arr[size/2];
}
}

double calculateStdDev(double arr[], int size, double mean) {
	double sum = 0;
	for(int i = 0; i < size; i++) {
	sum += (arr[i] - mean) * (arr[i] - mean);
}
return sqrt(sum / (size - 1));
}

double calculateZeroPercentage(double arr[], int size) {
int zeroCount = 0;
for(int i = 0; i < size; i++) {
	if(arr[i] == 0.0) {
	zeroCount++;
}
}
return (zeroCount * 100.0) / size;
}

int main() {
string filename;
ifstream file;
	double numbers[1000];
	int count = 0;
cout << "Enter filename: ";
cin >> filename;

file.open(filename);
	if (!file) {
	cerr << "File could not be opened." << endl;
	return 1;
	}

while (file >> numbers[count]) {
count++;
if (count >= 1000) break;
}

file.close();
	double mean = calculateMean(numbers, count);
	double median = calculateMedian(numbers, count);
	double stddev = calculateStdDev(numbers, count, mean);
	double zeroPct = calculateZeroPercentage(numbers, count);

	cout << "Mean = " << mean << endl;
	cout << "Median = " << median << endl;
	cout << "Stddev = " << stddev << endl;
	cout << "Zeroes = " << zeroPct << "%" << endl;

return 0;
}
