#include <bits/stdc++.h>
using namespace std;

#ifdef DBG
    template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
    template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
    void dbg_out() { cerr << '\n'; }
    template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
    #define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
    template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#endif
void print_out() { cout << '\n'; }
template<typename Head, typename... Tail> void print_out(Head H, Tail... T) { cout << H << ' '; print_out(T...); }
#define print(...) print_out(__VA_ARGS__)

template<typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T> istream& operator>>(istream &is, vector<T> &v) { for(T &x:v) is >> x; return is; }
void read_in() { return; }
template<typename Head, typename... Tail> void read_in(Head &H, Tail&... T) { cin >> H; read_in(T...); }
#define read(...) read_in(__VA_ARGS__)



template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
    static_assert(D >= 1, "Dimension must be positive");
    template <typename... Args>
    Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
    Vec(int n = 0, T val = T()) : std::vector<T>(n, val) {}
};
/* Example
    Vec<4, int64_t> f(n, k, 2, 2); // = f[n][k][2][2];
    Vec<2, int> adj(n); // graph
*/



#define int         long long
#define ld          long double
#define sz(x)       (int)size(x)
#define all(x)      begin(x), end(x)
#define rall(x)     rbegin(x), rend(x)
#define FOR(i,a,b)  for(int i=(a); i<=(b); ++i)
#define ROF(i,a,b)  for(int i=(a); i>=(b); --i)
#define endl        "\n"
#define PB          push_back
#define MP          make_pair

using vi = vector<int>;
using ii = pair<int,int>;
using vii = vector<ii>;

const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1); // or use M_PI from "cmath"

int nxt(){ int x; cin >> x; return x; }
void setIO(string file = "");


void solve(){
    
}

signed main(){
    setIO();
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}

void setIO(string file){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(!file.empty()){
        (void)!freopen((file + ".in").c_str(), "r", stdin);
        (void)!freopen((file + ".out").c_str(), "w", stdout);
    }
}

/* stuff you should look for (adapted from BenQ)
    * uninitialized stuff
    * off-by-one errors
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
*/
