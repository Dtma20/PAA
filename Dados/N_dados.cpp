#include<bits/stdc++.h>
using namespace std;

void Ndados(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(6 * n + 1, 0));
    dp[0][0] = 1;

    for (int dado = 1; dado <= n; ++dado) {
        for (int sum = dado; sum <= 6 * dado; ++sum) {
            dp[dado][sum] = 0;
            for (int face = 1; face <= 6; ++face) {
                if (sum - face >= 0) {
                    dp[dado][sum] += dp[dado - 1][sum - face];
                }
            }
        }
    }
    if (k >= n && k <= 6 * n) {
        cout << k << ": " << dp[n][k] << endl;
    } else {
        cout << "impossivel" << endl;
        return;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    Ndados(n, k);
    return 0;
}
