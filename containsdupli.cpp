#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int,int>> arr(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            arr[i].first = nums[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(arr[i].first + valueDiff >= arr[j].first) {
                    if(abs(arr[i].second - arr[j].second) <= indexDiff)
                        return true;
                } else {
                    break;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 2, 4, 3, 9, 1, 5, 9};
    int indexDiff = 2;
    int valueDiff = 3;
    cout << "Result: " << sol.containsNearbyAlmostDuplicate(nums, indexDiff, valueDiff) << endl;
    return 0;
}
