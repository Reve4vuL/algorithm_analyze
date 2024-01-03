#include<iostream>
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int a[2000][2000];
int dp[2000][2000];
int n;
int main(){
	int i,j,k;
	int min;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			for(j=0;j<i+1;j++){
				cin>>a[i][j];
			}
		}
		dp[0][0]=a[0][0];
		for(i=1;i<n;i++){
			dp[i][0]=dp[i-1][0]+a[i][0];
			dp[i][i]=dp[i-1][i-1]+a[i][i];
		}
		for(i=2;i<n;i++){
			for(j=1;j<i;j++){
				dp[i][j]=min(dp[i-1][j-1]+a[i][j],dp[i-1][j]+a[i][j]);
			}
		}
		min=dp[n-1][0];
		for(i=0;i<n;i++){
			if(min>dp[n-1][i])min=dp[n-1][i];
		}
		cout<<min<<endl;
	}
}
