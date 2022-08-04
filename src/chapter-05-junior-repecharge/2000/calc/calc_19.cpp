#include<cstdio>
#include<string>
#include<iostream>
using namespace std;
string s;
double lt,rt;
int u[3],n[3],k,t=0,alp;
void cal(bool kind)
{
    int tmp=0;
    bool flag=0;
    while('0'<=s[k]&&s[k]<='9'){
        flag=1;
        tmp=tmp*10+s[k]-'0';
        k++;
    }
    if(!flag)tmp=1;
    if(kind)tmp=-tmp;
    if('a'<=s[k]&&s[k]<='z'){
        u[t]+=tmp;
        alp=k;
        k++;
    }
    else n[t]+=tmp;
}
int main()
{
    cin>>s;
    for(k=0;k<s.length();){
        if(s[k]=='='){
            t=1;
            k++;
            continue;
        }
        if(s[k]=='-'){
            k++;
            cal(1);
        }
        else{
            if(s[k]=='+')k++;
            cal(0);
        }
    }
    lt=n[0]-n[1];
    rt=u[1]-u[0];
    printf("%c=%.3lf\n",s[alp],lt/rt);
    return 0;
}
