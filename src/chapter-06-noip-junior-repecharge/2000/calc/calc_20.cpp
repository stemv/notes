/*by SilverN*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,f;
int side;
int num;
char s[500];
char tar;
int main(){
    int x=0,f=1;
    side=1;
    scanf("%s",s);
    char ch;
    int len=strlen(s);
    s[len]='+';
    for(int i=0;i<=len;i++){
        ch=s[i];
        if( (ch<'0' || ch>'9' ) ){
            if(ch<'a' || ch>'z'){
                num+=-1*x*f*side;
                x=0; f=1;
            }
        }
        if(ch>='a' && ch<='z'){
            tar=ch;
            if(!x)x=1;x=x*f*side;
            n+=x;
            x=0;f=1;
            continue;
        }
        if(ch>='0' && ch<='9'){
            x=x*10+ch-'0';
            continue;
        }
        if(ch=='='){side=-1;continue;}//等号以后的项要变号 
        if(ch=='-'){f=-1;continue;}
        if(ch=='+'){f=1;continue;}
    }
    double ans=(double)num/(double)n;
    if(ans==-0)ans=0;
    printf("%c=%.3f\n",tar,ans);
    return 0;
}