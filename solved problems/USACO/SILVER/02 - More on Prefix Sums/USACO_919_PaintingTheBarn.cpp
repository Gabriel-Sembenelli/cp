/*
Offline 2D Prefix Sum (Técnica da Ondinha 2D)

Almost the same idea as Offline 1D Prefix Sum.
Just mark the rectangular corners to do the accumulation later.

Q := number of queries
X := maximum x coordinate
Y := maximum y coordinate
Time complexity: O(Q + X*Y)
*/
#include <bits/stdc++.h>
using namespace std;

int barn[1010][1010];

void solve(){
    int Q, K; cin >> Q >> K;
    // Marking the corners of each query to do the accumulation later
    while(Q--){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1++, y1++, x2++, y2++; // 1-indexing
        barn[x1][y1]++;
        barn[x2][y1]--;
        barn[x1][y2]--;
        barn[x2][y2]++;
    }
    // Making the offline 2D accumulation and checking answer
    int ans = 0;
    for(int x=1; x<=1001; x++){
        for(int y=1; y<=1001; y++){
            barn[x][y] += barn[x-1][y] + barn[x][y-1] - barn[x-1][y-1];
            ans += (barn[x][y] == K);
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}