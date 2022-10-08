#include<cstdio>
#include<cstring>
using namespace std;
int main()                  //例：3685a+452=16a-98
{
    bool left = true, right = false;
    int bianliang = 0, shuzi = 0,last = 0;
    char bianliangming;
    char fangcheng[1000];
    scanf("%s",fangcheng);
    int n = strlen(fangcheng);
    for(int i = 0;i<=n;i++)
    {
        int temp = 0;
        char ch = fangcheng[i];
        if(ch>='a'&&ch<='z')bianliangming = ch;   //变量名
        if(ch=='+'||ch=='-'||ch=='='||i==n)      //遇到符号
        {
            for(int j = last;j<i;j++)if(fangcheng[j]>='0'&&fangcheng[j]<='9')temp = temp*10+fangcheng[j]-'0'; //得到数字
            if(right)temp*=-1;if(fangcheng[last]=='-')temp*=-1;   //移项，标准化
            if(fangcheng[i-1]>='a'&&fangcheng[i-1]<='z')bianliang+=temp; //是变量系数
            else shuzi += temp*-1;                        //是数字
            if(ch=='='){left = false;right = true;}
            last = i;                                  //维护上一个符号
        } 
    }
    printf("%c=%.3f\n",bianliangming,shuzi*1.0/bianliang);
    return 0;
}
