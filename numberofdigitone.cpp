#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0;
        for(long long int i = 1; i <= n; i *= 10){
            int a = n / i;
            int b = n % i;
            int x = a % 10;
            if(x == 1){
                ret += (a / 10) * i + (b + 1);
            } else if(x == 0){
                ret += (a / 10) * i;
            } else {
                ret += (a / 10 + 1) * i;
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    int n = 13;
    cout << "Number of digit 1 in numbers up to " << n << ": " << solution.countDigitOne(n) << endl; // Output: 6
    return 0;
}
