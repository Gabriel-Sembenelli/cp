#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s; cin >> s;
    int ans = 0;
    for(char a='A'; a<='Z'; a++){       // iterate over each
        for(char b=a+1; b<='Z'; b++){   // character pair
            string tmp;
            string t1 = {a,b,a,b};  // the pair (a,b) is crossing iff
            string t2 = {b,a,b,a};  // they appear alternating in s
            for(auto c:s)
                if(c == a or c == b)
                    tmp += c;
            if(tmp == t1 or tmp == t2)
                ans++;
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}