/*
I made a HashMap {zodiac, index}, called it 'cycle'
Also made a HashMap {cow_name, year_of_birth}, called it 'birth'

Next, I set the birth of Bessie and then calculate the birth of the next cows
using some modular arithmetic.

This solution is only possible because the input order is in such a way that
new cows can be determined from previous determined ones, i.e., cow Y birth date
will be already fixed when determining X.

Time complexity: O(N)
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    unordered_map<string, int> birth;
    unordered_map<string, int> cycle = {{"Ox",0}, {"Tiger",1}, {"Rabbit",2},
        {"Dragon",3}, {"Snake",4}, {"Horse",5}, {"Goat",6}, {"Monkey",7},
        {"Rooster",8}, {"Dog",9}, {"Pig",10}, {"Rat",11}};
    
    int N; cin >> N;
    birth["Bessie"] = cycle["Ox"];
    
    while(N--){
        string X, __, when, cyc, Y;
        cin >> X >> __ >> __ >> when >> cyc >> __ >> __ >> Y;
        
        int zodX = cycle[cyc];    // Zodiac index of cow X
        
        int zodY = birth[Y] % 12; // Zodiac index of cow Y
        if(zodY < 0) zodY += 12;  // (birth[Y] may be negative)
        
        if(when == "next"){ // X was born after Y
            int dif = zodX - zodY;
            if(dif <= 0) dif += 12;    // We need a strictly positive difference
            birth[X] = birth[Y] + dif; // to sum
        }else{ // X was born before Y
            int dif = zodY - zodX;
            if(dif <= 0) dif += 12;    // We need a strictly positive difference
            birth[X] = birth[Y] - dif; // to subtract
        }
    }
    
    cout << abs(birth["Bessie"] - birth["Elsie"]) << '\n';
}

signed main(){
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
