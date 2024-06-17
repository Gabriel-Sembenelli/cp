/*
https://usaco.guide/bronze/intro-graphs#problem-usaco-833

Trees, Implementation, basic LCA.

This problem involves finding ancestors and some implementation.

First, I defined levels for all cows.
Cows that have no ancestors (roots) are level 0 and so on.

Now we find the LCA (Lowest Common Ancestor) of the two input cows, storing some
useful informations on the way.
The idea I used to find LCA was to first make the two cows be on the same level.
You need to store how many operations were necessary to level them, to later
define the great-great-... quantity. (I called it 'tolvl')
Now that they are leveled we make them go up the tree at the same time, until
they are the same. (if this never happen they are unrelated)
You need to store how many operations were necessary to join them, to later
define the relation mother/sibling/aunt/cousin. (I called it 'tojoin')

relation    tolvl   tojoin
MOTHER:     >0      0
SIBLINGS:   0       1
AUNT        >0      1
COUSINS     any     >1
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(x) (int)size(x)
#define all(x) begin(x), end(x)

map<string, vector<string>> adjDown;
map<string, string> adjUp;
map<string, int> level;
set<string> cows;

void dfsDown(string at, int lv){
    level[at] = lv;
    for(auto to:adjDown[at])
        dfsDown(to, lv+1);
}

void solve(){
    int N; cin >> N;
    string A, B; cin >> A >> B;
    while(N--){
        string a, b; cin >> a >> b;
        adjDown[a].push_back(b);
        adjUp[b] = a;
        cows.insert({a,b});
    }
    
    for(auto c:cows) if(sz(adjUp[c]) == 0)  // Finding roots
        dfsDown(c, 0);                      // Defining levels
    
    if(level[A] > level[B]) swap(A, B);
    string x=A, y=B;
    
    int tolvl = 0;
    while(level[x] < level[y]){ // Leveling x and y
        y = adjUp[y];
        ++tolvl;
    }
    
    int tojoin = 0;
    while(x != y and level[x]){ // Joining x and y if possible
        x = adjUp[x];
        y = adjUp[y];
        ++tojoin;
    }
    
    if(x != y){ cout << "NOT RELATED\n"; return; }
    
    if(tojoin == 0){
        cout << A << " is the ";
        while(--tolvl) cout << (tolvl > 1 ? "great-" : "grand-");
        cout << "mother of " << B << '\n';
        return;
    }
    
    if(tojoin == 1){
        if(tolvl == 0){ cout << "SIBLINGS\n"; return; }
        
        cout << A << " is the ";
        while(--tolvl) cout << "great-";
        cout << "aunt of " << B << '\n';
        return;
    }
    
    cout << "COUSINS\n";
}

void setIO(string file = ""){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        auto i = freopen((file + ".in").c_str(), "r", stdin);
        auto o = freopen((file + ".out").c_str(), "w", stdout);
    }
}

signed main(){
    setIO("family");
    //int t; cin >> t; while(t--)
    solve();
    return 0;
}
