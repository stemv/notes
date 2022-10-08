#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main(){
    char map[1000]={0};
    float sum=0,s=0,n=0;
    int t=1,f=1,i;
    char c,x;
    scanf("%s",map);
    int len = strlen(map)-1;
    for(i=0;i<=len;i++){
        c=map[i];
        if(map[i]>='0'&&map[i]<='9'){
            s=s*10+map[i]-'0';
        }
        else
        {
            if(map[i]>='a'&&map[i]<='z'||map[i]>='A'&&map[i]<='Z'){
            x=map[i];
                sum+=f*s*t;
            }
            else
            {
                n+=-1*f*s*t;
                t=(c=='-')?-1:1;
                f=(c=='=')?-1:f;
            }
            s=0;
            
        }
        
        
    }
    if(map[len]!=x)
    n+=-1*s*t*f;
    
    printf("%c=%.3f\n",x, n/sum);
    
    
    
    
    
    return 0;
} 
