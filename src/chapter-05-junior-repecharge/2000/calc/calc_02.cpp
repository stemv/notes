#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char s[1200];
	cin >> s;
	
	int l=strlen(s);
	int i=0,t=0,k=0,x=0,y=0;

	char c;
	while (i<l){
		if (s[i]=='='){
			i++;
			t=1;
		}
		if (s[i]=='-'){
			i++;
			k=1;
		}
		if (s[i]=='+') i++;
		int f=0;
		while (s[i]>='0' && s[i]<='9')
			f=f*10+s[i++]-'0';
		if (s[i]>='a' && s[i]<='z'){
			if(f==0)
				if(k=1) f = -1;
				else f = 1;
			c=s[i++];
			if ( (k+t)%2 ==0 ) 
				x+=f;
			else 
				x-=f;
			k=0;
		}else{
			if ( (k+t)%2 ==0 ) 
				y-=f;
			else 
				y+=f;
			k=0;
		}
	}
	
	double ans=y*1.000/x;
	printf("%c=%.3lf\n",c,ans);
	
	return 0;
}
