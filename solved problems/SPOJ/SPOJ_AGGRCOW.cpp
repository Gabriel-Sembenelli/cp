#include <bits/stdc++.h>
using namespace std;

#define endl '\n';
#define int long long

int n, c;
vector<int> stall(1e5+1);

bool da(int dist){
    int placed = 0;
    int livre = -1;
    for(int i=0; i<n; i++){
        if(stall[i] >= livre){
            placed++;
            livre = stall[i] + dist;
        }
    }
    if(placed >= c) return true;
    return false;
}

void solve(){
    cin>>n>>c;
    for(int i=0; i<n; i++) cin>>stall[i];
    sort(stall.begin(), stall.begin()+n);
    
    int l=0, r=1e9, m=(l+r+1)/2;
    while(l<r){
        m = (l+r+1)/2;
        if(da(m)){
            l = m;
        }else{
            r = --m;
        }
    }
    cout << m << endl;
}

signed main(){
    int t; cin >> t; while(t--)
    solve();
    
    return 0;
}
