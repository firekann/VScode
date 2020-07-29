#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

ordered_multiset x;
vector<int> v;
vector<int> ord;

int main(){
    fastio
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        x.insert(tmp);
    }
    for(int i=0; i<n; i++){
        int tmp;
        cin>>tmp;
        ord.push_back(tmp);
    }
    while(!ord.empty()){
        int t=ord.back();
        ord.pop_back();
        int k=*(x.find_by_order(t));
        x.erase(x.upper_bound(k));
        v.push_back(k);
    }
    reverse(all(v));
    for(auto i:v) cout<<i<<"\n";
}