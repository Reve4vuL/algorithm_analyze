#include<iostream>
using namespace std;
int n,m,x;
int e[1001][1001];
long long dp[1001][1001];
bool reach[1001];
long long length[1001];
//����ţ����һ��������̾��������룬Ҳ���������б߾�����֮�󣬸û�㵽�����������̾��������� 
//����ķ�������dj�㷨 
int main(){
	cin>>n>>m>>x;
	int i,j,k;
	int p,q,l;
	int node;
	int max=0;
	for(i=1;i<=n;i++){
		reach[i]=0;//һ��ʼ���е��δ���� 
		dp[i][i]=0;//���е��Լ����Լ���0 
		for(j=1;j<=n;j++){
			e[i][j]=-1;//���б߳�ʼ��Ϊ-1 
			dp[i][j]=100000000;//����dp��ʼ��Ϊһ������ֵ 
		}
	}
	
	for(i=1;i<=m;i++){
		cin>>p>>q>>l;
		e[p][q]=l; 
		dp[p][q]=l;
	}//����������ؼ�
	for(i=0;i<n-1;i++){
		node=-1;
			for(j=1;j<=n;j++){
				if(!reach[j]&&(dp[x][j]<dp[x][node]||node==-1)&&x!=j){
					node=j;
				}
			}
			//cout<<"node="<<node<<endl;
			for(j=1;j<=n;j++){
				if(e[node][j]!=-1)dp[x][j]=min(dp[x][j],dp[x][node]+e[node][j]);
			}
		reach[node]=1;
		//cout<<"reach["<<node<<"]="<<1<<endl;
	}
	for(i=1;i<=n;i++){
		if(i!=x){
			length[i]=dp[x][i];
			//cout<<"length["<<i<<"]="<<length[i]<<endl;
		}
	}	 
	int huan;//�û��м���� 
	for(i=1;i<=n;i++){
		reach[i]=0;//һ��ʼ���е��δ���� 
		for(j=1;j<=n;j++){
			if(e[i][j]!=-1){
				//cout<<"&&"<<endl;
				dp[i][j]=e[i][j]; 
			}
			else dp[i][j]=10000;//����dp��ʼ��Ϊһ������ֵ 
		}
	}//�����м���� 
	
//	for(i=1;i<=n;i++){
//		for(j=1;j<=n;j++){
//			if(e[i][j]!=-1){
//				cout<<"e["<<i<<"]"<<"["<<j<<"]="<<e[i][j]<<endl;
//				cout<<"dp["<<i<<"]"<<"["<<j<<"]="<<dp[i][j]<<endl;
//			}
//		} 
//	}
	for(i=0;i<n-1;i++){
		node=-1;
			for(j=1;j<=n;j++){
				if(!reach[j]&&(dp[j][x]<dp[node][x]||node==-1)&&x!=j){
					node=j;
				}
			}
			//cout<<"node="<<node<<endl;
			for(j=1;j<=n;j++){
				if(e[j][node]!=-1)dp[j][x]=min(dp[j][x],dp[node][x]+e[j][node]);
			}
		reach[node]=1;
		//cout<<"reach["<<node<<"]="<<1<<endl;
	}//�˴�ע�⣡���������յ㷴����Ϊ��������ֵ��ԭ�㵽����ֵ����ֱ��dj����� 
	for(i=1;i<=n;i++){
		if(i!=x){
			length[i]+=dp[i][x];
			//cout<<"length["<<i<<"]="<<length[i]<<endl;
			if(max<length[i]){
				max=length[i];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
