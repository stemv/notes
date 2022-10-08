#include<iostream> 
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char ch,unknown;
    int coefficient=0,sum=0;
    int current=0,flag=1,work=1,symbol=1;
    double result;
    
    ch=getchar();//读入一个字符
    for(;;)
    {
        if(ch>='a' && ch<='z')//当字符为字母时
        {
            unknown=ch;//记录该字符
            if(current==0&&work)//当前数位为0时
                coefficient=coefficient+symbol*flag;//求系数
            else//当前数位不为0时
            {
                coefficient=coefficient+symbol*flag*current;//求系数
                current=0;
                flag=1;
            }
        }
        else if(ch>='0'&&ch<='9')//当字符为数字时
        {
            current=current*10+ch-'0';//记录当前数位
            work=1; 
        }
        else if(ch=='+')//当字符为加号时
        {
            sum=sum+(-symbol*flag*current);//累加数字和
            current=0;
            flag=1;
            work=0;
        }
        else if(ch=='-')//当字符为减号时
        {
            sum=sum+(-symbol*flag*current);//累加数字和
            current=0;
            flag=-1;
            work=0; 
        }
        else if(ch=='=')//当字符为等号时
        {
            sum=sum+(-symbol*flag*current);//累加数字和
            current=0;
            flag=1;
            symbol=-symbol;//由于移位，取负
            work=0;
        }
        else//循环终止情况
        {
            sum=sum+(-symbol*flag*current);
            break;//终止循环
        }
        ch=getchar();//读入一个字符
    }
    
    result=1.0*sum/coefficient;//数字和和除以系数
    
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    cout<<unknown<<"="<<result<<endl;
    
    return 0;
}
