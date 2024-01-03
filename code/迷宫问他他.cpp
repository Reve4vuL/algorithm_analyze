#include<iostream>
using namespace std;
char rode[10][10];
int dfsx[4]={1,-1,0,0};
int dfsy[4]={0,0,1,-1};
void find(int x,int y){
	if(x==7&&y==7){
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cout<<rode[i][j];
			}
			cout<<endl;
		}
		exit(0);
	}
	
	else{
		for(int i=0;i<4;i++){
			int newx=x+dfsx[i];
			int newy=y+dfsy[i];
			if(newx>=0&&newy<=7&&newy>=0&&newy<=7&&rode[newx][newy]=='O'){
				rode[newx][newy]=' ';
				find(newx,newy);
				rode[newx][newy]='O';
			}
		}
	}
	return ;
		
}
int main(){
	int i,j,k;
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			cin>>rode[i][j];
		}
	}
	rode[0][0]=' ';
	find(0,0);
	return 0;
}
