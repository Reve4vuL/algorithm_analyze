#include<iostream>
#include<cstring>
#define dian 2501
#define bian 6201
using namespace std;
short int a[dian][dian];//short int 2B -32768->32767
int dis[dian];//int 4B -2147483648->+2147483647
int n,m,s,t;
int reach[dian];
void dij(){
	int i,j,k;
	for(i=1;i<=n;i++){
		reach[i]=0;
		dis[i]=30000;
	}
	dis[s]=0;
	for(i=0;i<n-1;i++){
		int mini,min=30000;
		for(j=1;j<=n;j++){
			if(!reach[j]&&dis[j]<min){
				mini=j;
				min=dis[j];
			}
		}
		//cout<<"min="<<min<<endl;
		//cout<<"mini="<<mini<<endl;
		reach[mini]=1;
		for(j=1;j<=n;j++){
			if(dis[j]>dis[mini]+a[mini][j]){
				dis[j]=dis[mini]+a[mini][j];
			}
		}
	}
}
int main(){
	cin>>n>>m>>s>>t;
	int i,j,k;
	int x,y,z;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][j]=30000;
		}
	}
	for(i=1;i<=n;i++){
		a[i][i]=0;
	}
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
		//cout<<"a["<<x<<"]["<<y<<"]="<<a[x][y]<<endl;
		//if(z<a[x][y]){}
	}
	dij();
//	for(i=1;i<=n;i++){
//		cout<<"dis["<<i<<"]="<<dis[i]<<endl;
//	}
	cout<<dis[t]<<endl;
	return 0;
}