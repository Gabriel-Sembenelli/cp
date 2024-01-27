# A
```cpp
#define int long long

signed main(){
    int n;
    cin >> n;
    vector<pair<int, string>> control(n);
    for(auto &[a, b] : control){
        cin >> b;
        a = b.size();
    }
    sort(control.begin(), control.end());
    for(auto &[a, b] : control){
        cout << b << '\n';
    }
}

```

# B
```cpp
struct Pt{
    int x, y, id;
    
    Pt(int _x, int _y, int _id):x(_x), y(_y), id(_id){}
    Pt(){}
    
    int dist2(){ return x*x + y*y; }
};

bool cmp(Pt a, Pt b){
    if(a.dist2() == b.dist2())
        return a.id < b.id;
    return a.dist2() <= b.dist2();
}

void solve(){
    int N; cin >> N;
    vector<Pt> pts(N);
    for(int i=0; i<N; i++){
        int X, Y; cin >> X >> Y;
        pts[i] = {X, Y, i};
    }
    sort(begin(pts), end(pts), cmp);
    for(auto p:pts)
        cout << p.x << ' ' << p.y << '\n';
}
```

# C
```cpp
#define int long long

signed main(){
    int n;
    cin >> n;
    vector<int> control[2];
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        control[p % 2].push_back(p);
    }
    sort(control[0].begin(), control[0].end());
    sort(control[1].begin(), control[1].end());
    for(auto &x : control[1]){
        cout << x << ' ';
    }
    for(auto &x : control[0]){
        cout << x << ' ';
    }
}

```

# D
```cpp
#define int long long

signed main(){
    int n;
    cin >> n;
    map<string, int> control, freq;
    for(int i = 1; i <= n; i++){
        string p;
        cin >> p;
        freq[p]++;
        if(!control[p]){
            control[p] = i;
        }
    }
    vector<tuple<int, int, string>> novo;
    for(auto &[a, b] : freq){
        novo.push_back({b, control[a], a});
    }   
    sort(novo.begin(), novo.end(), 
    [&](tuple<int, int, string> a, tuple<int, int, string> b){
        auto &[a1, b1, c1] = a;
        auto &[a2, b2, c2] = b;
        if(a1 == a2){
            return b1 < b2;
        }
        return a > b;
    });
    for(auto &[a, b, c] : novo){
        cout << c << '\n';
    }
}
```

# E
```cpp
struct Ac{
    vector<int> data;
    int id;
    string acao;
    Ac(){};
    Ac(vector<int> dt, int i, string ac): data(dt), id(i), acao(ac){};
    void out(){
        int i=0;
        int dd, mm, aa, hh, m, ss;
        aa = data[0];
        mm = data[1];
        dd = data[2];
        hh = data[3];
        m = data[4];
        ss = data[5];
        
        cout << setw(2) << setfill('0') << dd << '/';
        cout << setw(2) << setfill('0') << mm << '/';
        cout << setw(4) << setfill('0') << aa << ' ';
        
        cout << setw(2) << setfill('0') << hh << ':';
        cout << setw(2) << setfill('0') << m << ':';
        cout << setw(2) << setfill('0') << ss << ' ';
        
        cout << acao << '\n';
    }
};

bool cmp(Ac a, Ac b){
    if(a.data == b.data) return a.id < b.id;
    return a.data < b.data;
}

void solve(){
    int dd, mm, aa, hh, m, ss;
    string temp, acao;
    int lx;
    vector<Ac> v;
    int i = 0;
    do{
        temp = acao;
        lx = scanf("%d/%d/%d %d:%d:%d ", &dd, &mm, &aa, &hh, &m, &ss);
        getline(cin, acao);
        if(acao == temp or acao.size() == 0) break;
        
        vector<int> dt = {aa, mm, dd, hh, m, ss};
        Ac tmp = {dt, i++, acao};
        v.push_back(tmp);
    }while(acao != temp);
    
    sort(begin(v), end(v), cmp);
    
    for(auto &a:v){a.out();}
}
```

# F
```cpp
signed main(){
    string p;
    int n;
    getline(cin, p);
    n = stoi(p);
    vector<pair<int, string>> control(n);
    for(auto &[a, b] : control){
        getline(cin, p);
        int w = p.find(',');
        string prov = p.substr(w + 1, p.size() - w - 1);
        a = stoi(prov);
        b = p.substr(0, p.size() - prov.size() - 1);
    }
    sort(control.begin(), control.end(), 
    [&](pair<int, string> a, pair<int, string> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a > b;
    });
    for(auto &[a, b] : control){
        cout << b << '\n';
    }
}
```

