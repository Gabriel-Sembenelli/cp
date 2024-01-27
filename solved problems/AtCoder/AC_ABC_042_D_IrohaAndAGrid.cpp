/*
Combinatorics, Modular Arithmetic

If you know how to solve the easier case when there's no forbidden cells, it is
possible to reduce the actual problem into several simpler ones.

Let's imagine we are at (0,0) and need to go to (M,N), only going down or right.
In this case, there's no forbidden cells.
Note that any solution will have exactly M+N moves, where M of them are down
moves and N of them are right moves.
Every other solution can be obtained by permutations of a particular solution.
Note that this is a permutation with repetition, i.e., the number of ways of
going from (0,0) to (M,N) is given by the formula:
    (M+N)! / (M!N!)

Now let's think how to solve the actual problem.
We have a grid with H rows and W columns (0-indexed)
The forbidden rectangle has corners (H-1, 0) and (H-A, B-1).
We can split the free area into other two rectangles:
    (H-A-1, 0), (0, B-1)
    (H-1, B), (0, W-1)
Basically, I am trying to say to imagine the grid like this:

Y Y Y Y Z Z Z
Y Y Y Y Z Z Z
X X X X Z Z Z
X X X X Z Z Z
X X X X Z Z Z

Where X is forbidden, and Y,Z define the two free rectangles.

Now we can combine the number of ways of going from (0,0) to the rightmost cells
of Y, with the number of ways of going from the leftmost cells of Z to (H-1,W-1)

I.e., calculate the number of ways of going from cell 0 to 1, and multiply with
the number of ways of going from cell 2 to cell 3:

0 Y Y 1 2 Z Z
Y Y Y Y Z Z Z
X X X X Z Z Z
X X X X Z Z Z
X X X X Z Z 3

Do the same here:

0 Y Y Y Z Z Z
Y Y Y 1 2 Z Z
X X X X Z Z Z
X X X X Z Z Z
X X X X Z Z 3

And we are done.

Basically, do this for every (1,2) pair that can exist, i.e., from row 0 to
row H-A-1.

Also note that the paths 0-1 and 2-3 fall in the simple case.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
int fact[MAX];

// Just to make modular multiplication more aesthetic
int modMul(int a, int b){ return (a * b) % MOD; }

// Saving factorials in an array to speed up the calculations
void initFact(){
    fact[0] = 1;
    for(int i=1; i<MAX; i++)
        fact[i] = modMul(fact[i-1], i);
}

// Modular inverse of 'x', using Fermat's Little Theorem:
// If 'p' is prime, then a^(p-1) = 1 (mod p)
// Rearrange this to a*a^(p-2) = 1 (mod p),
// i.e., a^(p-2) is the modular inverse of 'a'.
// Yes, 1e9+7 is prime, so we can do this.
int modInv(int x){
    int exp = MOD - 2;
    int base = x;
    x = 1;
    while(exp){
        if(exp & 1)
            x = modMul(x, base);
        base = modMul(base, base);
        exp >>= 1;
    }
    return x;
}

// returns (R+D)! / (R!D!)
int Comb(int R, int D){
    int num = fact[R+D];
    int den = modMul(fact[R], fact[D]);
    return modMul(num, modInv(den));
}

void solve(){
    initFact();
    int H, W, A, B; cin >> H >> W >> A >> B;
    int ans = 0;
    for(int y=0; y<H-A; y++)
        ans = (ans + modMul(Comb(B-1, y), Comb(W-1-B, H-1-y))) % MOD;
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
