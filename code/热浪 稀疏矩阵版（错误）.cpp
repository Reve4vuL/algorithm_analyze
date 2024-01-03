#include<iostream>
#include<cstring>
#define dian 2001
#define bian 6201
using namespace std;
int dis[dian];
int n,m,s,t;
int reach[dian];
struct edge{
	int s;
	int t;
	int s1;
	int t1;
	int length;
}a[bian];
void dij(){
	int i,j,k;
	for(i=1;i<=n;i++){
		reach[i]=0;
		dis[i]=200000;
	}
	dis[s]=0;
	for(i=0;i<n-1;i++){
		int mini,min=199999;
		for(j=1;j<=n;j++){
			if(!reach[j]&&dis[j]<min){
				mini=j;
				min=dis[j];
			}
		}
		//cout<<"min="<<min<<endl;
		//cout<<"mini="<<mini<<endl;
		reach[mini]=1;
		for(j=1;j<=n;j++){// 在结构体中找出始边为mini，终边为j的
			for(k=1;k<=m;k++){
				if(mini<j){
					if(a[k].s==mini&&a[k].t==j){
						if(dis[j]>dis[mini]+a[k].length){
							dis[j]=dis[mini]+a[k].length;
						}	
					}
				}
				else{
					if(a[k].s1==mini&&a[k].t1==j){
						if(dis[j]>dis[mini]+a[k].length){
							dis[j]=dis[mini]+a[k].length;
						}	
					}
				}
			}
			
		}
	}
}
int main(){
	cin>>n>>m>>s>>t;
	int i,j,k;
	int x,y,z;
	
	
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
			a[i].s=x<y?x:y;
			a[i].t=x>=y?x:y;
			a[i].s1=x>=y?x:y;
			a[i].t1=x<y?x:y;
			a[i].length=z;

		
		//cout<<"a["<<x<<"]["<<y<<"]="<<a[x][y]<<endl;
		//if(z<a[x][y]){}
	}
	dij();
	for(i=1;i<=n;i++){
		cout<<"dis["<<i<<"]="<<dis[i]<<endl;
	}
	cout<<dis[t]<<endl;
}