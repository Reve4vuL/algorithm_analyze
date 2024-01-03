#include<iostream>

using namespace std;
int road[2001][2001];
bool reach[2001];
int n,m; 
int maxx=-1;
bool pan(bool *reach){
	int i;
	for(i=1;i<=n;i++){
		if(reach[i]==0){
			return 1;
		}
	}
	return 0;
}
void dfs(int x){
	reach[x]=1;
	int min=10000;
	for(int i=1;i<=n;i++){
		if(reach[i]==0&&i!=x)if(min>road[x][i]&&road[x][i]!=-1){
			min=i;
			if(maxx<road[x][i])maxx=road[x][i];
			cout<<"&&"<<endl;
		}
	}
	
	if(min!=10000)dfs(min);
	else return; 
}
int main(){
	int i,j,k;
	int x,y,z;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			road[i][j]=-1;
		}
		reach[i]=0;
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		road[x][y]=z;
		road[y][x]=z;//Ë«ÏòÍ¨Â· 
	} 
	dfs(1);
	cout<<maxx<<endl;
	return 0;
	
}
