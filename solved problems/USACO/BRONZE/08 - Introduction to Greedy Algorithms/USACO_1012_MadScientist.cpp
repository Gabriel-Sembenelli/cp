/*
Note that correct segments and wrong segments will always appear alternating.

OOOXXXXOOXXXXOXXXOXOOOOXXOO

If we have W wrong segments and flip them one by one, we will use W operations.
If we flip everything from the first to the last wrong in 1 operation, then we
will also need to flip the W-1 segments in between that were previously correct,
making again W operations in total.

So just count the number of wrong segments.
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    string A, B; cin >> A >> B;
    int ans = 0;
    for(int i=0; i<N;){
        while(i < N and A[i] == B[i]) i++; // Correct segment
        if(i == N) break;
        while(i < N and A[i] != B[i]) i++; // Wrong segment
        ans++;
    }
    cout << ans << '\n';
}

signed main(){
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
