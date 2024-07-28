/*
Pra testar:
https://www.codechef.com/practice/course/sorting/SORTING/problems/TSORT
*/
#include <bits/stdc++.h>
using namespace std;

#define sz(V) (int)(V.size())
#define int long long
using vi = vector<int>;

void mostra(vi &A, int l=-1, int m=-1, int r=-1){
    int n = sz(A) - 1;
    for(int i=1; i<=n; ++i){
        if      (i   == l) cout << '(';
        else if (i-1 == m) cout << '/';
        else if (i-1 == r) cout << ')';
        else               cout << ' ';
        cout << A[i];
    }
    if(r == n) cout << ')';
    cout << '\n';
}

void intercala(vi &A, int l, int m, int r){
    vi B(r - l + 2);
    {
        int i = l, iB = 1;
        for(; i <= m; ++i, ++iB)
            B[iB] = A[i];
        for(; i <= r; ++i, ++iB)
            B[iB] = A[r - i + m + 1];
    }
    //mostra(A, l, m, r);
    for(int i=1, j=sz(B)-1, k=l; i<=j;){
        if(B[i] <= B[j] and i <= m-l+1) A[k++] = B[i++];
        else                            A[k++] = B[j--];
    }
    //mostra(A, l, -1, r); cout << '\n';
}

signed main(){
    int n; cin >> n;
    vi A(n+1);
    for(int i=1; i<=n; ++i)
        cin >> A[i];
    //mostra(A); cout << '\n';
    for(int half = 1; half < n; half *= 2){
        int l = 1, m = half, r = min(n, 2 * half);
        while(m < n){
            intercala(A, l, m, r);
            l = r+1;
            m = l + half - 1;
            r = min(n, l + 2 * half - 1);
        }
    }
    for(int i=1; i<=n; ++i) cout << A[i] << ' '; cout << '\n';
    
    return 0;
}
