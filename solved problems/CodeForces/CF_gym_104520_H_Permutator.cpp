/*
Note that the first position appears in N subarrays
the second position appears in 2*(N-1) subarrays
the third position appears in 3*(N-2) subarrays
... and so on ...

Why:
Lets look at the first element of array A.
This element appears in N subarrays because that's all the possible suffixes
that we can take off the original array A.
The same can be thought for the last element and prefixes of A.
So, for an element at the middle of A, lets say A[j], we can just look at the
subarrays A[1..j] and A[j..N], do the same logcic separately and then multiply
the results. That's true because all subarrays of A[1..j] that contains j can be
combined with all the subarrays of A[j..N] that contains j to form all subarrays
of A that contains j.

So, the k-th element in the resulting array A*B will appear k*(N-k+1) times.
Thus, we can early multiply each A[i] by it's number of ocurrences, and then
adjust array B according to the new array.
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int N; cin >> N;
    vector<int> A(N), B(N);
    
    for(int i=0; i<N; i++){
        cin >> A[i];
        A[i] *= (i+1)*(N-i); // Number of occurrences of A[i] in the expression
    }
    
    for(int i=0; i<N; i++)
        cin >> B[i];
    
    sort(begin(A), end(A));     // Increasing
    sort(rbegin(B), rend(B));   // Decreasing
    
    int ans = 0;
    for(int i=0; i<N; i++)
        ans += A[i] * B[i];
    
    cout << ans << '\n';
}
