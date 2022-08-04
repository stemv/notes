#include <iostream>
using namespace std;

long long map[21][21];

int main(){
	int tx,ty,hx,hy;
	cin >> tx >> ty >> hx >> hy;

	for(int i=0;i<=tx;i++)
    	for(int j=0;j<=ty;j++)
        	map[i][j]=1;

	if(hx-2>=0 && hy-1>=0)
		map[hx-2][hy-1]=0;   
	if(hx-2>=0 && hy+1<=ty) 
		map[hx-2][hy+1]=0;
	if(hx-1>=0 && hy-2>=0)
		map[hx-1][hy-2]=0;
	if(hx-1>=0 && hy+2<=ty)
		map[hx-1][hy+2]=0;
	if(hx+1<=ty && hy-2>=0)
		map[hx+1][hy-2]=0;
	if(hx+2<=tx && hy-1>=0)
		map[hx+2][hy-1]=0;
	if(hx+1<=tx && hy+2<=ty)
		map[hx+1][hy+2]=0;
	if(hx+1<=tx && hy+1<=ty)
		map[hx+2][hy+1]=0;
	map[hx][hy]=0;

	for(int i=0;i<=tx;i++){
    	for(int j=0;j<=ty;j++){
        	if(map[i][j]){
            	if(i==0&&j==0) continue;
            	else if(i==0)  map[i][j]=map[i][j-1];
            	else if(j==0)  map[i][j]=map[i-1][j];
            	else map[i][j]=map[i-1][j]+map[i][j-1]; 
        	}
    	}
	}
	
	cout << map[tx][ty];

//	for(int i=0;i<=tx;i++){
//    	for(int j=0;j<=ty;j++)
//        	cout << map[i][j] << "\t";
//		cout << endl;
//	}

	return 0;
}

