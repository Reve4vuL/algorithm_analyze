#include<iostream>
using namespace std;
int dp[500][500]; 
int m,n;
int main(){
	int i,j,k;
	while(~scanf("%d %d",&m,&n)){
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				dp[i][j]=0;//所有递推数组初值置为0 
			}
		}
		for(i=0;i<m;i++){
			dp[i][0]=1;//全都是拿50元的，只有一种排队方式 
		}
		for(i=0;i<m;i++){
			for(j=i+1;j<n;j++){
				dp[i][j]=0;//拿100元的比50元的多，没有可以找的完的情况 
			}
		}
		for(i=1;i<=m;i++){
			for(j=0;j<=i;j++){
				dp[i][j]=dp[i][j-1]+dp[i-1][j];//分为两种子情况，一种是i个50和j-1个100，一个是i-1个50和j个100； 
			} 
		}
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
