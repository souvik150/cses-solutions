#include <bits/stdc++.h>
using namespace std;

#define int long long
 
void solve() {
    int n, x;
    cin >> n >> x;
 
    vector<int> cost(n);
    vector<int> pages(n);
 
    for(auto &i: cost) {
        cin >> i;
    }
    for(auto &i: pages) {
        cin >> i;
    }
 
    vector<int> dp(x+1, 0);
 
    // dp[k] = maximum pages we can read such that we can only spend at max k money
 
    // transition
    for(int i = 0; i < n; i++) {
        for(int k = x; k >= cost[i]; k--) {
            dp[k] = max(dp[k], pages[i] + dp[k-cost[i]]);
        }
    }
 
    cout << dp[x] << endl;
}
 
signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}