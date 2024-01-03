#include<iostream>
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
bool reach[2000];
int dp[2000];
int v[2000][2000];
int n,m,s,t;
int main(){
	cin>>n>>m>>s>>t;
	int i,j,k;    //ѭ������ 
	int x,y,z;      //����ʼ���յ�ļǺ�
	int node; 
	for(i=1;i<=n;i++){
		reach[i]=0;   //U������û�пɴ�� 
	} 
	reach[s]=1;     //��ʼ��ɴ� 
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			v[i][j]=-1;    //�����б�����Ϊ-1 
			dp[j]=50000;     //���г�ʼdp��Ϊ����� 
		}
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		v[x][y]=z;
		v[y][x]=z;
		if(x==s){
			dp[y]=z;
		}
	}
	dp[s]=0;
	for(i=0;i<n-1;i++){
		node=-1;
			for(j=1;j<=n;j++){
				if(!reach[j]&&(node==-1||dp[j]<dp[node])){
					node=j;
				}
			}
			//cout<<"node="<<node<<endl;
			for(j=1;j<=n;j++){
				if(v[node][j]!=-1)dp[j]=min(dp[j],dp[node]+v[node][j]);
			}
		reach[node]=1;
		//cout<<"reach["<<node<<"]="<<1<<endl;
	}
	cout<<dp[t]<<endl; 
	return 0;
}
