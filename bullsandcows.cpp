#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string getHint(string& secret, string &guess) {
        unordered_map<char,int> secret_freq;
        unordered_map<char,int> guess_freq;

        int size = secret.size();

        int bulls = 0;
        int cows = 0;
        for(int i = 0; i < size; i++){
            if(secret[i] == guess[i]){
                bulls++;
            }else{
                secret_freq[secret[i]]++;
                guess_freq[guess[i]]++;
            }
        }
        for(auto it: guess_freq){
            cows += min(it.second,secret_freq[it.first]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};

int main() {
    Solution solution;
    string secret = "1807";
    string guess = "7810";
    string result = solution.getHint(secret, guess);
    cout << "Result: " << result << endl;
    return 0;
}
