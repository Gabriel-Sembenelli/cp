/*
Note that positions 1 and 2 are "tied", i.e., the characters in these positions
will always be adjacent, no matter what we do. The same is true for (3,4), (5,6)
and so on. So we can analyze every 2-characters, rather than one by one.

Now we look at each possible tied pair. When an operation is applied to a prefix
that includes:
- a (G,H) pair, it will be transformed in a (H,G) pair, which is BETTER for John
- a (H,G) pair, it will be transformed in a (G,H) pair, which is WORSE for John
- a (G,G) pair, it will remain the same, and make NO DIFFERENCE for John
- a (H,H) pair, it will remain the same, and make NO DIFFERENCE for John

So we can ignore every (G,G) and (H,H) pairs.

Then, I decided to remap
(G,H) -> 1 (because G is in odd position, needing 1 operation)
(H,G) -> 0 (because G is already in an even position, needing 0 operations)

Then, the sample input will look like:
GGGHGHHGHHHGHG
GG GH GH HG HH HG HG
.  1  1  0  .  0  0
11000

Note that every input will be transformed into a binary string. Then all we need
to do is to choose prefixes to reverse and make this string contain only zeros.
When doing an operation, we reverse the order of the prefix, but also toggle all
0's to 1's and vice versa.

So we note that a prefix of only 1's can turn into a prefix of only 0's in 1 op.
                                 0's                                1's

Then, for an input as follows:
00001110001110000
we just do:
(1111)1110001110000
(0000000)0001110000
(1111111111)1110000
(0000000000000)0000

Which can be implemented almost the same way as the problem 1012 "Mad Scientist"
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int N; cin >> N;
    string s; cin >> s;
    vector<int> aux;
    
    for(int i=0; i<N; i+=2){
        if(s[i] == 'G' and s[i+1] == 'H') aux.push_back(1);
        if(s[i] == 'H' and s[i+1] == 'G') aux.push_back(0);
    }
    
    int M = int(size(aux));
    int ans = 0;
    for(int i=0; i<M;){
        while(i < M and aux[i] == 0) i++;
        if(i == M) break;
        if(i > 0) ans++;
        
        while(i < M and aux[i] == 1) i++;
        ans++;
    }
    
    cout << ans << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
