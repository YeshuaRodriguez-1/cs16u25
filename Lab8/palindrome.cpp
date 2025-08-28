#include <iostream>
#include <string>
#include <cctype>


std::string cleanUp(const std::string& s) {
std::string out;
out.reserve(s.size());
for (unsigned char ch : s) {
if (std::isalpha(ch)) out.push_back(static_cast<char>(std::tolower(ch)));
}
return out;
}

bool isPalRec(const std::string& s, int i, int j) {
if (i >= j) return true;
if (s[i] != s[j]) return false; 
return isPalRec(s, i + 1, j - 1);
}

bool isPalindrome(const std::string& s) {
return isPalRec(s, 0, static_cast<int>(s.size()) - 1);
}

int main() {
    std::cout << "Enter sentence:\n\n";
    std::string line;
    std::getline(std::cin, line);
    if (line.empty() && std::cin.good()) std::getline(std::cin, line);

    std::string cleaned = cleanUp(line);
    std::cout << (isPalindrome(cleaned) ? "\nIt is a palindrome.\n"
                                        : "\nIt is not a palindrome.\n");
    return 0;
}
