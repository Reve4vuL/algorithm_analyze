#include<iostream>
#define min(x,y) (x)<(y)?(x):(y)
using namespace std;
bool reach[1450];
int dp[1450][1450];
int v[1450][1450];
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
			dp[i][j]=10000;     //���г�ʼdp��Ϊ����� 
		}
	}
	for(i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(i=0;i<m;i++){
		cin>>x>>y>>z;
		v[x][y]=z;
		v[y][x]=z;
		dp[x][y]=z;
		dp[y][x]=z;
	}
	for(i=0;i<n-1;i++){
		node=-1;
			for(j=1;j<=n;j++){
				if(!reach[j]&&(dp[s][j]<dp[s][node]||node==-1)&&s!=j){
					node=j;
				}
			}
			//cout<<"node="<<node<<endl;
			for(j=1;j<=n;j++){
				if(v[node][j]!=-1)dp[s][j]=min(dp[s][j],dp[s][node]+v[node][j]);
			}
		reach[node]=1;
		//cout<<"reach["<<node<<"]="<<1<<endl;
	}
	cout<<dp[s][t]<<endl; 
	return 0;
}
