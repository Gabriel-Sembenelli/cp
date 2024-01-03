#include <bits/stdc++.h>
using namespace std;

// O(M^3 N lgN)
// This can be reduced to O(M^3 N) if we use bitmask/hashing like Editorial
// Or by using unordered_set (subject to anti-hash tests)
void solve(){
    int N, M; cin >> N >> M;
    string spotty[N], plain[N];
    for(auto &s:spotty) cin >> s;
    for(auto &s:plain) cin >> s;
    int ans = 0;
    for(int a=0; a<M; a++){             // for each
        for(int b=a+1; b<M; b++){       // position
            for(int c=b+1; c<M; c++){   // triplet
                bool explain = true;
                set<string> plains;
                for(int i=0; i<N; i++){     // construct
                    char c1 = plain[i][a];  // every string
                    char c2 = plain[i][b];  // combination
                    char c3 = plain[i][c];  // of plain cows
                    plains.insert({c1, c2, c3});
                }
                for(int i=0; i<N; i++){     // check if any
                    char c1 = spotty[i][a]; // string of
                    char c2 = spotty[i][b]; // spotty cows
                    char c3 = spotty[i][c]; // match with plains
                    if(plains.count({c1, c2, c3}))
                        explain = false;
                }
                ans += explain;
            }
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}