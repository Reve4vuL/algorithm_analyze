#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20000
using namespace std;
int n;
int a[20000];
int dp[20000];

//求解连续最大子段和还是采用动态规划比较好做。
//dp[j]表示到达第j个元素为止最大的子段和（j下标从0开始） 
//dp的递推式在于dp[j]=max(a[j],dp[j-1]+a[j]); 
int main(){
	int i,j,k;
	int maxi=-1;
	while((scanf("%d",&n))!=EOF){
		for(i=0;i<n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		dp[0]=a[0]>0?a[0]:0;
		for(j=1;j<n;j++){
			dp[j]=max(a[j],dp[j-1]+a[j]);
		}
		for(i=0;i<n;i++){
			if(dp[i]>maxi)maxi=dp[i];
		}
		cout<<maxi<<endl;
		maxi=-1;
	}
	return 0;
} 
