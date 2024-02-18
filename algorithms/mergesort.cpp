// Noob version
void mergesort(vector<int> &v){
    int n = v.size();
    
    if(n == 1) return;                      // Base Case
    
    vector<int> a, b;                       // Splitting 'v' into 'a' and 'b'
    for(int i=0; i<n; i++){
        if(i < n/2) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    
    mergesort(a);                           // Recursing to 'a' and 'b'
    mergesort(b);
    
    a.push_back(INT_MAX);                   // Merging 'a' and 'b' into 'v'
    b.push_back(INT_MAX);
    for(int ia=0, ib=0, iv=0; iv<n; iv++){
        if(a[ia] < b[ib]) v[iv] = a[ia++];
        else v[iv] = b[ib++];
    }
}

// Pro version
#define all(V)  begin(V), end(V)
void mergesort(vector<int> &v){
    int n = v.size();
    if(n == 1) return;
    vector<int> a(begin(v)      , begin(v) + n/2);
    vector<int> b(begin(v) + n/2, end(v)        );
    mergesort(a);
    mergesort(b);
    merge(all(a), all(b), begin(v)); // STL
}