#include <bits/stdc++.h>
using namespace std;

typedef long long   ll;

#define endl        "\n"
#define dbg(var)    cout<<#var<<"="<<var<<" "
#define dbgv(var)   cout<<#var<<"=";for(auto e:var)cout<<" "<<e;cout<<endl

const int    INF    = 0x3f3f3f3f;
const ll     LINF   = 0x3f3f3f3f3f3f3f3f;
const int    MOD    = 1e9+7;

string str;

vector<long long> esq(41);  // esq[i] 'l' da query 'i' (primeiro 'l' é o l[1])
vector<long long> dir(41);  // dir[i] 'r' da query 'i' (primeiro 'r' é o r[1])

long long findIndex(long long k, vector<long long> &tam){
    long long ret = lower_bound(tam.begin(), tam.end(), k) - tam.begin();
    if(tam[ret] < k) ret++;
    return ret;
}

char query(long long s, long long k, vector<long long> &tam){
    if(s == 0) return str[k-1];
    long long newK = esq[s] + k - tam[s-1] -1;
    long long newS = findIndex(newK, tam);
    //dbg(newS); dbg(newK) << endl;
    return query(newS, newK, tam);
}


void solve(int test_case=1){
    int n, c, q; cin >> n >> c >> q;
    cin >> str;
    vector<long long> tam(c+1);  // tam[i] = tamanho da string s[i] (string original é s[0])
    tam[0] = str.size();
    for(int i=1; i<=c; i++){
        long long l, r; cin >> l >> r;
        esq[i] = l; dir[i] = r;
        tam[i] = tam[i-1] + (r-l+1);
    }
    //dbgv(tam);
    while(q--){
        long long k; cin >> k;
        long long index = findIndex(k, tam);
        //dbg(index); dbg(k) << endl;
        cout << query(index, k, tam) << endl;
        // faz o lower_bound pra saber qual indice de tam ele cai
        // faz s[n][q] = s[n-1][esq[n]+q-tam[n-1]-1]; até chegar em s[0]
    }
}


int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1; i<=t; i++){
        solve(i);
    }
    return 0;
}