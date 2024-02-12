#include <iostream>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> result;
        vector<pair<int,int>> rows(mat.size()); 

        for (int i = 0; i < mat.size(); i++) {
            rows[i] = make_pair(accumulate(mat[i].begin(), mat[i].end(), 0), i);
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq(rows.begin(), rows.end());

        while (!pq.empty() && k > 0) {
            result.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,1,0,0,0},
                                {1,1,1,1,0},
                                {1,0,0,0,0},
                                {1,1,0,0,0},
                                {1,1,1,1,1}}; // Example input
    int k = 3; // Example k
    vector<int> result = sol.kWeakestRows(mat, k);
    cout << "The indices of the k weakest rows are: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
