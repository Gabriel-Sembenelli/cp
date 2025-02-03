#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)(x).size()
#define all(x)  begin(x), end(x)

const int MOD = 1e9 + 7;

// Gera um vetor de 'n' números em [1..MOD-1] tais que qualquer sequência de operações resulta num valor único.
pair<vector<int>, map<int, int>> gen(int n) {
    vector<int> v(n);
    map<int, int> mp;
    bool flag = true;
    while(flag){
        flag = false;
        mp.clear();
        for(auto& e : v) e = (rand() % (MOD - 1)) + 1;
        for(int mask = 0; mask < (1 << n); ++mask){
            int calc = 0;
            for(int b = 1, at = 0; b < (1 << n); b <<= 1, ++at){
                if(mask & b) calc = (calc + v[at]) % MOD;
                else         calc = (calc * v[at]) % MOD;
            }
            if(!mp.count(calc)) mp[calc] = mask;
            else flag = true; // Checa se duas sequências de operações colidiram, i.e., deram o mesmo resultado.
        }
    }
    return {v, mp};
}

void solve(){
    int n; cin >> n;
    int rem = n;
    vector<int> v(n + 1);
    string ans(n + 1, '.');
    pair<vector<int>, map<int, int>> g = gen(15);
    vector<int> query = g.first;
    map<int, int> mp = g.second;
    while(rem){ // Resolve da direita pra esquerda.
        int q = min(rem, 15ll);
        if(q < 15){ g = gen(q); query = g.first, mp = g.second; }
        for(int i = rem - q + 1, j = 0; j < q; ++i, ++j)
            v[i] = query[j];
        for(int i = rem + 1; i <= n; ++i){
            if(ans[i] == '+') v[i] = 0; // Elementos neutros, usados para 'ignorar'
            else              v[i] = 1; // operadores à direita que já foram descobertos.
        }
        cout << "?"; for(auto e : v) cout << ' ' << e; cout << '\n'; cout << flush;
        int calc; cin >> calc;
        int mask = mp[calc];
        for(int i = rem - q + 1, b = 1; b < (1 << q); ++i, b <<= 1){
            if(b & mask) ans[i] = '+';
            else         ans[i] = 'x';
        }
        rem -= q;
    }
    cout << "! "; for(int i = 1; i <= n; ++i) cout << ans[i]; cout << '\n'; cout << flush;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
