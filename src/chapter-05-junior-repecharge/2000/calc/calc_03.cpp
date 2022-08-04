#include<cstdio>
 
int main(){
    int op=1,dir=1,num=0,a=0,b=0;
    char ch,id;
    while((ch=getchar())!=EOF){
        if(ch>='a'&&ch<='z'){           //如果是变量，
            id=ch;                      //用id记录变量名
            if(num==0)
                num=1;                  //前面如果没有系数，则系数是1
            a+=op*num*dir;              //不管有没有，最终都加入运算
            num=0;                      //让num回归常态
        }else if(ch>='0'&&ch<='9')      //如果是数字，用num记录下来数值
            num=num*10+ch-'0';
        else{                           //如果既不是变量，又不是数字，那就是运算符号。
            b+=op*dir*num;              /*巧妙之处*/
            num=0;                      //算是对num、op的一种重置
            op=1;                       //让他们回到原始应该有的状态，不影响以后的操作及判断
            if(ch=='=')                 //dir和op一样，用来表示数值的符号
                dir=-1;
            else if(ch=='-')        
                op=-1;
        }
    }
    printf("%c=%.3f",id,(float)-b/a+0); //此处的思想是ax+b=0;即x=-b/a;
    return 0;
}
