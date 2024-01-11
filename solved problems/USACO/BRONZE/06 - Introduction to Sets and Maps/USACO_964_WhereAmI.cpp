/*
Combines Binary Search with Simulation
The Binary Search implementation is based on CPH
*/
#include <bits/stdc++.h>
using namespace std;

int N;
string s;

bool ok(int k){ // Test if all substrings of size k are unique
    set<string> boxes;
    for(int i=0; i<=N-k; i++){
        string sub = s.substr(i, k);
        if(boxes.count(sub)) // Found non-unique substring
            return false;
        boxes.insert(sub);
    }
    return true;
}

signed main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    
    cin >> N >> s;
    int k = -1;
    for(int leap=N; leap>=1; leap/=2) // Binary Search the answer
        while(!ok(k+leap)) k += leap;
    k++;
    cout << k << '\n';
}
