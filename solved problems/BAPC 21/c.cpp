#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)

const int INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
vector<string> grid;
vector<vector<int>> dp;

// check if cans overlap and if cans cover grid
bool valid(int row, int mask){
    // overlap
    for(int b = 1, last = 1; b < (1 << m); b <<= 1){
        int curr = b & mask;
        if(curr && last) return 0;
        last = curr;
    }
    // grid cover
    for(int col = m - 1, b = 1; col >= 0; --col, b <<= 1){
        if(grid[row][col] == '#' || grid[row - 1][col] == '#')
            if(!((mask & b) || (mask & (b << 1))))
                return 0;
    }
    return 1;
}

bool support(int lowmask, int himask){
    for(int b = 1; b < (1 << m); b <<= 1){
        if(himask & b)
            if(!((lowmask & (b >> 1)) || (lowmask & b) || (lowmask & (b << 1))))
                return 0;
    }
    return 1;
}

signed main(){
    cin >> n >> m;
    grid.assign(n, "");
    for(auto& linha : grid) cin >> linha;
    dp.assign(n, vector<int>(1 << m));
    int ans = INF;
    for(int mask = 0; mask < (1 << m); ++mask){
        auto& dpm = dp[n - 1][mask];
        dpm = INF;
        if(!valid(n - 1, mask)) continue;
        dpm = min(dpm, (int)__builtin_popcountll(mask));
        ans = min(ans, dpm); // if n == 2;
    }
    if(n > 2) ans = INF;
    for(int i = n - 3; i >= 1; i -= 2){
        for(int mask = 0; mask < (1 << m); ++mask){
            auto& dpm = dp[i][mask];
            dpm = INF;
            if(!valid(i, mask)) continue;
            for(int lowmask = 0; lowmask < (1 << m); ++lowmask)
                if(dp[i + 2][lowmask] < INF && support(lowmask, mask))
                    dpm = min(dpm, __builtin_popcountll(mask) + dp[i + 2][lowmask]);
            if(i == 1) ans = min(ans, dpm);
        }
    }
    cout << ans << '\n';
    return 0;
}
