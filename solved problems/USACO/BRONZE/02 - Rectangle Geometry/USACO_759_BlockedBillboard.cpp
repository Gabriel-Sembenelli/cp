#include <bits/stdc++.h>
using namespace std;

struct Rectangle {
    int x1, y1, x2, y2;
    Rectangle(){ cin >> x1 >> y1 >> x2 >> y2; }
};

int area(Rectangle R){ return (R.x2 - R.x1) * (R.y2 - R.y1); }

int inter(Rectangle A, Rectangle B){
    int xInter = max(0, min(A.x2, B.x2) - max(A.x1, B.x1));
    int yInter = max(0, min(A.y2, B.y2) - max(A.y1, B.y1));
    return xInter * yInter;
}

void solve(){
    Rectangle bb1, bb2, trk;
    int ans = area(bb1) + area(bb2) - inter(bb1, trk) - inter(bb2, trk);
    cout << ans << '\n';
}

signed main(){
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}