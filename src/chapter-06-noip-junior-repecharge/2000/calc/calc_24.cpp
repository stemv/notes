#include<stdio.h>
#include<string.h>     
int main()  
{  
    char s[110],c;      
    int l,i=0,t=0,k=0,x=0,y=0,f=0;
    //x为未知数的系数和，y为常熟和 
    //t=0在等号左边 t=1在等号右边 负号k=1;  
    double sum; 
    scanf("%s",s);  
    l=strlen(s);
    while(i<l)  
    {  
        if(s[i]=='=')   
        {  
            i++;  
            t=1;  //标记运行到了等号右边 
        }  
        else if(s[i]=='-')  
        {  
            i++;  
            k=1;  //标记负号 
        }  
        else if(s[i]=='+') 
        {
            i++; 
        }  
        f=0; 
        while(s[i]>='0'&&s[i]<='9')  
            f=f*10+s[i++]-'0';  
        if(s[i]>='a'&&s[i]<='z')  
        {  
            c=s[i++];  
            if((k==0&&t==0)||(k==1&&t==1)) //未知数移到左边 
                x+=f;  
            else 
                x-=f; 
            k=0; 
        }  
        else  
        {  
            if((k==0&&t==0)||(k==1&&t==1)) //常数移到右边 
                y-=f;  
            else 
                y+=f; 
            k=0; 
        }  
    }  
    sum=1.0*y/x;  
    printf("%c=%.3lf\n",c,sum); 
}  
