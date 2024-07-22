#include <bits/stdc++.h>
using namespace std;

#define sz(V) (int)(V).size()
#define all(V) begin(V),end(V)

using T = int;
using vi = vector<int>;

struct Point {
    T x, y;
    int idx;
    Point() : x(0), y(0), idx(0) {}
    Point(T _x, T _y, int _idx) : x(_x), y(_y), idx(_idx) {}
};
using Points = vector<Point>;
bool x_cmp(Point &a, Point &b){ return (a.x != b.x) ? a.x < b.x : a.y <= b.y; }
bool y_cmp(Point &a, Point &b){ return (a.y != b.y) ? a.y < b.y : a.x <= b.x; }
T dist2(Point &a, Point &b){ return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y); }


pair<Point, Point> Brute(Points &X, int n){
    pair<Point, Point> best = {X[0], X[1]};
    for(int i=0; i<n-1; ++i)
        for(int j=i+1; j<n; ++j)
            if(dist2(X[i], X[j]) < dist2(best.first, best.second))
                best = {X[i], X[j]};
    return best;
}

pair<Point, Point> ClosestPairAux(Points &X, Points &Y){
    int n = sz(X);
    
    // Base
    if(n <= 3) return Brute(X, n);
    
    // Divide
    int mid = n/2; // bissect line
    Points XL, XR, YL, YR;
    for(int i=0; i<n; ++i){
        if(i <= mid)
            XL.push_back(X[i]);
        else
            XR.push_back(X[i]);
        if((Y[i].x < X[mid].x) or (Y[i].x == X[mid].x and Y[i].y <= X[mid].y))
            YL.push_back(Y[i]);
        else
            YR.push_back(Y[i]);
    }
    //cout << "XL:"; for(auto [x,y,i]:XL) cout<<" ("<<x<<","<<y<<","<<i<<")"; cout << '\n';
    //cout << "XR:"; for(auto [x,y,i]:XR) cout<<" ("<<x<<","<<y<<","<<i<<")"; cout << '\n';
    //cout << "YL:"; for(auto [x,y,i]:YL) cout<<" ("<<x<<","<<y<<","<<i<<")"; cout << '\n';
    //cout << "YR:"; for(auto [x,y,i]:YR) cout<<" ("<<x<<","<<y<<","<<i<<")"; cout << "\n\n";
    
    // Conquer
    pair<Point, Point> pL = ClosestPairAux(XL, YL);
    pair<Point, Point> pR = ClosestPairAux(XR, YR);
    T deltaL = dist2(pL.first, pL.second);
    T deltaR = dist2(pR.first, pR.second);
    T delta = min(deltaL, deltaR);
    pair<Point, Point> best = pL;
    if(delta == deltaR) best = pR;
    
    // Combine
    Points Yrange;
    for(int i=0; i<n; ++i)
        if(mid - delta <= Y[i].x and Y[i].x <= mid + delta)
            Yrange.push_back(Y[i]);
    for(int i=0; i<sz(Yrange); ++i)
        for(int j = i+1; j <= min(i+7, sz(Yrange)-1); ++j)
            if(dist2(Yrange[i], Yrange[j]) < dist2(best.first, best.second))
                best = {Yrange[i], Yrange[j]};
    
    return best;
}

pair<int, int> ClosestPair(vi &X_coord, vi &Y_coord){
    int n = sz(X_coord);
    Points X(n), Y(n);
    for(int i=0; i<n; ++i)
        X[i] = Point(X_coord[i], Y_coord[i], i);
    Y = X;
    sort(all(X), x_cmp);
    sort(all(Y), y_cmp);
    for(int i=0; i<n-1; ++i)
        if(X[i].x == X[i+1].x and X[i].y == X[i+1].y)  // Caso trivial, distancia zero
            return {i, i+1};
    pair<Point, Point> closest = ClosestPairAux(X, Y); // Caso nao trivial, usa D&C
    return {closest.first.idx, closest.second.idx};
}

int main(){
    int n; cin >> n;
    vi X_coord(n), Y_coord(n);
    for(int i=0; i<n; ++i)
        cin >> X_coord[i] >> Y_coord[i];
    pair<int, int> ans = ClosestPair(X_coord, Y_coord);
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}
