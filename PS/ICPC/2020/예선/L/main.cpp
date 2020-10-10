#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main()
{
    int n,i,j;
    string str1, str2;
    cin>>n>>str1>>str2>>i>>j;
    if(str1==str2)
    {
        cout<<"YES";
        return 0;
    }
    
    int idx1=0,idx2=0,cnt=0;
    int diff[2]={-1,-1};
    bool flag=true;
    while(idx1<n && idx2<n)
    {
        if(idx1==i || idx1==j)
        {
            idx1++;
            if(str1[idx1]==str2[idx2]) diff[cnt++]=idx2++;
            continue;
        }

        if(str1[idx1]!=str2[idx2])
        {
            if(cnt>=2)
            {
                flag=false;
                break;
            }
            diff[cnt++]=idx2++;
        }
        else idx1++,idx2++;
    }
    while(idx2<n){
        
        if(cnt>=2)
        {
            flag=false;
            break;
        }
        diff[cnt++]=idx2++;
    }
    if(flag)
    {
        //printf("%c %d %c %d",str2[diff[0]],diff[0],str2[diff[1]],diff[1]);
        if(cnt==2 && str1[i]==str2[diff[0]] && str1[j]==str2[diff[1]]) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
    return 0;
}