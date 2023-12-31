#include <bits/stdc++.h>
using namespace std;

#define int long long

// Sol 2
signed main(){
    unordered_map<string, int> stnums = {   {"one",     '1'},
                                            {"two",     '2'},
                                            {"three",   '3'},
                                            {"four",    '4'},
                                            {"five",    '5'},
                                            {"six",     '6'},
                                            {"seven",   '7'},
                                            {"eight",   '8'},
                                            {"nine",    '9'}};
    string s;
    int ans = 0;
    while(cin >> s){
        int lind=1e9, rind=-1;
        int n = s.size();
        string aux = "..";
        for(int i=0; i<n; i++){
            if('0' <= s[i] && s[i] <= '9')
                aux[1] = s[i];
            for(int j=3; j<=5; j++){
                string t = s.substr(i, min(j, n-i));
                if(stnums[t])
                    aux[1] = stnums[t];
            }
        }
        for(int i=n-1; i>=0; i--){
            if('0' <= s[i] && s[i] <= '9')
                aux[0] = s[i];
            for(int j=3; j<=5; j++){
                string t = s.substr(i, min(j, n-i));
                if(stnums[t])
                    aux[0] = stnums[t];
            }
        }
        ans += stoi(aux);
    }
    
    return 0;
}
