#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
typedef long long ll;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

const int alphabet=26;
struct trie{
    trie *next[alphabet]; //알파벳 소문자는 26개
    bool end;
    int cnt;
    trie(): end(false), cnt(1){memset(next, 0, sizeof(next));} //생성자
    ~trie(){ //소멸자
        for(int i=0; i<alphabet; i++) if(next[i]) delete next[i];
    }
    void insert(const char* key){
        if(*key=='\0') end=true;
        else{
            int cur=*key-'a';
            if(next[cur]==NULL) next[cur]=new trie();
            else next[cur]->cnt++;
            next[cur]->insert(key+1);
        }
    }
    int find(const char* key){
        int cur=*key-'a';
        if(*key=='?'){
            int tmp=0;
            for(int i=0; i<alphabet; i++) if(next[i]!=NULL) tmp+=next[i]->cnt;
            return tmp;
        }
        if(next[cur]==NULL) return 0;
        if(*(key+1)=='?') return next[cur]->cnt;
        return next[cur]->find(key+1);
    }
};

trie *root[10100];
trie *reversedroot[10100];

vector<int> solution(vector<string> words, vector<string> queries) {
    int wlen=sz(words);
    int qlen=sz(queries);
    vector<int> answer(qlen);
    for(auto itr:words){
        int len=sz(itr);
        const char *c=itr.c_str();
        if(root[len]==NULL) root[len]=new trie();
        root[len]->insert(c);
        string tmps=itr;
        reverse(all(tmps));
        const char *reversed=tmps.c_str();
        if(reversedroot[len]==NULL) reversedroot[len]=new trie();
        reversedroot[len]->insert(reversed);
    }
    int idx=0;
    for(auto itr:queries){
        int len=sz(itr);
        if(itr[0]=='?'){
            string tmps=itr;
            reverse(all(tmps));
            const char *reversed=tmps.c_str();
            if(reversedroot[len]==NULL){
                idx++;
                continue;
            }
            else answer[idx]=reversedroot[len]->find(reversed);
        }
        else{
            const char *c=itr.c_str();
            if(root[len]==NULL){
                idx++;
                continue;
            }
            else answer[idx]=root[len]->find(c);
        }
        idx++;
    }
    return answer;
}

int main(){
    fastio
    int w, q;
    cin>>w>>q;
    vector<string> vw(w), vq(q);
    for(auto &i:vw) cin>>i;
    for(auto &i:vq) cin>>i;
    for(auto i:solution(vw, vq)) cout<<i<<" ";
}

/*
crocus.co.kr/1053
*/

/*
6 5
frodo front frost frozen frame kakao
fro?? ????o fr??? fro??? pro?
*/

/*
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<int, map<string, int>> mp;
    for(auto itr:words){
        int len=sz(itr);
        string tmps=itr;
        string front, end, qq;
        front=end=qq="";
        for(int i=0; i<len; i++) qq+="?";
        if(mp[len][qq]) mp[len][qq]++;
        else mp[len][qq]=1;
        for(int i=0; i<len; i++){
            front+=tmps[i];
            end=tmps.substr(len-1-i, i+1);
            qq="";
            for(int j=0; j<len-i-1; j++) qq+="?";
            if(mp[len][front+qq]) mp[len][front+qq]++;
            else mp[len][front+qq]=1;
            if(mp[len][qq+end]) mp[len][qq+end]++;
            else mp[len][qq+end]=1;
        }
        mp[len][tmps]--;
    }
    for(auto itr:queries){
        string tmp=itr;
        int len=sz(itr);
        if(sz(mp[len])){
            answer.pb(mp[len][itr]);
        }
        else answer.pb(0);
    }
    return answer;
}
*/

/*
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<int, vector<string>> mp;
    for(auto itr:words){
        int len=sz(itr);
        mp[len].pb(itr);
    }
    for(auto itr:queries){
        string tmp=itr;
        int len=sz(tmp);
        if(sz(mp[len])){
            int cnt=0;
            if(tmp[0]=='?'&&tmp[len-1]=='?'){
                answer.pb(sz(mp[len]));
                continue;
            }
            int subs, sube;
            int cntqus=0;
            string qq="";
            for(auto i:tmp){
                if(i=='?'){
                    cntqus++;
                    qq+="?";
                }
            }
            sube=len-cntqus;
            if(tmp[0]=='?') subs=cntqus;
            else subs=0;
            for(auto itrv:mp[len]){
                if(subs){
                    if(tmp==qq+itrv.substr(subs, sube)) cnt++;
                    //cout<<qq+itrv.substr(subs, sube)<<" ";
                }
                else{
                    if(tmp==itrv.substr(subs, sube)+qq) cnt++;
                    //cout<<itrv.substr(subs, sube)+qq<<" ";
                }
            }
            cout<<"\n";
            answer.pb(cnt);
        }
        else answer.pb(0);
    }
    return answer;
}
*/

/*
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    map<int, map<string, int>> mpf;
    map<int, map<string, int>> mpe;
    map<int, int> mp;
    for(auto itr:words){
        int len=sz(itr);
        string tmps=itr;
        string front, end;
        if(mp[len]) mp[len]++;
        else mp[len]=1;
        for(int i=0; i<len; i++){
            front+=tmps[i];
            end=tmps.substr(len-1-i, i+1);
            if(mpf[len][front]) mpf[len][front]++;
            else mpf[len][front]=1;
            if(mpe[len][end]) mpe[len][end]++;
            else mpe[len][end]=1;
        }
    }
    for(auto itr:queries){
        string tmp=itr;
        int len=sz(itr);
        if(mp[len]){
            if(tmp[0]=='?'&&tmp[len-1]=='?') answer.pb(mp[len]);
            else{
                char tmpc=tmp[0];
                int cnt=0;
                tmp.erase(remove(all(tmp), '?'), tmp.end());
                if(tmpc=='?') answer.pb(mpe[len][tmp]);
                else answer.pb(mpf[len][tmp]);
            }
        }
        else answer.pb(0);
    }
    return answer;
}
*/