#include <iostream>
using namespace std;

int main(){
    int a[1001]={0};
    int n,p;
    cin >> n;
    
    a[1]=1;
    a[2]=2;
    for(p=3;p<=n;p++){
        if(p%2==1){
            a[p]=a[p-1];
        } else {
            a[p]=a[p-1]+a[p/2];
        }
    }
    
    cout << a[n] << endl;
    
    return 0;    
}