#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        priority_queue<pair<int , int>> pq;
        vector<int>ans;
        int i = 0 , j = 0;
        while(j < a.size()) {
            while(j - i < k) pq.push({a[j] , j++});
            while(!pq.empty() and j - pq.top().second > k) pq.pop();
            ans.emplace_back(pq.top().first);
            i++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = solution.maxSlidingWindow(nums, k);
    cout << "Maximum sliding window values: ";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
