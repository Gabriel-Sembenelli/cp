/*
Was training "Complete Search with Recursion" when tried to solve this.
*/
#include <bits/stdc++.h>
using namespace std;

struct Rect{
    int x1, y1, x2, y2; // (x1,y1) := up left vertex
    char c;             // (x2,y2) := down right vertex
};

int N;
int x[4], y[4]; // 1 indexed
vector<Rect> occup;
vector<vector<char>> ans;

// Check if there's free space to put a logo with vertices (x1,y1) (x2,y2)
bool isFree(int x1, int y1, int x2, int y2){
    if( min({x1, y1, x2, y2}) < 0 or    // Outside answer area
        max({x1, y1, x2, y2}) >= N)
        return false;
    
    for(auto R:occup){  // Intersects with another positioned logo
        int xInter = max(0, min(x2, R.x2) - max(x1, R.x1) + 1);
        int yInter = max(0, min(y2, R.y2) - max(y1, R.y1) + 1);
        if(xInter * yInter) return false;
    }
    
    return true;
}

void search(int k){
    if(k == 4){ // Successfully positioned all logos, found answer
        for(auto R:occup)                       // For each positioned logo
            for(int i=R.x1; i<=R.x2; i++)       // Iterates through
                for(int j=R.y1; j<=R.y2; j++)   // all of it's area
                    ans[i][j] = R.c;            // Filling with it's character
        return;
    }
    for(int i=0; i<N; i++){     // For current logo, iterate
        for(int j=0; j<N; j++){ // through all possible (i,j)
            int x1, y1, x2, y2;
            char c = 'A' + k - 1;
            // Try to put current logo at (i,j) with original orientation
            tie(x1, y1, x2, y2) = make_tuple(i, j, i+x[k]-1, j+y[k]-1);
            if(isFree(x1, y1, x2, y2)){
                Rect R = {x1, y1, x2, y2, c};
                occup.push_back(R);
                search(k+1);
                occup.pop_back();
                if(ans[0][0]) return; // Found answer, no need to continue
            }
            // Try to put current logo at (i,j) with swapped orientation
            swap(x[k], y[k]);
            tie(x1, y1, x2, y2) = make_tuple(i, j, i+x[k]-1, j+y[k]-1);
            if(isFree(x1, y1, x2, y2)){
                Rect R = {x1, y1, x2, y2, c};
                occup.push_back(R);
                search(k+1);
                occup.pop_back();
                if(ans[0][0]) return; // Found answer, no need to continue
            }
            swap(x[k], y[k]); // Unswap just in case
        }
    }
}

signed main(){
    int area = 0;
    for(int i=1; i<=3; i++){
        cin >> x[i] >> y[i];
        area += x[i] * y[i];
    }
    N = int(sqrt(area));    // Answer exists
    if(N*N != area){        // only if total
        cout << -1 << '\n'; // area is a
        return 0;           // perfect square
    }
    
    ans.resize(N, vector<char>(N));
    search(1);
    
    if(ans[0][0]){
        cout << N << '\n';
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout << ans[i][j];
            }
            cout << '\n';
        }
    }else{
        cout << -1 << '\n';
    }
    
    return 0;
}
