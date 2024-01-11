/*
My thought process was quite complex, so maybe it's more worth looking at the
Official Solution.
https://usaco.guide/problems/usaco-892-sleepy-cow-sorting/solution

My approach:
Imagine that we are looking at the current order.
The first cow we want to see is cow 1, then 2, and so on.
Now, what if we want to see the k-th cow but we encounter some other?
Then we will need to move all previous cows to correct the position of the
current one.
Depending on the input, the correct place of all previous cows may vary, but
note that each cow will need at most one move if our choices are optimal.
So my approach is to simulate this process.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    vector<int> seen(N+2);
    int want = 1; // Which cow I want to see now
    
    int curr = 0; // How many cows were ordered in the past but will
                  // need to be moved if I encounter a wrong cow
    
    int ans = 0;
    for(int i=0; i<N; i++){
        int cow; cin >> cow;
        seen[cow] = 1;
        
        if(cow == want){ // If this is the cow I want to see
            curr++; // Then the current ordered group increase
            want++; // I want to see the next
            while(seen[want]) // This is like if we encountered greater
                want++;       // unordered cows in the past and already
                              // optimally positioned them
        
        }else{ // This isn't the cow I want to see
            ans += curr + 1; // So i move the entire ordered group to the
                             // optimal position, as well as this cow
            curr = 0; // Start counting a new group
        }
    }
    cout << ans << '\n';
}

signed main(){
    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
