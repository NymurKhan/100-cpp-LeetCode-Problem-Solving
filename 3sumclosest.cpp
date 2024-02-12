#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // For INT_MAX
#include <cmath> // For abs()

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
    
        int sum = 0;
        int ans = nums[0] + nums[1] + nums[2]; // Initialize ans with the sum of first three elements

        for(int i = 0; i < nums.size(); i++) {
            int starting = i + 1;
            int ending = nums.size() - 1;
            while(starting < ending) {
                sum = nums[i] + nums[starting] + nums[ending];
                if(sum == target) {
                    return sum;
                }
                if(abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                if(sum < target) {
                    starting++;
                } else {
                    ending--;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4}; // Example input
    int target = 1; // Example target
    int result = sol.threeSumClosest(nums, target);
    cout << "Closest sum to target " << target << " is: " << result << endl;
    return 0;
}
