#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    int v[n], p[n];
    for(int i = 0; i < n; i++) {
        cin >> v[i] >> p[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= w; j++) {
            if(j < p[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i - 1][j - p[i - 1]]);
            }
        }
    }
    cout << dp[n][w];
}