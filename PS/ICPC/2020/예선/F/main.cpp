#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int>> pol(n);
    pair<int,int> thi;
    for(int i=0;i<n;i++) cin>>pol[i].first>>pol[i].second;
    cin>>thi.first>>thi.second;

    vector<bool> flag(4,false);
    for(int i=0;i<n;i++)
    {
        int cx=pol[i].first-thi.first;
        int cy=pol[i].second-thi.second;
        if(cy<=cx*-1 && cy>=cx) flag[0]=true;
        if(cy>=cx*-1 && cy>=cx) flag[1]=true;
        if(cy<=cx*-1 && cy<=cx) flag[2]=true;
        if(cy>=cx*-1 && cy<=cx) flag[3]=true;
    }

    if(flag[0] && flag[1] && flag[2] && flag[3]) cout<<"NO";
    else cout<<"YES";
    return 0;
}