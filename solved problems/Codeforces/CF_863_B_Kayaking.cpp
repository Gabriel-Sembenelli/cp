/*
Approach: n <= 50, so we can brute force all n^2 possible ways of selecting 2
people to go alone in single kayaks, and calculate the total instability of the
rest. Is guaranteed that we will have an even number of people, so if we sort
the weights, it is clear that, for those people who were not selected to go
alone, the lightest person should go with the second lightest and so on.
This calculation can be done in linear time, so the total time complexity of
this approach will be O(n^3), which is fine.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 0x3f3f3f3f3f3f3f3fLL;

signed main(){
    int n; cin >> n;
    n *= 2;
    vector<int> w(n);
    for(auto &e:w) cin >> e;
    sort(w.begin(), w.end());
    int ans = INF;
    for(int i=0; i<n-1; i++){       // Simulates all possible ways of
        for(int j=i+1; j<n; j++){   // selecting 2 people to go alone
            int tot = 0;
            int lastw = 0;
            for(int k=0; k<n; k++){ // Calculating total diff of tandem
                if(k == i or k == j) continue;
                
                if(lastw != 0){  // Already selected first person
                    tot += w[k] - lastw;  // Pick second now and accumulate diff
                    lastw = 0;
                }else{  // Didn't selected first person
                    lastw = w[k];  // Pick it now
                }
            }
            ans = min(ans, tot);
        }
    }
    cout << ans << '\n';
}
