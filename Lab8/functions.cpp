#include <iostream>
#include <fstream>
#include "headers.hpp"

void getArray(std::ifstream& fin, const std::string& filename, int arr[], int& n) {
n = 0;
fin.open(filename);
if (!fin) {
std::cerr << "Error: cannot open \"" << filename << "\"\n";
return;
}
while (n < MAXSIZE && (fin >> arr[n])) {
++n;
}
fin.close();
}
int find_index_of_swap(bool descending, const int arr[], int n, int start_idx) {
int idx = start_idx;
for (int j = start_idx + 1; j < n; ++j) {
if (descending) {
if (arr[j] > arr[idx]) idx = j; 
} else {
if (arr[j] < arr[idx]) idx = j;
}
}
return idx;
}
void swap_values(int& a, int& b) {
int t = a; a = b; b = t;
}
void sort(bool descending, int arr[], int n, int start_idx) {
if (start_idx >= n - 1) return; 

int idx = find_index_of_swap(descending, arr, n, start_idx);
if (idx != start_idx) swap_values(arr[start_idx], arr[idx]);
sort(descending, arr, n, start_idx + 1);
}
