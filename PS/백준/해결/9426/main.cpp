#include <stdio.h>
const int num=100007;
int a[100001]={0};
int N, K;
void f(int n, int k){
	int tmp=0;
    for(int i=1; i<=K; i++){
        tmp+=a[k-i]%num;
    }
    a[k]=tmp%num;
	if(n==K){printf("%d", a[k-1]); return;}
	if(k==n){
		printf("%d", a[k-1]);
		return;
	}
	f(n, k+1);
}
int main(){
	scanf("%d %d", &K, &N);
	for(int i=0; i<K; i++){
	    scanf("%d", &a[i]);
	}
	f(N, K);
	return 0;
}