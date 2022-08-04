#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

bool f;
int i,j,unknown,yz; 
char s[124414],ch;
bool c[124111];
int main()
{ 
    gets(s);
    int sl=strlen(s);
    for(i=0;i<sl;++i)
    {
        if(s[i] == '=') f=1;
        if(s[i]>='1'&&s[i]<='9')
        {
            int z=0,h=0,j=i;
            while(s[j]>='0'&&s[j]<='9')
            {
                if(h==0&&!c[j]) {z=s[j]-48;h++;c[j]=1;}
                if(!c[j]&&h)
                {
                    z=z*10+s[j]-48;c[j]=1;
                    j++;
                }
                else j++;
            }
            if(s[j]>='a'&&s[j]<='z') z=0;
            if(s[i-1]=='-') z=z*(-1);
            if(f) yz+=z*(-1);
            else yz+=z;
        }
        if(s[i]>='a'&&s[i]<='z')
        {
            int g,v,x,c;
            if(s[i-1]=='+') c=1;
            else if(s[i-1]=='+') c=-1;
            else if(s[i-1]>='1'&&s[i-1]<='9') {
                g=i-1,v=0,x=0;
                while(s[g]>='0'&&s[g]<='9')
                {
                    if(x==0) {v=s[g]-48;x++;}
                    else {v=v+(s[g]-48)*10;}
                    g--;
                }
                if(s[g]=='+') v*=1;
                else if(s[g]=='-') v*=(-1); 
                if(f) v*=(-1);
                else v*=1;
                unknown+=v;
            }
            ch=s[i];
        }
    }
    double c=yz*1.0/unknown*-1;
    if(c!=-0.000||c!=0.000)
    printf("%c=%.3lf\n",ch,c);
    else cout<<ch<<"="<<"0.000";
}