//#include<bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    char c;                         //用于读入字符
    char x;                         //保存未知数
    int lxs=0,rxs=0;                //未知数左边系数和右边系数
    int lcs=0,rcs=0;                //左边常数和右边常数
    int lor=0;                      //在左边还是右边的标识符（0是左，1是右）
    int num=0;                      //用于保存当前操作数
    int opera=0;                    //操作标识符（0是加，1是减）
	
    while(scanf("%c",&c)!=EOF){     //每次读入一个字符
        if(c>='0'&&c<='9'){         //遇到数字
            num=num*10+c-'0';       //把字符串编程数值
        }else if(c=='+'){           //遇到+
            if(lor==0){             //在等号左
                if(opera==0){       //是+号或无号
                    lcs+=num;       //
                }else{              //是-号
                    lcs-=num;
                }
            }else{                  //在等号右边
                if(opera==0){       //是+号或无号
                    rcs+=num;
                }else{
                    rcs-=num;
                }
            }
            num=0;                  //操作数设置为0
            opera=0;                //
        }else if(c=='-'){
            if(lor==0){
                if(opera==0){
                    lcs+=num;
                }else{
                    lcs-=num;
                }
            }else{
                if(opera==0){
                    rcs+=num;
                }else{
                    rcs-=num;
                }
            }
            num=0;
            opera=1;
        }else if(c=='='){
            if(lor==0){             
                if(opera==0){
                    lcs+=num;
                }else{
                    lcs-=num;
                }
            }else{
                if(opera==0){
                    rcs+=num;
                }else{
                    rcs-=num;
                }
            }
            num=0;
            opera=0;
            lor=1;            //转变等式方位
        }else if(c>='a'&&c<='z'){    //如果是字母
            x=c;                   //保存未知数
            if(num==0){
                num=1;
            }
            if(lor==0){
                if(opera==0){
                    lxs+=num;
                }else{
                    lxs-=num;
                }
            }else{
                if(opera==0){
                    rxs+=num;
                }else{
                    rxs-=num;
                }
            }
            num=0;
        }
    }
    if(num!=0){           //3    
        if(opera==0){
            rcs+=num;
        }else{
            rcs-=num;
        }
    }
    double ans=(double)(rcs-lcs)/(double)(lxs-rxs);
    if(ans==0.0){                                   //4
        ans=abs(ans);
    } 
    printf("%c=%.3f",x,ans);                        //5
    return 0;
}