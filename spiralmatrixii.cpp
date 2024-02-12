#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n));
        int p=n;
        int m=n;
        //cout<<n<<m;
        int c=1;
        int left=0,right=p-1,top=0,bottom=m-1;
        while (left<=right && top<=bottom){
            for (int i=left;i<=right;i++){
                matrix[top][i]=c;
                c++;
            }
            top++;
            for (int i=top;i<=bottom;i++){
                matrix[i][right]=c;
                c++;
            }
            right--;
            if (top<=bottom){
            for (int i=right;i>=left;i--){
                matrix[bottom][i]=c;
                c++;

            }
            bottom--;
        }
            if (left<=right){
            for (int i=bottom;i>=top;i--){
                matrix[i][left]=c;
                c++;
            }
            left++;
            }
        }


    return matrix; 
    }
};