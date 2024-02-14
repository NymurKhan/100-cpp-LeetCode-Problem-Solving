#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        combinationSumRec(candidates, target, 0, result, t);
        return result;
    }

    void combinationSumRec(vector<int>& candidates, int target, int begin, vector<vector<int>>& result, vector<int>& t) {
        if (target == 0) {
            result.push_back(t);
            return;
        }

        int x = begin;

        while (begin < candidates.size() && target - candidates[begin] >= 0) {
            if (begin > x && candidates[begin] == candidates[begin - 1]) {
                begin++;
                continue;
            }

            t.push_back(candidates[begin]);
            combinationSumRec(candidates, target - candidates[begin], begin + 1, result, t);
            t.pop_back();
            begin++;
        }
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5}; // Example candidates
    int target = 8; // Example target
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    cout << "Unique combinations that sum up to " << target << ":" << endl;
    for (const auto& combination : result) {
        cout << "[";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
