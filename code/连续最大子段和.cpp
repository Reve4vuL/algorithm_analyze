#include<iostream>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20000
using namespace std;
int n;
int a[20000];
int dp[20000];

//�����������Ӷκͻ��ǲ��ö�̬�滮�ȽϺ�����
//dp[j]��ʾ�����j��Ԫ��Ϊֹ�����Ӷκͣ�j�±��0��ʼ�� 
//dp�ĵ���ʽ����dp[j]=max(a[j],dp[j-1]+a[j]); 
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
