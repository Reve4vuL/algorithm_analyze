#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
//dp[i][j]��ʾ ����i����Ʒ������ΪjΪֹ������ֵ  
//���ƹ�ʽ �����i��װ���£���dp[i][j]=dp[i-1][j];
//         �����i��װ���£���dp[i][j]=max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]) 
//������õķ����Ƕ�̬�滮�㷨 
using namespace std;
int v;//��� 
int n;//���� 
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
