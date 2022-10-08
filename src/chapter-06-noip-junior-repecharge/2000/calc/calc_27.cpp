#include <cstdio>
#include <cstring>
 
int main()
{
    //freopen("a.txt","r",stdin);
    char s[100];
    char c;
    double x=0,y=0,ans=0,flag=1;  //ans存储当前数值 ，flag表示在等式左边还是右边，x表示变量的大小，y表示整数的结果
    int cnt=1; //cnt表示当前的数正还是负
    scanf("%s",s);
    int len=strlen(s);
    if(s[0]=='-') cnt=-1; //判断第一个字符
    else if(s[0]>='a'&&s[0]<='z') { x+=1; c=s[0];} //是字母的话
    else ans=ans*10+s[0]-'0';  //是数字
    for(int i=1;i<len;i++)
    {
      // printf("%.2lf %d %.2lf %.2lf\n",ans,cnt,x,y);
        if(s[i]>='a'&&s[i]<='z')  //是字母就把 ans的值加到x里面去 同时c表示变量是哪个字母
        {
            c=s[i];  
            x+=cnt*flag*ans;
            ans=0;
            cnt=1;
        }
        else if(s[i]>='0'&&s[i]<='9')
        {
                ans=ans*10+s[i]-'0';
        }
        else
        {
            if(ans)  //数字加到y上面去
            {
                y+=cnt*flag*ans;
                ans=0;cnt=1;
            }
            if(s[i]=='-') cnt=-1;
            else if(s[i]=='+') cnt=1;
            else if(s[i]=='=') flag=-1;
        }
    }
    if(s[len-1]>='0'&&s[len-1]<='9') y+=cnt*flag*ans; //还要注意最后是整数的情况没有处理
   // printf("%.2lf\n",ans);
    //printf("%.2lf %.2lf\n",x,y);
    ans=y/x; //还有等于0的情况
    if(ans==0) printf("0.000\n");
    else
    printf("%c=%.3lf\n",c,-1*y/x);
    return 0;
}
