#include<iostream>
#include<cstring>
#define N 255
using namespace std;

//此题的主要突破（优化）在于使用了from数组
//因为我们知道如果加倍的边不是最短路径上的那条，对结果是没有影响的。
//所以用此数组记录路径，并可以加倍路径上的任意一条边 
int n,m,al[N][N],ad[N][N];
int reach[N],from[N],f[N],dist[N];
//还有细致的点在于采用两个数组 al和ad，al记录长边，ad记录短边，以防输入重复边
//主要的算法采用还是dj算法 


void dij(){
	memset(reach,0,sizeof(reach));
	memset(dist,1,sizeof(dist));
	dist[1]=0;
	int i,j,k;
	for(i=0;i<n-1;i++){
		int mini,min=20000000;
		for(j=1;j<=n;j++){
			if(!reach[j]&&dist[j]<min){
				min=dist[j];
				mini=j;
			}
		}
		reach[mini]=1;
		for(j=1;j<=n;j++){
			int now=ad[mini][j]<al[mini][j]?ad[mini][j]:al[mini][j];
			if(dist[j]>dist[mini]+now){
				dist[j]=dist[mini]+now;
				f[j]=mini;
			}
		}
	}
}
int main(){
	memset(al,1,sizeof(al));
	memset(ad,1,sizeof(ad));
	int i,j,k;
	int x,y,z;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		if(ad[x][y]<z){
			if(al[x][y]<=z)continue;
			al[x][y]=al[y][x]=z;
		}
		al[x][y]=ad[x][y];
		al[y][x]=ad[y][x];
		ad[x][y]=ad[y][x]=z;
	}
	for(i=1;i<=n;i++){
		ad[i][i]=0;
	}
	dij();
	int chushi=dist[n];
	int maxx=0;
	//cout<<dist[n]<<endl;
	//cout<<"&&&"<<endl;
	for(i=1;i<=n;i++){
		from[i]=f[i];
	}
	for(i=n;i!=1;i=from[i]){
		ad[from[i]][i]*=2;
		ad[i][from[i]]*=2;
		dij();
		if(dist[n]>maxx)maxx=dist[n];
		//cout<<dist[n]<<endl;
		ad[from[i]][i]/=2;
		ad[i][from[i]]/=2;
	}
		cout<<maxx-chushi<<endl;
	return 0;
}
