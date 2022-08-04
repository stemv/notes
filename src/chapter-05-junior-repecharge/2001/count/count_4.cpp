#include <iostream>
using namespace std;

int main(){
    int i,n,ans,sum[1001];
    sum[0]=0,sum[1]=1;
    
    cin>>n;
 
    for(i = 2 ; i <= n ; i++){
        ans = sum[i/2] + 1;
        sum [i] = sum[i-1] + ans;
    }
    
    cout<<sum[n] - sum[n-1]<<endl;
    
    return 0;
}
