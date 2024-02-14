#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long int ans = dividend / static_cast<long long int>(divisor);
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return static_cast<int>(ans);
    }
};

int main() {
    Solution sol;
    int dividend = 10, divisor = 3; // Example input
    int result = sol.divide(dividend, divisor);
    cout << "Result of division: " << result << endl;
    return 0;
}
