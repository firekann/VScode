#include <stdio.h>
int k, n, memo[26][26]={0};
int f(int k, int l){
    if(l==k||l==0){
        return 1;
    }
    else{
        if(memo[k][l]==0){
            memo[k][l]=f(k-1, l-1)+f(k-1, l);
            return memo[k][l];
        }
        else{
            return memo[k][l];
        }
    }
}
int main(){
    scanf("%d", &k);
    for(int i=0; i<k; i++){
        scanf("%d", &n);
        printf("%d\n", f(n, 3)+f(n, 2)+f(n, 1));
    }
}