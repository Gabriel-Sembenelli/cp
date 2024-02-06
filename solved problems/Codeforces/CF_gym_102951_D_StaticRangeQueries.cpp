/*
Sources:
https://codeforces.com/gym/102951/problem/D
https://usaco.guide/silver/sorting-custom#example-2

Topics:
Coordinate Compression, Prefix Sums, Binary Search

Solution:
There are two levels of prefix sums on this problem

The first N updates are handled in O(1) per update with Offline approach:
    pref[l] += v , pref[r] -= v

Then we accumulate over 'pref' 2 times, one to finish the earlier N queries, and
the second to precompute the array for the following Q queries, i.e., to make:
    pref[i] := a[0] + a[1] + ... + a[i-1]

This is the main idea of the solution. But the problem is that the coordinates
range is 1e9, so we need to use Coordinate Compression to take advantage of the
fact that Q is 1e5.

So, instead of using an array 'pref', we can use a map that only stores the
actual coordinates that appears on input. Let it be 'mp': x -> {curr, tot}
x    := coordinate
curr := the value that pref[x] would have on the first accumulation
tot  := the value that pref[x] would have on the second accumulation

Note that two adjacent elements in 'mp' can have coordinates really far apart,
we must take care of that in the calculations, for example:
mp = ..., {x, {currX, totX}}, {y, {currY, totY}}, ...
When iterating through 'mp' doing the first accumulation it's simple:
    currY += currX
When iterating through 'mp' doing the second accumulation, however:
    totY = totX + (y - x) * currX
because currX will occur in all points between x and y.

When doing the Q queries, we also need to be careful. The query can be about a
point that doesn't exist in 'mp'. So we can use Binary Search to find the
element that has the highest coordinate less than or equal (leq) to the
coordinate aksed. Let the coordinate asked be 'y' and the leq element be
{x, {currX, totX}}. We can answer the query by doing almost the same thing:
    ans = totX + (y - x) * currX
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int,pair<int,int>> mp;
#define curr first
#define tot second

int query(int x){
    if(x < begin(mp)->first) return 0; // Corner case: no leq element 
    
    auto leq = *(--mp.upper_bound(x)); // leq = {x,{curr,tot}}
    int leqX = leq.first;
    int leqCurr = leq.second.curr;
    int leqTot = leq.second.tot;
    
    return leqTot + (x - leqX) * leqCurr;
}

void solve(){
    int N, Q; cin >> N >> Q;
    while(N--){
        int l, r, v; cin >> l >> r >> v;
        mp[l].curr += v;
        mp[r].curr -= v;
    }
    
    int lastC = 0, lastTot = 0, lastX = 0;
    for(auto &[x,ct]:mp){
        ct.curr += lastC;                       // First accumulation
        ct.tot = lastTot + (x - lastX) * lastC; // Second accumulation
        
        lastC = ct.curr;
        lastTot = ct.tot;
        lastX = x;
    }
    
    while(Q--){
        int l, r; cin >> l >> r;
        cout << query(r) - query(l) << '\n';
    }
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}