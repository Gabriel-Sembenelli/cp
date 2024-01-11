#include <bits/stdc++.h>
using namespace std;

#define int long long

int p[21];
int n;
int ans = LLONG_MAX;

// Recursive Complete-Search ---------------------------------------------------
void solve(int i, int pA, int pB){
    if(i == n){ // base case, already distributed all p[i]
        ans = min(ans, abs(pA - pB));
        return;
    }
    solve(i+1, pA + p[i], pB); // try to put into groupA
    solve(i+1, pA, pB + p[i]); // try to put into groupB
}

signed main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i];
    solve(0, 0, 0); // start at index 0 with pA=0 and pB=0
    cout << ans << '\n';
    
    return 0;
}
// -----------------------------------------------------------------------------

// Iterative Complete-Search ---------------------------------------------------
signed main2(){
    cin >> n;
    int p[n]; for(auto &e:p)cin>>e;
    
    int m = 1LL<<n; // pow(2, n)
    for(int i=0; i<m; i++){ // Simulate all sets (think in a bitwise way)
        int sum[2] = {0, 0};
        for(int j=0; j<n; j++){
            bool checkbit = i&(1<<j); // Check if j-th bit is ON in the i-th set
            sum[checkbit] += p[j];    // j-th state define where it goes
        }
        ans = min(ans, abs(sum[0]-sum[1]));
    }
    cout << ans << endl;
    
    return 0;
}
// -----------------------------------------------------------------------------
