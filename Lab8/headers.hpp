#ifndef HEADERS_HPP
#define HEADERS_HPP
#include <string>
#include <fstream>


const int MAXSIZE = 20;     // amount of integers in the file (you need this to declare your array size)
const std::string FILENAME = "ArrayFile.txt";    // The file name with the integers

void swap_values(int& a, int& b);
int  find_index_of_swap(bool descending, const int arr[], int n, int start_idx);
void sort(bool descending, int arr[], int n, int start_idx);
void getArray(std::ifstream& fin, const std::string& filename, int arr[], int& n);

#endif
