#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0, end = len - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < nums[end]){
                if(target > nums[mid] && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            } else {
                if(target >= nums[start] && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            }
        }
       
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example input
    int target = 0; // Example target
    int result = sol.search(nums, target);
    cout << "Index of target in nums: " << result << endl;
    return 0;
}
