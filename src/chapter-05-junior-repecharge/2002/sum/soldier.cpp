#include <bits/stdc++.h>
using namespace std;

long tx,ty,hx,hy,sum = 0,mp[21][21];

bool ishorse(int sx,int sy){
	if(sx==hx-1 && sy==hy-2)
		return 1;
	if(sx==hx+1 && sy==hy-2)
		return 1;
	if(sx==hx-2 && sy==hy-1)
		return 1;
	if(sx==hx+2 && sy==hy-1)
		return 1;	
	if(sx==hx-1 && sy==hy+2)
		return 1;
	if(sx==hx+1 && sy==hy+2)
		return 1;
	if(sx==hx-2 && sy==hy+1)
		return 1;
	if(sx==hx+2 && sy==hy+1)
		return 1;	
	if(sx==hx && sy==hy)
		return 1;	
	return 0;	
}

int walk(int sx,int sy){
	if(ishorse(sx,sy)) 
		return 0;

	mp[sx][sy]=mp[sx][sy] + 1;
	
	if(sx<tx)
		walk(sx+1,sy);
	if(sy<ty)
		walk(sx,sy+1);
		
	return 0;
}

int main(){
	for(int i=0;i<21;i++){
		for(int j=0;j<21;j++){
			mp[i][j]=0;
		}
	}	

	cin >> tx >> ty >> hx >> hy;
	walk(0,0);
	cout << mp[tx][ty] << endl;
	
	return 0;
}
