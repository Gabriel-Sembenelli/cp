/*
Worth looking at the editorial to get an interesting alternative solution
https://codeforces.com/blog/entry/69954
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Rectangle {
    int x1, y1, x2, y2;
    
    Rectangle(){}
    Rectangle(int a, int b, int c, int d): x1(a), y1(b), x2(c), y2(d){}
    
    void make(){ cin >> x1 >> y1 >> x2 >> y2; }
    
    int area(){ return (x2 - x1) * (y2 - y1); }
};

Rectangle inter(Rectangle A, Rectangle B){
    int x1 = max(A.x1, B.x1);
    int y1 = max(A.y1, B.y1);
    int x2 = min(A.x2, B.x2);
    int y2 = min(A.y2, B.y2);
    if(x1 < x2 and y1 < y2) return Rectangle(x1, y1, x2, y2);
    return Rectangle(-1, -1, -1, -1);
}

void solve(){
    Rectangle W, B1, B2;
    W.make(), B1.make(), B2.make();
    
    Rectangle I1 = inter(W, B1);
    Rectangle I2 = inter(W, B2);
    Rectangle II = inter(I1, I2);
    
    int uncoveredArea = W.area() - I1.area() - I2.area() + II.area();
    
    if(uncoveredArea > 0) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}