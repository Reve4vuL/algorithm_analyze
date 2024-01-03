//使用dj算出最小边，并使用maxx存取边上的最大噪声
 


#include<iostream>
using namespace std;
short int C,S,Q;
int path[101][101];
int dp[101];
bool reach[101];
short int before[101];
int maxx=0;
int count=1;

int main(){
	int u,v,w;
	int i,j,k;
	int a,b;
	while(~scanf("%d%d%d",&C,&S,&Q)){
		for(i=1;i<=C;i++){
			for(j=1;j<=C;j++){
				path[i][j]=2000000;
			}
		}
		for(i=1;i<=S;i++){
			cin>>u>>v>>w;
			if(w<path[u][v]){
				path[u][v]=w;
				path[v][u]=w;
			}
		}
		for(i=1;i<=C;i++){
			path[i][i]=0;
		}
		//初始化数据
		cout<<"Case #"<<count++<<endl; 
		for(i=1;i<=Q;i++){
			cin>>a>>b;
			maxx=0;
			for(j=1;j<=C;j++){
				dp[j]=2000000;
				reach[j]=0;
			}
			dp[a]=0;
			
			for(j=0;j<C-1;j++){
				int mini,min=2000000;
				for(k=1;k<=C;k++){
					if(!reach[k]&&dp[k]<min){
						mini=k;
						min=dp[k];
					}
				}
				//cout<<"mini="<<mini<<endl;
				reach[mini]=1;
				for(k=1;k<=C;k++){
					if(dp[k]>dp[mini]+path[mini][k]){
						dp[k]=dp[mini]+path[mini][k];
						before[k]=mini;
					}
				}
			}
			//cout<<dp[b]<<endl;
			k=b;
			if(dp[b]!=2000000)while(k!=a){
				if(path[k][before[k]]>maxx)maxx=path[k][before[k]];
				//cout<<k<<"->";
				k=before[k];
			}
			
			//cout<<endl;
			if(k!=a){
				cout<<"no path"<<endl;
			}
			else cout<<maxx<<endl;
		} 
	}

	return 0;
}
