#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        stack<pair<int,int>> help;
        int area_max = 0;
        int s = a.size();
        for (int i = 0; i <= s; i++)
        {
            int p = 0;
            while (!help.empty() && (i == s || a[help.top().first] >= a[i]))
            {
                // calculate area for element about to be popped
                if (i != s && a[help.top().first] == a[i])
                {
                    break;
                }
                p += 1 + help.top().second;
                int area = p*a[help.top().first];
                if (area > area_max)
                {
                    area_max = area;
                }
                help.pop();
            }
            help.push(make_pair(i, p));
        }
        return area_max;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {2,1,5,6,2,3}; // Example input
    int result = sol.largestRectangleArea(heights);
    cout << "Largest rectangle area: " << result << endl;
    return 0;
}
