#include <iostream>
using namespace std;
 
int main(){
    int n,sum=0,i=0;
    cin>>n;

    while(sum < n){
        i++;
        sum += i;
    }//�ҵ�N�ڵ�i��б����
 
    if(i % 2 == 0)
        cout<< n-sum+i << "/" << i+1-(n-sum+i) << endl;
    else
        cout<< i+1-(n-sum+i) << "/" << n-sum+i << endl;
    
    return 0;
}
