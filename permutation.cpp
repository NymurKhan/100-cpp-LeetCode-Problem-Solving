class Solution {
public:
    string ans = "";
    void generate(int visited[], int n, int k, int &count, int at, int val) {
        if(count>=k) return;
        visited[val] = at;
        if(at == n) {
            count++;
            if(count == k) {
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=n;j++) {
                        if(visited[j]==i) {
                            ans += to_string(j);
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n && count<k;i++) {
            if(visited[i]==0) {
                generate(visited, n, k, count, at+1, i);
            }
        }
        visited[val] = 0;
    }
    string getPermutation(int n, int k) {
        int visited[11] = {0};
        int count = 0;
        generate(visited, n, k, count, 0, 100);
        return ans;
    }
};