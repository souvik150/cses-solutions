#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
 
    vector<long long> prefix_sum(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }
 
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
 
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i; j < n; j++) {
            if(i == j) {
                dp[i][j] = arr[i];
            } else {
                dp[i][j] = max(
                    arr[i] + (prefix_sum[j + 1] - prefix_sum[i + 1] - dp[i + 1][j]),
                    arr[j] + (prefix_sum[j] - prefix_sum[i] - dp[i][j - 1])
                );
            }
        }
    }
    cout << dp[0][n - 1] << endl;
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
 
    return 0;
}