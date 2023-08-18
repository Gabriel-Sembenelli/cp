const int INF = 0x3f3f3f3f;

void mergesort(vector<int> &v){
    int n = v.size();
    if(n==1) return;
    vector<int> a, b;
    for(int i=0; i<n; i++){
        if(i<n/2) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    mergesort(a);
    mergesort(b);
    a.push_back(INF);
    b.push_back(INF);
    for(int ia=0, ib=0, iv=0; iv<n; iv++){
        if(a[ia] < b[ib]) v[iv] = a[ia++];
        else v[iv] = b[ib++];
    }
}
