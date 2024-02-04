// https://codeforces.com/blog/entry/11080
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Como usar
ordered_set<int> S;
*S.find_by_order(i); // equivale a S[i] se fosse um vetor
S.order_of_key(x);   // equivale a uma busca binária / lower_bound
