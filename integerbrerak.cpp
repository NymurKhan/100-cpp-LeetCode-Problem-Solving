#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1; 
        
        int k = n / 3, r = n % 3; 
        if (r == 0) return pow(3, k); 
        else if (r == 1) return pow(3, k - 1) * 4;
        else return pow(3, k) * 2;
    }
};

int main() {
    Solution sol;
    int n = 10; // Example input
    int result = sol.integerBreak(n);
    cout << "Maximum product after breaking the integer: " << result << endl;
    return 0;
}
