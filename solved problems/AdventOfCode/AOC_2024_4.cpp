#include <bits/stdc++.h>
using namespace std;

#define int     long long
#define sz(x)   (int)size(x)
#define all(x)  begin(x), end(x)
using ll = long long;

void solve(){
    deque<string> grid;
    {
        string tmp;
        while(cin >> tmp)
            grid.push_back("..." + tmp + "...");
        tmp = string(sz(grid[0]), '.');
        for(int i = 0; i < 3; ++i)
            grid.push_back(tmp), grid.push_front(tmp);
    }
    vector<int> dx = {1,1,0,-1,-1,-1,0,1};
    vector<int> dy = {0,1,1,1,0,-1,-1,-1};
    int ans = 0;
    for(int i = 3; i < sz(grid[0]) - 3; ++i){
        for(int j = 3; j < sz(grid) - 3; ++j){
            for(int d = 0; d < 8; ++d){
                string tmp = "";
                for(int s = 0, x = i, y = j; s < 4; ++s, x += dx[d], y += dy[d]){
                    tmp += grid[x][y];
                }
                ans += (tmp == "XMAS");
            }
        }
    }
    cout << ans << '\n';
}

void solvee(){
    vector<string> grid;
    {
        string tmp;
        while(cin >> tmp)
            grid.push_back(tmp);
    }
    int ans = 0;
    for(int i = 0; i < sz(grid[0]) - 2; ++i){
        for(int j = 0; j < sz(grid) - 2; ++j){
            string x = {grid[i][j], grid[i+1][j+1], grid[i+2][j+2]};
            string y = {grid[i][j+2], grid[i+1][j+1], grid[i+2][j]};
            ans += (x == "MAS" || x == "SAM") && (y == "MAS" || y == "SAM");
        }
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int t; cin>>t; while(t--)
    solvee();
    return 0;
}
