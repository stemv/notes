#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
 
int n,len,xi,now,z,zhe[1001][2],jian[1001][2];
double ans;
char s[1001],dva;
 
int main()
{
    scanf("%s",s);len=strlen(s);
    if(s[now]>='0' && s[now]<='9')
    {
        int kkz=0;
        while(s[now]>='0' && s[now]<='9') (kkz*=10)+=s[now]-'0',now++;
        if(s[now]>='a' && s[now]<='z') xi+=kkz,dva=s[now],now++;
        else zhe[++zhe[0][z]][z]=kkz;
    }
    while(now<len)
    {
        if(s[now]=='=') now++,z=1;
        if(s[now]=='+')
        {
            int kkz=0;now++;
            while(s[now]>='0' && s[now]<='9') (kkz*=10)+=s[now]-'0',now++;
            if(s[now]>='a' && s[now]<='z')
            {
                dva=s[now];now++;
                if(!kkz) kkz=1;
                if(!z) xi+=kkz;
                else xi-=kkz;
            }
            else zhe[++zhe[0][z]][z]=kkz;
        }
        if(s[now]=='-')
        {
            int kkz=0;now++;
            while(s[now]>='0' && s[now]<='9') (kkz*=10)+=s[now]-'0',now++;
            if(s[now]>='a' && s[now]<='z')
            {
                dva=s[now];now++;
                if(!kkz) kkz=1;
                if(!z) xi-=kkz;
                else xi+=kkz;
            }
            else jian[++jian[0][z]][z]=kkz;
        }
        if(s[now]>='0' && s[now]<='9')
        {
            int kkz=0;
            while(s[now]>='0' && s[now]<='9') (kkz*=10)+=s[now]-'0',now++;
            if(s[now]>='a' && s[now]<='z')
            {
                dva=s[now];now++;
                if(!kkz) kkz=1;
                if(!z) xi+=kkz;
                else xi-=kkz;
            }
            else zhe[++zhe[0][z]][z]=kkz;
        }
        if(s[now]>='a' && s[now]<='z') dva=s[now++];
    }
    double tot=0;
    for(int i=1;i<=zhe[0][0];i++) tot+=zhe[i][0];
    for(int i=1;i<=zhe[0][1];i++) tot-=zhe[i][1];
    for(int i=1;i<=jian[0][0];i++) tot-=jian[i][0];
    for(int i=1;i<=jian[0][1];i++) tot+=jian[i][1];
    printf("%c=",dva);
    if(xi==0) printf("0.000\n");
    else printf("%.3lf\n",-tot/(double)xi);
    return 0;
}
