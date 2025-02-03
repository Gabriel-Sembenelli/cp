#include <bits/stdc++.h>
using namespace std;

#define int long long
#define sz(X) ((int)(X).size())
#define all(X) (X).begin(),(X).end()

using T = double;
using Pt = pair<T,T>;
#define X first
#define Y second

const T eps = 1e-9;

int n, m; // largura n, altura m 
T l;
Pt fim;

T dist(Pt a, Pt b){ return hypot(a.X - b.X, a.Y - b.Y); }

// Qual ponto sobre o segmento ab resulta num caminho final de tamanho exatamente l?
bool ok(Pt at, Pt to){ return dist(at, to) + dist(to, fim) <= l; }
Pt anda(Pt at, T step, Pt to){
    Pt v = {to.X - at.X, to.Y - at.Y};
    T razao = step / dist(at, to);
    v = {v.X * razao, v.Y * razao};
    return {at.X + v.X, at.Y + v.Y};
}
Pt acha(Pt a, Pt b){
    Pt re = a;
    for(T step = dist(a, b) + 1.0; step > eps; step /= 2.0){
        Pt nxt;
        while(ok(a, nxt = anda(re, step, b))){
            assert(abs(step - dist(re, nxt)) < eps);
            re = nxt;
        }
    }
    return re;
}

signed main(){
    cin >> n >> m >> l;
    fim = {n, m};
    
    vector<Pt> path = {{0,0}};
    for(int i = 1; i <= m; ++i)
        path.push_back({(i % 2) * n, i}); // zig-zag
    path.push_back(fim);
    
    vector<Pt> ans = {{0,0}};
    for(int i = 0; i < sz(path) - 1 && l > eps; ++i){
        Pt at = path[i], to = path[i + 1];
        T best = dist(at, to) + dist(to, fim); // Tenta acabar nesse segmento
        if(l <= best){ // Se dá, acha o ponto exato que acaba com o comprimento restante
            to = acha(at, to);
            if(dist(at, to) > eps) ans.push_back(to);
            ans.push_back(fim);
            l -= best;
            assert(l <= eps);
        }else{ // Se não, consome esse segmento e continua
            ans.push_back(to);
            l -= dist(at, to);
        }
    }

    cout << sz(ans) << '\n';
    Pt last = ans[0]; T len = 0;
    for(auto p : ans){
        len += dist(last, p);
        //cout << fixed << setprecision(8) << p.X << ' ' << p.Y << '\t' << len << '\n';
        cout << fixed << setprecision(8) << p.X << ' ' << p.Y << '\n';
        last = p;
    }

    return 0;
}