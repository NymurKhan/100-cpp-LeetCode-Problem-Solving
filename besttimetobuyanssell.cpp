#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& Arr) {
        int n = Arr.size();

        vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
        vector<vector<int>> cur(2, vector<int>(k + 1, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 0) { // Condition for buy
                        cur[buy][cap] = max(ahead[0][cap], -Arr[ind] + ahead[1][cap]);
                    }
                    if (buy == 1) { // Condition for Sell
                        cur[buy][cap] = max(ahead[1][cap], Arr[ind] + ahead[0][cap - 1]);
                    }
                }
            }
            ahead = cur;
        }
        return ahead[0][k];
    }
};

int main() {
    Solution sol;
    vector<int> Arr = {3, 2, 6, 5, 0, 3};
    int k = 2;
    int maxProfit = sol.maxProfit(k, Arr);
    cout << "Maximum profit with at most " << k << " transactions: " << maxProfit << endl;
    return 0;
}
