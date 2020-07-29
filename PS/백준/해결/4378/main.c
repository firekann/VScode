#include<stdio.h>
#include<string.h>

const char f[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main(){
    int l=strlen(f);
    char s[1000]={};
    while(gets(s)){
        for(int i=0; i<strlen(s); i++){
            if(s[i]==' ') continue;
            for(int j=0; j<l; j++){
                if(s[i]==f[j]){
                    s[i]=f[j-1];
                    break;
                }
            }
        }
        printf("%s\n", s);
    }
}