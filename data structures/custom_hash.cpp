/*
https://usaco.guide/gold/hashmaps?lang=cpp
https://codeforces.com/blog/entry/60737
*/
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Syntax
unordered_set<T, custom_hash> S;
unordered_map<T1, T2, custom_hash> M;

// Alternative (looks faster)
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<T, null_type, custom_hash> S;
gp_hash_table<T1, T2, custom_hash> M;
