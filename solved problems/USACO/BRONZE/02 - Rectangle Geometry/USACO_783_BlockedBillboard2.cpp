#include <bits/stdc++.h>
using namespace std;

#define MP make_pair

struct Rectangle {
    int x1, y1, x2, y2;
    
    Rectangle(){ cin >> x1 >> y1 >> x2 >> y2; }
    
    int area(){ return (x2 - x1) * (y2 - y1); }
};

void solve(){
    Rectangle lawn, feed;
    
    int xInter = max(0, min(lawn.x2, feed.x2) - max(lawn.x1, feed.x1));
    int yInter = max(0, min(lawn.y2, feed.y2) - max(lawn.y1, feed.y1));
    
    int ans = lawn.area();
    
    // Billboards doesn't intersect
    if(xInter * yInter == 0){
        cout << ans << '\n';
        return;
    }
    
    // Intersection coordinates
    int x1 = max(lawn.x1, feed.x1);
    int y1 = max(lawn.y1, feed.y1);
    int x2 = min(lawn.x2, feed.x2);
    int y2 = min(lawn.y2, feed.y2);
    
    // Check if intersection has a common corner and a common side length with lawn board
    if(MP(x1, y1) == MP(lawn.x1, lawn.y1) or MP(x2, y2) == MP(lawn.x2, lawn.y2))
        if(x2 - x1 == lawn.x2 - lawn.x1 or y2 - y1 == lawn.y2 - lawn.y1)
            ans -= xInter * yInter;
    
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