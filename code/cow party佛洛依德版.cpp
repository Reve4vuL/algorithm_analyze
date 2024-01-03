#include<iostream>
#define INF 0x3f3f3f3f

using namespace std;
int c[1001][1001];
long long dp[1001][1001];
long long length[1001];
long long maxx=0;
int n,m,x;
void input(){
	cin>>n>>m>>x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=INF;
			dp[i][j]=INF;
		}
	}
	
	int x,y,l;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>l;
		if(c[x][y]>l){
			c[x][y]=l;
		}
		dp[x][y]=l;
	}
}
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(i!=x){
			length[i]=dp[i][x]+dp[x][i];
			if(length[i]>maxx)maxx=length[i];	
		}
	}
}
int main(){
	input();
	solve();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
//		}
//		cout<<"length["<<i<<"]="<<length[i]<<endl;
//	}
	cout<<maxx<<endl;
	return 0;
}
