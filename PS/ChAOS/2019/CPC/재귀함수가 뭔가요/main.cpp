#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define ans p(t);cout<<"라고 답변하였지.\n";

using namespace std;
typedef long long lli;

int n;
void p(int v){while(v--) cout<<"____";}
void f(int t){
    p(t);
    cout<<"\"재귀함수가 뭔가요?\"\n";
    if(t!=n){
        p(t);
        cout<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
        p(t);
        cout<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
        p(t);
        cout<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";
    }
    else{
        p(t);
        cout<<"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    }
    if(t==n){
        ans
        return;
    }
    else f(t+1);
    ans
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
    f(0);
}
