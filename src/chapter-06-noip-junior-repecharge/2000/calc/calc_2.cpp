#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
using namespace std;
 
int main()
{
  freopen("1.in","r",stdin);
  int x=0,y=0,n=0;
  bool mark=0,flag=0;
  char tmp,c;
  while((tmp=getchar())!=EOF)
    {
      if(isdigit(tmp))
        {
          n=(n<<3)+(n<<1)+tmp-'0';
          continue;
        }
      if(islower(tmp))
        {
          if(n==0)n=1;
          if(mark^flag)x-=n;
          else x+=n;
          c=tmp,n=mark=0;
          continue;
        }
      if(tmp=='+' || tmp=='-')
        {
          if(mark^flag)y+=n;
          else y-=n;
          n=0,mark=(tmp=='-');
          continue;
        }
      if(tmp=='=')
        {
          if(mark^flag)y+=n;
          else y-=n;
          flag=1,n=mark=0;
        }
    }
  if(mark^flag)y+=n;
  else y-=n;
  double ans=(double)y/x;
  if(abs(ans)<=0.000001)ans=0;
  printf("%c=%.3lf\n",c,ans);
  return 0;
}