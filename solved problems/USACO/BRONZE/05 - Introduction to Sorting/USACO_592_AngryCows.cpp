/*
Approach: N <= 100 so we can brute force to choose each hay bale and propagate
it's explosions.
For each time 't', we keep track of all the blast area as well as which hay
bales already exploded. Then we iterate over all others, checking if they can
explode now, and calculate what will be the new explosion range.
For each chosen hay bale, we do this until the explosion can not propagate
anymore.
At the worst case, a hay bale can propagate it's explosion at one other hay bale
every time, so one iteration would take n^2 operations.
At total this should be O(n^3)

It's worth looking at the Internal Sol to get an O(N^2) approach
https://usaco.guide/problems/usaco-592-angry-cows/solution#video-solution
*/
#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    
    int N; cin >> N;
    vector<int> x(N);
    for(auto &e:x) cin >> e;
    //sort(begin(x), end(x)); // Not needed, since we are always checking all N
    int ans = 0;
    for(int chosen=0; chosen<N; chosen++){
        vector<int> exploded(N);
        exploded[chosen] = 1;
        int L = x[chosen] - 1;
        int R = x[chosen] + 1;
        int booms = 1;
        for(int t=2; t; t++){
            bool propagate = false;
            int newL = L, newR = R;
            for(int i=0; i<N; i++){
                if(!exploded[i] and L <= x[i] and x[i] <= R){
                    newL = min(newL, x[i] - t);
                    newR = max(newR, x[i] + t);
                    exploded[i] = 1;
                    booms++;
                    propagate = true;
                }
            }
            L = newL, R = newR;
            if(!propagate) break;
        }
        ans = max(ans, booms);
    }
    cout << ans << '\n';
}
