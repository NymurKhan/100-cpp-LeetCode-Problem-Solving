#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int el1, el2;
        vector<int> res;

        for(int i=0; i<nums.size(); i++) {
            if(count1 == 0 && nums[i] != el2) {
                count1 = 1;
                el1 = nums[i];
            } else if(count2 == 0 && nums[i] != el1) {
                count2 = 1;
                el2 = nums[i];
            } else if(nums[i] == el1) {
                count1++;
            } else if(nums[i] == el2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        int array_size = (nums.size() / 3) + 1;
        int cnt_1 = 0;
        int cnt_2 = 0;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == el1) {
                cnt_1++;
            } else if(nums[i] == el2) {
                cnt_2++;
            }
        }

        if(cnt_1 >= array_size) {
            res.push_back(el1);
        }

        if(cnt_2 >= array_size) {
            res.push_back(el2);
        }

        return res;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    vector<int> result = solution.majorityElement(nums);
    cout << "Majority Elements: ";
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl; // Output: Majority Elements: 4
    return 0;
}
