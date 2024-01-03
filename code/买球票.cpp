#include<iostream>
using namespace std;
int dp[500][500]; 
int m,n;
int main(){
	int i,j,k;
	while(~scanf("%d %d",&m,&n)){
		for(i=0;i<=m;i++){
			for(j=0;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(i=1;i<=m;i++){
			dp[i][0]=1;
		}
		for(i=0;i<=m;i++){
			for(j=i+1;j<=n;j++){
				dp[i][j]=0;
			}
		}
		for(i=1;i<=m;i++){
			for(j=1;j<=i;j++){
				dp[i][j]=dp[i][j-1]+dp[i-1][j];
			} 
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
