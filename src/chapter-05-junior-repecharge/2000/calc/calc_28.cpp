#include<iostream>
#include<string.h>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    char ch,a[1010],str1[1010][10],str2[1010][10],t[10];
    int len,k1=0,k2=0,c=0,sum1=0,sum2=0,s=0,i,j,r=0,flag=0;
    cin>>a;
    len = strlen(a);
    a[len]='=';
    a[++len]='\0';
    if (a[0] != '-'){
        for (i=len; i>0; i--){
            a[i]=a[i-1];
        }
        a[0]='+';
        a[++len]='\0';
    }
    for (i=0; a[i]; i++){
        if (a[i]>='a' && a[i]<='z'){
            ch=a[i];
            if (i==0 || !(a[i-1]<='9'&&a[i-1]>='0')){
                for (j=len; j>i; j--){
                    a[j]=a[j-1];
                }
                a[i]='1';
                a[++len]='\0';
            }
        }
    }
    while (a[r++]!='=') ;
    r--;
    if (a[r+1]!='-'){
         for (i=len; i>r+1; i--){
            a[i]=a[i-1];
         }
         a[r+1]='+';
         a[++len]='\0';
     }
     for (i=0; a[i]; ){
        if (a[i]=='+'){
            t[c++]='+';
         }
        else if(a[i]=='-'){
            t[c++]='-';
        }
        else if (a[i]=='='){
            i++;
            continue;
        }
        while(a[i+1]!='+'&&a[i+1]!='-'&&a[i+1]!='='&&a[i]){
            
            t[c++]=a[++i];
            if (a[i]>='a'&&a[i]<='z'){
                flag=1;
            }
         }
        t[c]='\0'; 
        if (flag){
            if (i>r){
                t[0]=='+' ? t[0]='-' : t[0]='+';
            } 
            strcpy(str1[k1++],t);
            flag=0;
        }else{
            if (i<r){
                t[0]=='+' ? t[0]='-' : t[0]='+';
            }
            strcpy(str2[k2++],t);
        }
        c=0;
        i++;
        t[c]='\0';
     }
 
     for (i=0; i<k1; i++){
        s=0;
        for (j=0; str1[i][j]; j++){
            if (str1[i][j]>='0'&&str1[i][j]<='9'){
                s=s*10 +(str1[i][j]-'0');
            }
        } 
         if (str1[i][0]=='-'){
            sum1-=s;
         }else{
            sum1+=s;
         }
    }
     for (i=0; i<k2; i++){
        s=0;
        for (j=0; str2[i][j]; j++){
            if(str2[i][j]>='0'&&str2[i][j]<='9'){
                s=s*10 + (str2[i][j]-'0');
             } 
         }
         if (str2[i][0]=='-'){
            sum2-=s;
         }else{
            sum2+=s;
         }
     }
     if (sum1==0||sum2==0){
       cout<<ch<<"=0.000";
     }
     else{
         printf("%c=%.3f",ch,sum2*1.0/sum1);
     }
    return 0;
 }
