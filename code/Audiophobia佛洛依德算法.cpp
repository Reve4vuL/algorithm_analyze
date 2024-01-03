//�㷨������road[][]�������ͼ�ı� 20000����������֮��û�б�
//dp[][]��ʾ����֮�����̾��룬ʹ��kk��������n��
//��ͳ���������㷨 i,j,k dp[j][k]=min(dp[j][k],(dp[j][i]+dp[i][k])) 
#include<iostream>
#define MAX 101
#define INF 0x3f3f3f3f
using namespace std;
int road[MAX][MAX];
int dp[MAX][MAX];
int maxedge[MAX][MAX];//����������·���ϵ���� 


int main(){
	int C,S,Q;
	int u,v,w;
	int a,b;
	int i,j,k;
	int kk;
	int count=0;
	while(~scanf("%d%d%d",&C,&S,&Q)){
		for(i=1;i<=C;i++){
			for(j=1;j<=C;j++){
				road[i][j]=INF;
			}
		}
		for(i=1;i<=S;i++){
			cin>>u>>v>>w;
			if(w<road[u][v]){
				road[u][v]=w;
				road[v][u]=w;
			}
		}
		
//		for(i=1;i<=C;i++){
//			for(j=1;j<=C;j++){
//				dp[i][j]=road[i][j];
//				maxedge[i][j]=0;
//			}
//		}

//		for(i=1;i<=C;i++){
//			for(j=1;j<=C;j++){
//				cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		for(kk=1;kk<=C;kk++){
			for(i=1;i<=C;i++){
				for(j=1;j<=C;j++){
					road[i][j]=min(road[i][j],max(road[i][kk],road[kk][j]));
				}
			}
		}
//		for(i=1;i<=C;i++){
//			for(j=1;j<=C;j++){
//			//	cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<" ";
//				cout<<"road["<<i<<"]["<<j<<"]="<<road[i][j]<<" ";
//			}
//			cout<<endl;
//		}
	cout<<"Case #"<<++count<<endl;
		for(i=1;i<=Q;i++){
			cin>>a>>b;
			if(road[a][b]!=INF)cout<<road[a][b]<<endl;
			else cout<<"no path"<<endl;
		}
	}
	return 0;
} 
