#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
    Rectangle(){ cin >> x1 >> y1 >> x2 >> y2; }
};

void solve(){
    Rectangle A, B;
    int side1 = max(A.x2, B.x2) - min(A.x1, B.x1);
    int side2 = max(A.y2, B.y2) - min(A.y1, B.y1);
    int ans = max(side1, side2);
    cout << ans*ans << '\n';
}

signed main(){
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}