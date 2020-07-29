#include <stdio.h>
long long int memo[100]={1, 1, 2, 4}, arr[100]={0};
long long int f(int k){
    if(k==0) return 1;
    if(k==1) return 1;
    if(k==2) return 2;
    if(k==3) return 4;
    else{
        if(memo[k]==0){
            memo[k]=f(k-1)+f(k-2)+f(k-3)+f(k-4);
            return memo[k];
        }
        else{
            return memo[k];
        }
    }
}
int main(){
	int k=4, m;
	scanf("%d", &m);
	for(int i=0; i<m; i++){
        scanf("%lld", &arr[i]);
	}
	for(int i=0; i<m; i++){
        printf("%lld\n", f(arr[i]));
	}
}