#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char ch[10001],al;
bool neg,alp,rev;
int a,b,t=1;
int main(){
    scanf("%s",ch+1);ch[strlen(ch+1)+1]='+';
    for(int i=1;i<=strlen(ch+1);i++){
        if(ch[i]=='-'||ch[i]=='+'||ch[i]=='='){
            if(rev)t=-t;
            if((i==1||ch[i-1]=='=')&&ch[i]=='-')neg=true;
            else{
                if(!neg)
                    if(alp){a+=t;alp=false;t=1;}
                    else{b+=t;t=1;}
                else
                    if(alp){a-=t;alp=false;t=1;neg=false;}
                    else{b-=t;t=1;neg=false;}
                if(ch[i]=='-')neg=true;
            }
            if(ch[i]=='=')rev=true;
        }
        else if(ch[i]>='0'&&ch[i]<='9'){
            t=(int)(ch[i]-'0');i++;
            while(ch[i]>='0'&&ch[i]<='9'){
                t=t*10+(int)(ch[i]-'0');i++;}
            i--;
        }
        else {alp=true;al=ch[i];}
    }
    if(b)printf("%c=%.3lf",al,(double)(-b)/(double)a);
    else printf("%c=0.000",al);
    return 0;
}
