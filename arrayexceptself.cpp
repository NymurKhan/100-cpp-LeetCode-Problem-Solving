#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /***************************************** Approach 1 *****************************************/
    vector<int> productExceptSelfBruteForce(vector<int>& nums) {
        int n = nums.size();
        vector<int> output;
        for(int i = 0; i < n; i++) {
            int product = 1;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                product *= nums[j];
            }
            output.push_back(product);
        }
        return output;
    }

    /***************************************** Approach 2 *****************************************/
    vector<int> productExceptSelfDP(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> leftProduct(n);
        vector<int> rightProduct(n);
        leftProduct[0] = 1;
        for(int i = 1; i < n; i++) {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }
        rightProduct[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--) {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }
        for(int i = 0; i < n; i++) {
            ans[i] = leftProduct[i] * rightProduct[i];
        }
        return ans;
    }

    /***************************************** Approach 3 *****************************************/
    vector<int> productExceptSelfDPOptimized(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n);
        output[0] = 1;
        for(int i = 1; i < n; i++) {
            output[i] = output[i - 1] * nums[i - 1];
        }
        int right = 1;
        for(int i = n - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    
    // Approach 1: Brute Force
    vector<int> result1 = solution.productExceptSelfBruteForce(nums);
    cout << "Approach 1: Brute Force" << endl;
    for(int i = 0; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;
    
    // Approach 2: Dynamic Programming (Tabulation)
    vector<int> result2 = solution.productExceptSelfDP(nums);
    cout << "Approach 2: Dynamic Programming (Tabulation)" << endl;
    for(int i = 0; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;
    
    // Approach 3: Dynamic Programming (Space Optimization)
    vector<int> result3 = solution.productExceptSelfDPOptimized(nums);
    cout << "Approach 3: Dynamic Programming (Space Optimization)" << endl;
    for(int i = 0; i < result3.size(); i++) {
        cout << result3[i] << " ";
    }
    cout << endl;
    
    return 0;
}
