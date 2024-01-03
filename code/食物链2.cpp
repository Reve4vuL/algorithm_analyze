#include<iostream>
using namespace std;
bool edge[1001][1001];
int count[1001];
bool v[1001];
int n,m;

int ans=-1;
void dfs(int a){
	int i;
	for(i=1;i<=n;i++){
		if(edge[a][i]){
			if(i<=n){
				count[i]=max(count[i],count[a]+1);
				//cout<<a<<"->"<<i<<endl;
			}
			
			dfs(i);
			
		}
	}
	
}
int main(){
	int maxa=-1;
	int i,j,k;
	int x,y;
	while(scanf("%d%d",&n,&m)!=EOF){
		for(i=0;i<m;i++){
			cin>>x>>y;
			edge[x][y]=1;
		}
		for(i=1;i<=n;i++){
			//cout<<"dfs("<<i<<"):"<<endl;
			dfs(i);
		}
		for(i=1;i<=n;i++){
			if(count[i]>maxa)maxa=count[i];
			count[i]=0;
		}
		cout<<maxa+1<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				edge[i][j]=0;
			}
		}
		maxa=0;
	} 
	
	return 0;
}
