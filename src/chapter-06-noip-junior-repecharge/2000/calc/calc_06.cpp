#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

string op;
int a, b, c, d;
int str[100], ans;

void func(int l, int r, int x, int y){
    int j = 0, k = 0, flag = 1;
    x = y = 0;
    memset(str, 0, sizeof(str));
    for(int i = l; i <= r; i++){
        switch(op[i]){
            case '+':
                flag = 1, y += str[j++], k = 0;
                break;
            case '-':
                flag = -1, y += str[j++], k = 0;
                break;
        }
        if(isdigit(op[i])){
            str[j] = (k * 10 + op[i] - '0') * flag;
            k = str[j] * flag;
        }
        if(islower(op[i])){
            if(i == l || !isdigit(op[i-1]))
                x += flag;
            else{
                x += str[j++];
                k = 0;
            }
        }
    }
    y += str[j];
    if(l == 0)
        a = x, b = y;
    else
        c = x, d = y;
}

int main(){
    char ch;
    while(cin >> op){
        int len = op.size();
        int k = op.find("=");
        for(int i = 0; i < len; i++)
            if(islower(op[i]))
                ch = op[i];
        int flag = 1, j = 0;
        func(0, k - 1, a, b);
        func(k + 1, len - 1, c, d);
        if(d - b != 0)
            printf("%c=%.3f\n", ch, (d - b) * 1.0 / (a - c));
        else
            printf("%c=0.000\n", ch);
    }
    return 0;
}
