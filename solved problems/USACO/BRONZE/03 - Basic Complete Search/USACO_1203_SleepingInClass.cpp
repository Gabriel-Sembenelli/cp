#include <bits/stdc++.h>
using namespace std;

// Following Editorial's idea because I didn't know "what" to search
void solve(){
    int N; cin >> N;
    int sum = 0;
    int a[N]; for(auto &e:a) cin >> e, sum += e;
    if(sum == 0){
        cout << 0 << '\n';
        return;
    }
    // We need to search the final number that appears in all entries
    int num = 1;
    while(num++ < sum){
        if(sum % num) continue; // This line greatly reduces runtime
        int curr = -1, op = 0;
        bool ok = true;
        for(int i=0; i<N; i++){
            // take first or merge
            if(curr < 0){
                curr = a[i];
            }else if(curr < num){
                curr += a[i];
                op++;
            }
            // check consistency
            if(curr == num){
                curr = -1;
            }
            if(curr > num){
                ok = false;
                break;
            }
        }
        if(curr != -1)
            ok = false;
        if(ok){
            cout << op << '\n';
            return;
        }
    }
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}

/*
Observations:
For a testcase like:
    100000
    1 1 1 ... 1 1 1 900001
If we don't use line 16, the code will iterate the entire array for each num
until reach num == 1e6, i.e., will make 1e6*1e5=1e11 operations

However, with line 16 the code only iterate the array when a divisor of sum
is found. As the sum can go up to 1e6, we know that the maximum number of
divisors the sum can have is 240, i.e, the code will make 240*1e5~2e7 operations
https://oeis.org/search?q=240+maximal+divisors
*/