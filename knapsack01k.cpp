#include<bits/stdc++.h>

using namespace std;

void knapsack(vector<int> w, vector<int> p, int c, int n) {
    vector<vector<int>> dp(n+1, vector<int>(c +1,0));

    for(int i=1;i<=n;i++) {
        for(int j=0;j<=c;j++) {
            if(w[i-1]<=j) {
                dp[i][j] = max(dp[i-1][j],p[i-1]+dp[i-1][j-w[i-1]]);
                
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main() {
    
    return 0;
}