#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve1(){
    int ans = 0;
    string card;
    while(cin >> card){ // "Card"
        cin >> card;    // " x:"
        set<int> win;
        for(int i=0; i<10; i++){
            int n; cin >> n;
            win.insert(n);
        }
        cin >> card; // " | "
        int pts = 0;
        for(int i=0; i<25; i++){
            int n; cin >> n;
            if(win.count(n)){
                if(pts == 0) pts = 1;
                else pts *= 2;
            }
        }
        ans += pts;
    }
    cout << ans << '\n';
}

int copies[300];

void solve2(){
    int ans = 0;
    string card;
    int id = 0;
    while(cin >> card){ // "Card"
        cin >> card;    // " x:"
        id++;
        copies[id]++;
        set<int> win;
        for(int i=0; i<10; i++){
            int n; cin >> n;
            win.insert(n);
        }
        cin >> card; // " | "
        int pts = 0;
        for(int i=0; i<25; i++){
            int n; cin >> n;
            if(win.count(n)) pts++;
        }
        
        for(int i=id+1; i<id+1+pts; i++)
            copies[i] += copies[id];
        
        ans += copies[id];
    }
    cout << ans << '\n';
}

signed main(){
    solve2();
} 