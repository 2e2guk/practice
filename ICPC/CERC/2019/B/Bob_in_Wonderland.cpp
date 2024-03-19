// boj 18173 Bob in wonderland
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> link[n];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        link[u].push_back(v);
        link[v].push_back(u);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max((int)link[i].size() - 2, 0);
    }
    cout << ans;
    return 0;
}
