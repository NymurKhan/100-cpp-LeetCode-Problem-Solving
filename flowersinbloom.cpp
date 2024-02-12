#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        unordered_map<int,int> mp;
        vector<int> mp_key;
        
        for(int p: people){
            if (mp.count(p) == 0){
                mp[p] = 0;
                mp_key.push_back(p);
            }   
        }
        
        for(auto& fl: flowers){
            int s = fl[0], t = fl[1] + 1;
            if (mp.count(s)) mp[s]++;
            else {
                mp[s] = 1;
                mp_key.push_back(s);
            }
            if (mp.count(t)) mp[t]--;
            else{
                mp[t] = -1;
                mp_key.push_back(t);
            } 
        }

        sort(mp_key.begin(), mp_key.end());

        int bloom = 0;
        for(int k : mp_key){
           mp[k] += bloom;
           bloom = mp[k];
        }
        
        int n = people.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++){
           ans[i] = mp[people[i]];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> flowers = {{1, 3}, {2, 4}, {2, 5}, {5, 6}}; // Example flowers
    vector<int> people = {2, 1, 3, 4, 5, 6}; // Example people
    vector<int> result = sol.fullBloomFlowers(flowers, people);
    cout << "Bloom Status for each person: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
