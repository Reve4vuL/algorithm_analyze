#include<iostream>
#define XX 251
using namespace std;
int n,m;
int road[XX][XX];
int chushi[XX][XX];
int dp[XX][XX];
int endlength[4000];
bool reach[XX];
int main(){
	int i,j,k,p,q;
	int x,y;
	int z;
	int node;
	int s=1;
	int initlength;
	int count=1;
	int maxx;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			road[i][j]=-1;
			dp[i][j]=1000000;
		}
		reach[i]=0;
		dp[i][i]=0;
	}
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		road[x][y]=z;
		road[y][x]=z;
		dp[x][y]=z;
		dp[y][x]=z;
	}
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			chushi[i][j]=road[i][j];
			chushi[j][i]=road[j][i];
		}
	}
	reach[s]=1;
	for(i=0;i<n-1;i++){
		node=-1;
			for(j=1;j<=n;j++){
				if(!reach[j]&&(dp[s][j]<dp[s][node]||node==-1)&&s!=j){
					node=j;
				}
			}
			//cout<<"node="<<node<<endl;
			for(j=1;j<=n;j++){
				if(road[node][j]!=-1)dp[s][j]=min(dp[s][j],dp[s][node]+road[node][j]);
			}
		reach[node]=1;
		//cout<<"reach["<<node<<"]="<<1<<endl;
	}
	initlength=dp[s][n];
	//cout<<initlength<<endl;
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			if(road[i][j]!=-1){
				for(k=1;k<=n;k++){
					for(p=k;p<=n;p++){
						road[k][p]=chushi[k][p];
						road[p][k]=chushi[p][k];
						if(road[p][k]!=-1){
							dp[p][k]=chushi[p][k];
							dp[k][p]=chushi[k][p];
						}
						else {
							dp[p][k]=1000000;
							dp[k][p]=1000000;
						}
					}	
				}
				for(k=1;k<=n;k++){
					dp[k][k]=0;
				}
				for(k=1;k<=n;k++)reach[k]=0;
				road[i][j]*=2;
				road[j][i]*=2;
				dp[i][j]=road[i][j];
				dp[j][i]=road[i][j];
				reach[1]=1;
//				for(int ii=1;ii<=n;ii++){
//					for(int jj=1;jj<=n;jj++){
//						cout<<"road["<<ii<<"]["<<jj<<"]="<<road[ii][jj]<<endl;
//					}
//				}
				//cout<<"******"<<endl;
				for(int ii=0;ii<n-1;ii++){
					node=-1;
						for(int jj=1;jj<=n;jj++){
							if(!reach[jj]&&(dp[s][jj]<dp[s][node]||node==-1)&&s!=jj){
								node=jj;
							}
						}
						//cout<<"node="<<node<<endl;
						for(int jj=1;jj<=n;jj++){
							if(road[node][jj]!=-1)dp[s][jj]=min(dp[s][jj],dp[s][node]+road[node][jj]);
						}
					reach[node]=1;
					//cout<<"reach["<<node<<"]="<<1<<endl;
				}
				endlength[count++]=dp[s][n];
			}
		}
	}
	
	maxx=endlength[1];
	for(i=1;i<count;i++){
		cout<<"endlength["<<i<<"]="<<endlength[i]<<endl;
		if(maxx<endlength[i])maxx=endlength[i];
	}
	cout<<maxx-initlength<<endl;
	return 0;
}
