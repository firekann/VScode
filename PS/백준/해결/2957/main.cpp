#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mid ((l+r)>>1)

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

typedef struct node{
    int v;
    node *l, *r;
} node;
int cnt;

node* insert(node *n, int v){
    if(n==NULL){
        node *tmp=(node*)malloc((int)sizeof(node));
        tmp->v=v;
        tmp->l=tmp->r=NULL;
        n=tmp;
    }
    else{
        cnt++;
        if(n->v>v) n->l=insert(n->l, v);
        else n->r=insert(n->r, v);
    }
    return n;
}

int main(){
    fastio
    int n;
    cin>>n;
    node *head=NULL;
    for(;n--;){
        int v;
        cin>>v;
        head=insert(head, v);
        cout<<cnt<<"\n";
    }
}