# G
```cpp
map<int, char> m = {{1, 'A'},
                    {11, 'J'},
                    {12, 'Q'},
                    {13, 'K'}};

void solve(){
    int x;
    vector<int> cards;
    while(cin >> x) cards.push_back(x);
    sort(begin(cards), end(cards));
    for(auto c:cards){
        if(m.count(c)) cout << m[c] << ' ';
        else cout << c << ' ';
    }
    cout << '\n';
}
```

# H
```cpp
map<int, string> m = {  {1, "Às"},
                        {11, "Valete"},
                        {12, "Dama"},
                        {13, "Rei"}};

map<int, string> naipe = {  {0, "Paus"},
                            {1, "Ouro"},
                            {2, "Coração"},
                            {3, "Espada"}};

void solve(){
    int np, x; cin >> np >> x;
    if(m.count(x)) cout << m[x];
    else cout << x;
    cout << " de " << naipe[np] << '\n';
}
```

# I
```python
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))

set1 = set(nxt())
check = nxt()

for i in sorted(check):
    if i in set1:
        print("%d Está mapeado\n" %(i), end="")
    else:
        print("%d Não está mapeado\n" %(i), end="")
```

# J
```cpp
int J(int n, int k){
    if(n == 1) return 0;
    return (J(n-1, k) + k) % n;
}

void solve(){
    int n, k;
    while(cin >> n >> k)
        cout << J(n,k) + 1 << '\n';
}
```

# K
```cpp
#define int long long

void solve(){
    int n; cin >> n;
    map<int, int> m;
    int maxFreq = 0;
    
    while(n--){
        int x; cin >> x;
        m[x]++;
        maxFreq = max(maxFreq, m[x]);
    }
    
    int ans = 0;
    for(auto [fi, se]:m)
        if(se == maxFreq)
            ans = fi;
    
    cout << ans << ' ' << maxFreq << '\n';
}
```

# L
```cpp
struct Node{
    Node *left, *right;
    int value;
    Node(int v): value(v), left(nullptr), right(nullptr){}
};

void bota(Node* at, int val){
    if(val < at->value){
        if(at->left == nullptr) at->left = new Node(val);
        else bota(at->left, val);
    }else{
        if(at->right == nullptr) at->right = new Node(val);
        else bota(at->right, val);
    }
}

void pre_dfs(Node* at){
    if(at == nullptr) return;
    
    cout << at->value << ' ';
    pre_dfs(at->left);
    pre_dfs(at->right);
}

void in_dfs(Node* at){
    if(at == nullptr) return;
    
    in_dfs(at->left);
    cout << at->value << ' ';
    in_dfs(at->right);
}

void pos_dfs(Node* at){
    if(at == nullptr) return;
    
    pos_dfs(at->left);
    pos_dfs(at->right);
    cout << at->value << ' ';
}

void solve(){
    int x;
    vector<int> a;
    while(cin >> x) a.push_back(x);
    int n = a.size();
    Node* root = new Node(a[0]);
    for(int i=1; i<n; i++){
        bota(root, a[i]);
    }
    
    pre_dfs(root); cout << '\n';
    in_dfs(root); cout << '\n';
    pos_dfs(root); cout << '\n';
}
```

# M
```python
import unicodedata

def remove_accents(input_str):
    nfkd_form = unicodedata.normalize('NFKD', input_str)
    return u"".join([c for c in nfkd_form if not unicodedata.combining(c)])

n = int(input())
nomes = []

for i in range(n):
    nome = input()
    nomes.append([remove_accents(nome), nome])

for nome in sorted(nomes):
    print(nome[1])


```

# N
```cpp
typedef long long ll;
#define endl "\n"

void solve(){
  ll n; cin >> n;
  ll maior = 0, menor = 60;
  for(int i =0; i<n; i++){
    ll a; cin >> a;
    maior = max(a, maior);
    menor = min(a, menor);
  }
  ll ans = maior - menor;
  cout << ans << endl;
}
```

# O
```cpp
void solve(){
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    for(int i=1; i<n; i++){
        for(int j=i-1; j>=0 and s[j] > s[j+1]; j--){
            swap(s[j], s[j+1]);
            cnt++;
        }
        cnt++;
    }
    cout << cnt << '\n';
}

signed main(){
    int t; cin>>t; while(t--)
    solve();
    
    return 0;
}
```
