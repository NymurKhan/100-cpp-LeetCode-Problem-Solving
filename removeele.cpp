#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 2, 3, 4, 5}; // Example input
    int val = 3; // Value to remove
    int newSize = sol.removeElement(nums, val);
    
    cout << "Modified array after removing " << val << ": ";
    for (int i = 0; i < newSize; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}
