#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int leftSum = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = leftSum;
            leftSum *= nums[i];
        }
        int rightSum = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= rightSum;
            rightSum *= nums[i];
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = solution.productExceptSelf(nums);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
