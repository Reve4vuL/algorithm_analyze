//dp 放苹果
//m 苹果  n 盘子 
#include<iostream>
#include<cstring>
using namespace std;
int m,n;
int dp[101][101];

int solve(int m,int n){
	if(dp[m][n]!=0)return dp[m][n];
	if(n==1||m==0){
		dp[m][n]=1;
		return dp[m][n];
	}
	else if(m<n){
		dp[m][n]=solve(m,m);
		return dp[m][n];
	}
	else if(m==n){
		dp[m][n]=1+solve(m,n-1);
		return dp[m][n];
	}
	else {
		dp[m][n]=solve(m-n,n)+solve(m,n-1);
		return dp[m][n];
	}
}
int main(){
	while (scanf("%d %d",&m,&n)!=EOF){
		memset(dp,0,sizeof(dp));

		cout<<solve(m,n)<<endl;
//		for(int i=0;i<=m;i++){
//			for(int j=0;j<=n;j++){
//				cout<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	}
	return 0;
} 
