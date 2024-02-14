#include <iostream>
#include <string>

using namespace std;

string m[31] = {""};

class Solution {
public:
    string countAndSay(int n) {
        m[1] = "1";
        string next, prev;
        int i, j, len;
		
		// Generating the say(i)
        for (i = 2; i < n + 1; i++) {
            if (m[i] != "")
                continue;
            next = "";
            prev = m[i - 1];
            len = prev.size();
            int count = 1;
			
			// Reading out the say(i-1) i.e., string prev
            for (j = 1; j < len; j++) {
                if (prev[j - 1] == prev[j])
                    count++;
                else {
                    next = next + to_string(count) + prev[j - 1];
                    count = 1;
                }
            }
            next = next + to_string(count) + prev[j - 1];
            m[i] = next;
        }
        return m[n];
    }
};

int main() {
    Solution sol;
    int n = 5; // Example input
    string result = sol.countAndSay(n);
    cout << "Result for n = " << n << ": " << result << endl;
    return 0;
}
