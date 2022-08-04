#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char ch[1005],ans;
int num,sum,k1=1,k2=1,xi;
int main()
{
    scanf("%s",ch+1);
    for(int i=1;i<=strlen(ch+1);i++)
    {
        if(ch[i]>='0'&&ch[i]<='9')
            num*=10,num+=ch[i]-'0';
        else
        {
            if(ch[i]>='a'&&ch[i]<='z')
                ans=ch[i],xi+=k1*k2*num;
            else
            {
                sum+=k1*k2*num;
                if(ch[i]=='-')
                    k1=-1;
                else if(ch[i]=='+')
                    k1=1;
                else if(ch[i]=='=')
                    k2=-1,k1=1;
            }
            num=0;
        }
    }
    sum+=k1*k2*num;
    printf("%c=%.3f\n",ans,(double)-sum/xi);
    return 0;
}