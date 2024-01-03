#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
//dp[i][j]表示 到第i个物品，重量为j为止，最大价值  
//递推公式 如果第i个装不下，则dp[i][j]=dp[i-1][j];
//         如果第i个装得下，则dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]) 
//此题采用的方法是动态规划算法 
using namespace std;
int v;//体积 
int n;//数量 
int vo[50];
int va[50];
int dp[50][30000];
int main(){
	int i,j,k;
	while(~scanf("%d %d",&v,&n)){
		vo[0]=va[0]=0;
		for(i=0;i<=n;i++){
			for(j=0;j<=v;j++){
				dp[i][j]=0;
			}
		}
		for(i=1;i<=n;i++){
			cin>>vo[i]>>va[i];
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=v;j++){
				if(j<vo[i])dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j-vo[i]]+va[i],dp[i-1][j]);
			}
		}
		cout<<dp[n][v]<<endl;
	}
	return 0;
} 
