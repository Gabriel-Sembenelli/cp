#include <bits/stdc++.h>
using namespace std;

signed main(){
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    
    map<string, int> cows = {   {"Bessie",      0},
                                {"Elsie",       0},
                                {"Daisy",       0},
                                {"Gertie",      0},
                                {"Annabelle",   0},
                                {"Maggie",      0},
                                {"Henrietta",   0}};
    
    int N; cin >> N;
    
    // Calculating milk productions
    while(N--){
        string s; cin >> s;
        int m; cin >> m;
        cows[s] += m;
    }
    // Finding all production values and how many cows had that value
    map<int, int> productions; // {value, qCows}
    for(auto [c,m]:cows) productions[m]++;
    
    // If they all tied, it's a tie
    if(size(productions) == 1){
        cout << "Tie\n";
        return 0;
    }
    // If more than 1 cow had the second-lowest productions, it's also a tie
    int secLow = (++begin(productions))->first;
    if(productions[secLow] > 1){
        cout << "Tie\n";
        return 0;
    }
    // Iterating to find the unique cow with the secons-lowest production
    for(auto [c,m]:cows){
        if(m == secLow){
            cout << c << '\n';
            return 0;
        }
    }
}
