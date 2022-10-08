#include<cstdio>  
int main()
{  
    int op=1,dir=1,num=0,a=0,b=0;  
    char ch,id;  
    while((ch=getchar())!=EOF)
    {  
        if(ch>='a'&&ch<='z')
        {  
            id=ch;  
            if(num==0) num=1;
            a+=op*num*dir;
            num=0;  
        }else if(ch>='0'&&ch<='9')num=num*10+ch-'0';  
            else
            {
                b+=op*num*dir;  
                num=0;  
                op=1;  
                if(ch=='=')dir=-1;  
                    else if(ch=='-')op=-1;  
            }            
    }  
    printf("%c=%.3f",id,(float)-b/a+0);  
}