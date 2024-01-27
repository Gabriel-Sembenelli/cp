# A
```cpp
#define all(x) begin(x), end(x)
void solve(){
    string s; cin >> s;
    string t = s;
    reverse(all(t));
    cout << (s == t ? "sim\n" : "não\n");
}
```

# B
```cpp
void solve(){
    string s; getline(cin, s);
    int n = s.size();
    string s1, s2;
    for(int i=0; i<n; i++){
        if(i < n/2) s1 += s[i];
        else s2 += s[i];
    }
	reverse(begin(s1), end(s1));
    reverse(begin(s2), end(s2));
    cout << s1 << s2 << '\n';
}
signed main(){
    int t; scanf("%d\n", &t); while(t--)
    solve();
    return 0;
}
```

# C
```python
from sys import stdin
input = stdin.readline
nxt = lambda : list(map(int, input().split()))

nome = input().split()
n = len(nome)
for i in range(n):
    if i == 0:
        print(nome[i], end=" ")
    elif i == n-1:
        print(nome[i], end="\n")
    elif nome[i] in ["da", "de", "do", "dos", "e"]:
        continue
    else:
        print("%c."%(nome[i][0]), end=" ")
```

# D
```cpp
#define all(x) begin(x), end(x)
void solve(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    sort(all(s1));
    sort(all(s2));
    cout << (s1 == s2 ? "sim" : "nao") << '\n';
}
```

# E
```cpp
void solve(){
    string s; cin >> s;
    if(s.size() == 1){ cout << s << '\n'; return; }
    s += '.';
    char curr = s[0];
    int cnt = 1;
    string aux;
    for(int i=1; i<s.size(); i++){
        if(s[i] == curr){
            cnt++;
        }else{
            aux += curr;
            if(cnt > 1) aux += (to_string(cnt));
            curr = s[i];
            cnt = 1;
        }
    }
    s.pop_back();
    if(aux.size() < s.size()) cout << aux << '\n';
    else cout << s << '\n';
}
```

# F
```cpp
void solve(){
    string s; cin >> s;
    bool c8 = false;
    bool AA = false;
    bool aa = false;
    bool nn = false;
    
    if(s.size() >= 8) c8 = true;
    for(auto c:s){
        if('A' <= c and c <= 'Z') AA = true;
        if('a' <= c and c <= 'z') aa = true;
        if('0' <= c and c <= '9') nn = true;
    }
    
    if(c8 and AA and aa and nn){ cout << "senha valida\n"; return; }
    
    if(!c8) cout << "minimo de 8 caracteres" << '\n';
    if(!AA) cout << "letra maiuscula" << '\n';
    if(!aa) cout << "letra minuscula" << '\n';
    if(!nn) cout << "numero" << '\n';
}
```

# G
```cpp
void solve(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        cout << s << " \n"[i==n-1];
    }
}
```

# H
```cpp
void solve(){
    string s; getline(cin, s);
    int x; cin >> x;
    for(auto &c:s){
        if('a' <= c and c <= 'z'){
            c -= 'a';
            c += x;
            c %= 26;
            c += 'a';
        }
        if('A' <= c and c <= 'Z'){
            c -= 'A';
            c += x;
            c %= 26;
            c += 'A';
        }
    }
    cout << s << '\n';
}
```

# I
```cpp
void solve(){
    map<string, int> D, E;
    int n; cin >> n;
    while(n--){
        string id, c; cin >> id >> c;
        if(c == "D") D[id]++;
        else E[id]++;
    }
    int ans = 0;
    for(auto [id,qe]:E){
        int qd = D[id];
        ans += min(qe, qd);
    }
    cout << ans << '\n';
}
```

# J
```cpp
void solve(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cout << (s1 == s2 ? 1 : 0) << '\n';
}
```

# K
```python
linha = input().split()
n = len(linha)
m = 0
for palavra in linha:
    m += len(palavra)

print(n)
print(m)
```

# L
```python
linha = input().split()
m = 0
for palavra in linha:
    m = max(m, len(palavra))

for palavra in linha:
    if len(palavra) == m:
        print(palavra)
        break
```

# M
```cpp
void solve(){
    string s; getline(cin, s);
    int cntarr = 0;
    for(auto c:s) cntarr += (c == '@');
    
    if(cntarr != 1){ cout << 0 << '\n'; return; }
    
    int ans=1, i=0;
    for(;s[i]!='@'; i++){
        char c = s[i];
        if('a' <= c and c <= 'z') continue;
        if('0' <= c and c <= '9') continue;
        if(c == '.') continue;
        if(c == '_') continue;
        ans = 0;
    }
    i++;
    for(;i<s.size();i++){
        char c = s[i];
        if('a' <= c and c <= 'z') continue;
        if(c == '.') continue;
        ans = 0;
    }
    if(s.back() == '.') ans = 0;
    
    cout << ans << '\n';
}
```

# N
```cpp
void solve(){
    string s; cin >> s;
    int n = s.size();
    cout << s[0];
    for(int i=1; i<n; i++){
        if(s[i-1] == s[i]) continue;
        cout << s[i];
    }
    cout << '\n';
}
```

# O
```python
ans = 0
linha = input()
for c in linha:
    if c in ['a','e','i','o','u','A','E','I','O','U']:
        ans += 1
print(ans)
```