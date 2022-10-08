//洛谷 P1022 计算器的改良  
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define M(a) memset(a,0,sizeof a)
#define fo(i,j,k) for(i=j;i<=k;i++)
using namespace std;
const int mxn=1e6;
char s[1000005];
int num[1000005],cun[1000005];
char ch;
bool vis[1000005];
ll kl,kr;  //常数项
ll al,ar;  //系数项 
int main()
{
    int i,j,mid;
    scanf("%s",s+1);
    int len=strlen(s+1);
    fo(i,1,len) if(s[i]<='z' && s[i]>='a') num[++num[0]]=i,ch=s[i];
    fo(i,1,len) if(s[i]=='=') {mid=i;break;}
    fo(i,1,num[0])
    {
        M(cun);int mul=1;
        for(j=num[i]-1;s[j]>='0' && s[j]<='9';j--)
          cun[++cun[0]]=s[j]-'0',vis[j]=1;
        if(s[j]=='-') mul=-1;
        ll tmp=0,po=1;
        fo(j,1,cun[0]) tmp+=po*cun[j],po*=10;
        if(num[i]<mid) al+=tmp*mul;
        else ar+=tmp*mul;
    }
    fo(i,1,len)
      if(!vis[i] && s[i]<='9' && s[i]>='0')
      {
          ll tmp=0;int mul=1;
          if(s[i-1]=='-') mul=-1;
          fo(j,i,len)
          {
              if(s[j]<'0' || s[j]>'9') break;
              vis[j]=1;
              tmp=tmp*10+s[j]-'0';
          }
          if(i<mid) kl+=tmp*mul;
          else kr+=tmp*mul;
      }
    al-=ar,kr-=kl;
    double ans=(double)kr/(double)al;
    printf("%c=%.3lf\n",ch,ans);
    return 0;
}