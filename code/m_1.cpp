#include<iostream>
#include<cstring>
using namespace std;
int a[21][21];
int c[21];
int count=0;
int n,k,m;//n个点，k条边，m种颜色
bool same(int x){
	int i;
	for(i=1;i<=n&&i!=x;i++){
		if(c[x]==c[i]&&a[x][i]==1){
			return true;
		}
	}
	return false;
}
void dfs(int s){
	//cout<<"&&"<<endl;
	int i,j,k;
	if(s>n)
	{
		count++;
	}
	else{
		for(i=1;i<=m;i++){
			c[s]=i;
			if(!same(s)){
				dfs(s+1);
			}
			c[s]=0;
		}
	}
}
int main(){
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	cin>>n>>k>>m;
	int i,j;
	int x,y;
	for(i=1;i<=k;i++){
		cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	dfs(1);
	cout<<count<<endl;
	return 0;
}