#include <bits/stdc++.h>
using namespace std;

void subsetSum(vector<int> arr, int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    dp[0][0] = 1;
    for (int i = 1; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = arr[i - 1] <= j ? (dp[i - 1][j - arr[i - 1]] || dp[i - 1][j]) : dp[i - 1][j];
        }
    }
    cout << (dp[n][k] ? "Existe" : "Nao existe") << "\n";
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    subsetSum(arr, n, k);
}
