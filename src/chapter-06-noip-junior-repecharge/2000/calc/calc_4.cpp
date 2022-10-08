#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000
using namespace std;
char ch,s[N];
int f=1,y=1,k,b,sum;
int main()
{
    cin>>s;
    int l=strlen(s);
    for(int i=0;i<l;i++)
    {
        if(s[i]=='-') f=-1,sum=0;
        if(s[i]=='+') f=1,sum=0;
        if(s[i]>='a'&&s[i]<='z') ch=s[i],sum=0;
        if(s[i]>='0'&&s[i]<='9')
        {
            sum+=s[i]-'0';
            if(s[i+1]>='a'&&s[i+1]<='z') k+=y*f*sum;
            else if(s[i+1]>='0'&&s[i+1]<='9') sum*=10;
            else b+=-y*f*sum;
        }
        if(s[i]=='=') y=-1,sum=0,f=1;        
    }
    double ans=1.0*b/k;
    printf("%c=%.3lf",ch,ans);
    return 0;
}