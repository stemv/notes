#include <iostream>
using namespace std;

long int n,cnt = 1;

void count(long v){
	for(long i=1;i<=v/2;i++){
		cnt = cnt + 1;
		count(i);
	}
}

int main(){
	cin >> n;
	count(n);
	cout << cnt << endl;
	return 0;
}
