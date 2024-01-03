//采用求连通子图的方法求解炼丹术
//题设可以得知每种药材只能作为稳定剂一次，所以有向边的终点只可以做一次
//于是就不用考虑分叉上的连通子图
#include<iostream>
#include<cstring>
using namespace std;
int g[1000001];//记录药材的稳定剂
bool xuan[1000001];//记录此药材是否作为稳定剂过 
int n;
int count=0;
void dfs(int x){
	int i=x;
	while(xuan[i]==false){
		xuan[i]=true;
		i=g[i];
	}
	if(x==i)count=(count+1)%998244353;
}
int main(){
	cin>>n;
	int i,j,k;
	unsigned long long sum=1;
	memset(xuan,0,sizeof(xuan));
	for(i=1;i<=n;i++){
		cin>>g[i];
	}
	for(i=1;i<=n;i++){
		if(xuan[i])continue;
		dfs(i);
	}
	for(i=1;i<=count;i++){
		sum=(sum*2)%998244353;//这一步比较不容易想到，假设有n个元素，他的子集树最后一层的元素个数是2^n-1 
	}
	cout<<sum-1<<endl;
	return 0;
} 
