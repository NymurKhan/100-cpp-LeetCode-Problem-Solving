#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        
        set<int> st(nums.begin(), nums.end());
        vector<int> uniqueNums;
        for (int num : st) {
            uniqueNums.push_back(num);
        }
        int visited = 0;
        for (int mi = 0; mi < uniqueNums.size(); mi++) {
            while (visited < uniqueNums.size() && uniqueNums[visited] < uniqueNums[mi] + n) {
                visited++;
            }
            
            int subAns = visited - mi;
            ans = min(ans, n - subAns);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 3}; // Example input
    int result = sol.minOperations(nums);
    cout << "Minimum operations required: " << result << endl;
    return 0;
}
