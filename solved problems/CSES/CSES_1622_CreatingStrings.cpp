#include <bits/stdc++.h>
using namespace std;
 
signed main(){
    string s; cin >> s;
    sort(begin(s), end(s));
    vector<string> ans;
    do{                     // generate and save all permutations in
        ans.push_back(s);   // lexicographical order whithout repetitions
    }while(next_permutation(begin(s), end(s)));
    
    cout << size(ans) << '\n';
    for(auto a:ans) cout << a << '\n';
    
    return 0;
}