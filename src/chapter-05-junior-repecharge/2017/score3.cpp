#include <stdio.h>
#include <iostream>
using namespace std;

int a,b,c;
double score;

int main(){
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);

    cin >> a >> b >> c;
    score = a*.2 + b*.3 + c*.5;
    cout << score << endl;

    return 0;
}

