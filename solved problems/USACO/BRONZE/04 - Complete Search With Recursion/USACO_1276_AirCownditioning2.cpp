/*
Approach: M<=10, so it's possible to Complete Search all
possible subsets of ACs
*/
#include <bits/stdc++.h>
using namespace std;

struct Ac {
    int L, R, cool, cost;
};

int N, M, ans = INT_MAX;
vector<int> need(123);
vector<Ac> ac(11), chosen;

void search(int i){
    // Reached last AC
    if(i == M){
        vector<int> need2 = need; // Maintain original needs for future searches
        int aux = 0;
        for(auto a:chosen){
            aux += a.cost;              // Account each chosen AC
            for(int i=a.L; i<=a.R; i++) // Cooling all its
                need2[i] -= a.cool;     // working range
        }
        // Only updates answer if all needs were met
        if(*max_element(begin(need2), end(need2)) <= 0)
            ans = min(ans, aux);
        return;
    }
    search(i+1);        // Search without current AC
    chosen.push_back(ac[i]);
    search(i+1);        // Search with current AC
    chosen.pop_back();  // Don't forget to pop it
}

signed main(){
    cin >> N >> M;
    
    // Building vector of cow needs accross all stalls
    while(N--){
        int l, r, c; cin >> l >> r >> c;
        need[l] += c;
        need[r+1] -= c;
    }
    for(int i=1; i<=100; i++)
        need[i] += need[i-1];
    
    // Saving all ACs
    for(int i=0; i<M; i++){
        Ac &a = ac[i];
        cin >> a.L >> a.R >> a.cool >> a.cost;
    }
    
    // Begins Complete Search from the first AC
    search(0);
    
    cout << ans << '\n';
    
    return 0;
}
