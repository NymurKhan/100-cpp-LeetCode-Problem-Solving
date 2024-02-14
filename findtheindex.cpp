#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int x = needle.size(); // Get the size of the needle
        for (int i = 0; i <= haystack.size() - x; i++) { // Iterate through the characters of the haystack
            if (needle == haystack.substr(i, x)) { // Check if the substring of haystack starting at index i and of length x is equal to the needle
                return i; // If true, return the current index i
            }
        }
        return -1; // If no match is found, return -1
    }
};

int main() {
    Solution sol;
    string haystack = "hello", needle = "ll"; // Example input
    int result = sol.strStr(haystack, needle);
    cout << "Index of needle in haystack: " << result << endl;
    return 0;
}

