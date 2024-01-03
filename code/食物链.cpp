#include<iostream>
using namespace std;
bool edge[1001][1001];
int count=0;
bool v[1001];
int n,m;

int ans=-1;
void dfs(int a){
	int i;
	if(a>n){
		//cout<<"77"<<endl;
		ans=max(ans,count);
		
		cout<<"count="<<count<<endl;
		
		count=0;
		return;
	}
	for(i=1;i<=n+1;i++){
		if(edge[a][i]||i==n+1){
			if(i<=n){
				count++;
				cout<<a<<"->"<<i<<endl;
			}
			
			dfs(i);
			
		}
	}
	
}
int main(){
	cin>>n>>m;
	int i,j,k;
	int x,y;
	for(i=0;i<m;i++){
		cin>>x>>y;
		edge[x][y]=1;
	}
	for(i=1;i<=n;i++){
		cout<<"dfs("<<i<<"):"<<endl;
		dfs(i);
	}
	cout<<ans<<endl; 
	return 0;
}
