#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<int> soma(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> grid[i][j];
            soma[i] += grid[i][j];
        }
    }
    sort(all(soma));
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(i < n / 2) ans -= soma[i];
        else          ans += soma[i];
    }
    cout << ans / 2 << '\n';
    return 0;
}
