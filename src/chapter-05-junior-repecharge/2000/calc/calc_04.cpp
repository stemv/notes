#include<cstdio>
#include<cstring>

int main(){
    char c,s[505];
    int x=0;                        //x为未知数系数（=左）
    int y=0;                        //y为常数项（=右）
    int a=0;                        //a为正在读入的常数值
    int f=1;                        //f为a的符号
    int f1=1;                       //f1为a是否在等号左边
    int i;
     
    double ans;
    scanf("%s",s);
    for (i=0;i<strlen(s);i++){
        if (s[i]>='0'&&s[i]<='9') 
            a=a*10+s[i]-48;         //是数字就存 
        if (s[i]=='-'){
            y+=-1*f*f1*a;           //常数项保存，如果前面是未知数此时a为0 
            f=-1;
            a=0;
        }
        if (s[i]=='+'){
            y+=-1*f*f1*a;           //同上 
            f=1;
            a=0;
        }
        if (s[i]=='='){
            y+=-1*f*f1*a;           //同上 
            f1=-1;
            f=1;
            a=0;
        }
        if (s[i]>='a'&&s[i]<='z'){
            c=s[i];
            if(a) 
                x+=f*a*f1; 
            else 
                x+=f*f1;            //未知数系数保存。 
            f=1;
            a=0;
        }
    }

    y+=-1*f*f1*a;                   //最后一个常数项。 
    ans=1.0*y/x;                    //计算结果。 

    if (ans<=0.000 && ans>-0.0005) 
        printf("%c=0.000",c);       //最后一个点会卡掉a=-0.000，注意(-0.0005,0.000]的区间。 
    else 
        printf("%c=%.3lf",c,ans);

    return 0;
}


