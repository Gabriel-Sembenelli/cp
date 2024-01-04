#include <bits/stdc++.h>
using namespace std;

// Approach: Simulate everything for each K and for each patient zero
void solve(){
    int N, T; cin >> N >> T;
    string currState; cin >> currState;
    currState = "0" + currState; // 1-indexing
    
    int shake[251][2]{};
    while(T--){             // Saving hooves shakes
        int t; cin >> t;    // over the time
        cin >> shake[t][0] >> shake[t][1];
    }
    
    int cntP0 = 0, minK = 1000, maxK = 0;
    for(int p0=1; p0<=N; p0++){         // For each cow as patient zero
        bool isPossibleP0 = false;
        for(int K=0; K<=251; K++){      // and for each possible K
            string state(N+1,'0');
            int cntShake[N+1]{};
            state[p0] = '1';
            for(int t=0; t<=250; t++){  // simulate hooves shakes over time
                int cow1 = shake[t][0];
                int cow2 = shake[t][1];
                // Flags avoid infecting cow2 and cntShake++ at same iteraction
                bool flag1 = false, flag2 = false;
                if(state[cow1] == '1' and cntShake[cow1] < K){
                    flag1 = true;   // cow1 can infect
                    cntShake[cow1]++;
                }
                if(state[cow2] == '1' and cntShake[cow2] < K){
                    flag2 = true;   // cow2 can infect
                    cntShake[cow2]++;
                }
                if(flag1) state[cow2] = '1';
                if(flag2) state[cow1] = '1';
            }
            if(state == currState){
                isPossibleP0 = true;
                minK = min(minK, K);
                maxK = max(maxK, K);
            }
        }
        if(isPossibleP0) cntP0++;
    }
    
    cout << cntP0 << " " << minK << " ";
    if(maxK >= 250) cout << "Infinity\n";
    else cout << maxK << '\n';
}

signed main(){
    freopen("tracing.in", "r", stdin);
    freopen("tracing.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
