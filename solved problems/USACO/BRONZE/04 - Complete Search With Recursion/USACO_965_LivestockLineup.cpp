/*
Approach: We only have 8 cows, so we can search through all permutations of cows
in lexicographical order, until find the first that match the constraints
*/
#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define F first
#define S second

signed main(){
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    
    int N; cin >> N;
    vector<pair<string,string>> constraint(N);
    for(int i=0; i<N; i++){
        string &X = constraint[i].F;
        string &Y = constraint[i].S;
        cin >> X;
        cin >> Y >> Y >> Y >> Y; // must, be, milked, beside
        cin >> Y;
    }
    
    vector<string> cows = { "Bessie", "Buttercup", "Belinda", "Beatrice",
        "Bella", "Blue", "Betsy", "Sue"};
    
    sort(begin(cows), end(cows)); // Don't forget to sort before permuting!
    
    do{ // For each permutation
        bool validPerm = true;
        for(auto [X,Y]:constraint){ // Search each constraint
            bool foundPair = false;
            for(int i=0; i<size(cows)-1; i++){ // Through all adjacent cows
                if(MP(cows[i], cows[i+1]) == MP(X, Y)) // X before Y
                    foundPair = true;
                if(MP(cows[i], cows[i+1]) == MP(Y, X)) // Y before X
                    foundPair = true;
            }
            if(!foundPair) validPerm = false;
        }
        if(validPerm) break; // Break as soon as we find a valid permutation
    }while(next_permutation(begin(cows), end(cows)));
    
    for(auto c:cows) cout << c << '\n';
    
    return 0;
}
