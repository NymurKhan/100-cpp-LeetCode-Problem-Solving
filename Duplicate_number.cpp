#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(auto i : nums) {
            if(ans[i - 1] == 0) ans[i - 1]++;
            else return i;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 2, 2}; // Example input
    int result = sol.findDuplicate(nums);
    cout << "Duplicate number: " << result << endl;
    return 0;
}
