#include <bits/stdc++.h>
using namespace std;

#define int long long
#define I first
#define J second

vector<string> matrix;
int n, m;

int check1(pair<int,int> &ini, pair<int,int> &fim){
    bool possible = false;
    for(int i=ini.I-1; i<=fim.I+1; i++){
        for(int j=ini.J-1; j<=fim.J+1; j++){
            if(i<0 or j<0 or i>=n or j>=m) continue;
            if(i==ini.I and ini.J<=j and j<=fim.J) continue;
            char c = matrix[i][j];
            if(c!='.')
                possible = true;
        }
    }
    int ret = 0;
    for(int i=ini.I, j=ini.J; j<=fim.J; j++){
        ret *= 10;
        ret += (int)(matrix[i][j]-'0');
    }
    ini = {-1,-1};
    fim = {-1,-1};
    if(!possible) return 0;
    return ret;
}

void solve1(){
    string s;
    while(cin >> s) matrix.push_back(s);
    n = matrix.size();
    m = matrix[0].size();
    int ans = 0;
    
    pair<int, int> ini={-1,-1}, fim={-1,-1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c = matrix[i][j];
            
            if(ini == make_pair(-1LL,-1LL)){
                if('0' <= c and c <= '9')
                    ini = {i, j};
            }else if(!('0' <= c and c <= '9')){
                fim = {i, j-1};
            }else if(j == m-1){
                fim = {i, j};
            }
            
            if(fim != make_pair(-1LL,-1LL))
                ans += check1(ini, fim);
        }
    }
    
    cout << ans << '\n';
}

map<int, vector<int>> gears;

void check2(pair<int,int> &ini, pair<int,int> &fim){
    int num = 0;
    for(int i=ini.I, j=ini.J; j<=fim.J; j++){
        num *= 10;
        num += (int)(matrix[i][j]-'0');
    }
    
    for(int i=ini.I-1; i<=fim.I+1; i++){
        for(int j=ini.J-1; j<=fim.J+1; j++){
            if(i<0 or j<0 or i>=n or j>=m) continue;
            char c = matrix[i][j];
            if(c == '*')
                gears[i*m+j].push_back(num);
        }
    }
    ini = {-1,-1};
    fim = {-1,-1};
}

void solve2(){
    string s;
    while(cin >> s) matrix.push_back(s);
    n = matrix.size();
    m = matrix[0].size();
    int ans = 0;
    
    pair<int, int> ini={-1,-1}, fim={-1,-1};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c = matrix[i][j];
            
            if(ini == make_pair(-1LL,-1LL)){
                if('0' <= c and c <= '9')
                    ini = {i, j};
            }else if(!('0' <= c and c <= '9')){
                fim = {i, j-1};
            }else if(j == m-1){
                fim = {i, j};
            }
            
            if(fim != make_pair(-1LL,-1LL))
                check2(ini, fim);
        }
    }
    for(auto [fi,v]:gears)
        if(v.size() == 2)
            ans += v[0] * v[1];
    
    cout << ans << '\n';
}

signed main(){
    solve2();
}