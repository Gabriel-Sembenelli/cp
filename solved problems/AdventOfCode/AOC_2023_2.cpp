#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve1(){
    int ans=0, R=12, G=13, B=14;
    string s;
    while(cin >> s){
        bool possible = true;
        int id = 0;
        cin >> id;
        cin >> s; // ":"
        
        int r=0, g=0, b=0;
        while(true){
            int q = 0;
            string color;
            cin >> q >> color;
            
            if(color[0] == 'r') r += q;
            else if(color[0] == 'g') g += q;
            else b += q;
            
            if(r>R or g>G or b>B) possible = false;
            
            if(color.back() == ',') continue;
            else if(color.back() == ';') r = g = b = 0;
            else break;
        }
        
        if(possible) ans += id;
    }
    cout << ans << '\n';
}

void solve2(){
    int ans=0;
    string s;
    while(cin >> s){
        int id = 0;
        cin >> id;
        cin >> s; // ":"
        
        int r, g, b, R, G, B;
        r = g = b = R = G = B = 0;
        while(true){
            int q = 0;
            string color;
            cin >> q >> color;
            
            if(color[0] == 'r') r += q;
            else if(color[0] == 'g') g += q;
            else b += q;
            
            R = max(R, r);
            G = max(G, g);
            B = max(B, b);
            
            if(color.back() == ',') continue;
            else if(color.back() == ';') r = g = b = 0;
            else break;
        }
        ans += R * G * B;
    }
    cout << ans << '\n';
}

signed main(){
    solve2();
}