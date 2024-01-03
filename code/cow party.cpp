#include<iostream>
using namespace std;
int n,m,x;
int e[1001][1001];
long long dp[1001][1001];
bool reach[1001];
long long length[1001];
//所有牛到达一个汇点的最短距离的最长距离，也就是在所有边均反向之后，该汇点到达其他点的最短距离的最长距离 
//此题的方法还是dj算法 
int main(){
	cin>>n>>m>>x;
	int i,j,k;
	int p,q,l;
	int node;
	int max=0;
	for(i=1;i<=n;i++){
		reach[i]=0;//一开始所有点均未到达 
		dp[i][i]=0;//所有点自己到自己是0 
		for(j=1;j<=n;j++){
			e[i][j]=-1;//所有边初始置为-1 
			dp[i][j]=100000000;//所有dp初始置为一个极大值 
		}
	}
	
	for(i=1;i<=m;i++){
		cin>>p>>q>>l;
		e[p][q]=l; 
		dp[p][q]=l;
	}//先正向边求解回家
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
	int huan;//置换中间变量 
	for(i=1;i<=n;i++){
		reach[i]=0;//一开始所有点均未到达 
		for(j=1;j<=n;j++){
			if(e[i][j]!=-1){
				//cout<<"&&"<<endl;
				dp[i][j]=e[i][j]; 
			}
			else dp[i][j]=10000;//所有dp初始置为一个极大值 
		}
	}//重置中间变量 
	
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
	}//此处注意！！！起点和终点反向，是为了求汇点最值（原点到各店值可以直接dj算出） 
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
