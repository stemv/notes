#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char func[1000];
    long lcs=0,rcs=0,lxs=0,rxs=0;
	int dh = 0,fh=0; //dh=0左dh=1右，fh=0加好,fh=1减号 
	char c;	//存变量 
    cin >> func;

	int len = strlen(func);
	long num = 0;
	for(int i=0;i<len;i++){
		if(func[i]=='-'){
			if(num>0){
				if(dh==0){
					if(fh==0) lcs = lcs + num;
					else lcs = lcs -num;
				}else{
					if(fh==0) rcs = rcs + num;
					else rcs = rcs - num;
				}
			}
			fh=1;
			num = 0;
		}
		if(func[i]=='+'){
			if(num>0){
				if(dh==0){
					if(fh==0) lcs = lcs + num;
					else lcs = lcs -num;
				}else{
					if(fh==0) rcs = rcs + num;
					else rcs = rcs - num;
				}
			}
			fh=0;
			num = 0;
		}
		if(func[i]=='='){
			if(num>0){
				if(dh==0){
					if(fh==0) lcs = lcs + num;
					else lcs = lcs -num;
				}else{
					if(fh==0) rcs = rcs + num;
					else rcs = rcs - num;
				}
			}
			dh = 1;
			num = 0;
		}
		if(func[i]>='0' && func[i]<='9'){
			num = num * 10 + func[i] - '0';
		}
		if(func[i]>='a' && func[i]<='z'){
			c = func[i]; 
			if(num==0){
				if(fh==1) num = -1;
				else num =1;
			}else{
				if(fh==1) num = -num;
			}
			if(dh==0){
				lxs= lxs + num;
			}else{
				rxs = rxs + num;
			}
			num = 0;
			fh = 0;
		}
		
		//cout << func[i] << num<< lxs << lcs << rxs << rcs << endl;
		
	}	    
     
    printf("%c=%.3f",c,(double)(rcs-lcs) / (double)(lxs -rxs) );

    return 0;
}
