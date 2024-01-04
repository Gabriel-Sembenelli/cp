#include <bits/stdc++.h>
using namespace std;

int N, B;
int X[100], Y[100];

// Calculates M when fence cross is at (a,b)
int checkCrossAt(int a, int b){
    vector<int> cnt(4);
    for(int i=0; i<N; i++){
        if(X[i] < a and Y[i] < b) cnt[0]++;
        if(X[i] < a and Y[i] > b) cnt[1]++;
        if(X[i] > a and Y[i] < b) cnt[2]++;
        if(X[i] > a and Y[i] > b) cnt[3]++;
    }
    return *max_element(begin(cnt), end(cnt));
}

void solve(){
    cin >> N >> B;
    for(int i=0; i<N; i++)
        cin >> X[i] >> Y[i];
    int ans = N;
    for(int i=0; i<N; i++)      // combine each x-coordinate
        for(int j=0; j<N; j++)  // with each y-coordinate
            ans = min(ans, checkCrossAt(X[i] + 1, Y[j] + 1));
    cout << ans << '\n';
}

signed main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

/*
Earlier approaches:

1) WA
Create a prefix-sum vector from 0 to 1'000'000 that accumulates x-coordinates
Then find x-coordinate that halves the points
Same on y
Combine them and calculate M

2) WA
Same as (1) but check a neighborhood of the "half-coordinates"
i.e., checkCrossAt (halfX-2, halfY-2), (halfX, halfY-2), (halfX+2, halfY-2), ...

3) WA
Check cross at every 4 even corners of each point.
i.e., for a point (x,y), checkCrossAt (x-1,y-1), (x-1,y+1), (x+1,y-1), (x+1,y+1)
But this fails on tests like:
    .     .
.             .
       
.             .
    .     .
Which the answer is right at the middle, but isn't tested

4) AC
After (3) counter-example I got the idea to combine and check every x-coordinate
with every y-coordinate, even if they don't belong to the same point
*/