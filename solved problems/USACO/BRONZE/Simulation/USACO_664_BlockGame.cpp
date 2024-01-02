#include <bits/stdc++.h>
using namespace std;

// For each board, count how many letters each side needs
// and add the maximums in the answer vector.
void solve(){
    int n; cin >> n;
    vector<int> letters(26);
    while(n--){
        string s1, s2; cin >> s1 >> s2;
        vector<int> aux1(26), aux2(26);
        for(auto c:s1) aux1[c-'a']++;
        for(auto c:s2) aux2[c-'a']++;
        for(int i=0; i<26; i++) letters[i] += max(aux1[i], aux2[i]);
    }
    for(auto q:letters) cout << q << '\n';
}

signed main(){
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
} 