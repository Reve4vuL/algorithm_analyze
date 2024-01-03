#include<iostream>
#include<cstring>
using namespace std;
int a[21][21];
int c[21];
int count=0;
int n,k,m;//n个点，k条边，m种颜色
//此题采用的是回溯法->子集树的想法 
//思路就是从第一个点开始，一个一个点往下建立树，每个节点有m个子节点（m中颜色）
//剪枝算法主要是看同色问题，如果有就剪枝 

bool same(int x){
	int i;
	for(i=1;i<=n&&i!=x;i++){
		if(c[x]==c[i]&&a[x][i]==1){
			return true;
		}
	}
	return false;
}//相同返回true，不同返回false 
void dfs(int s){
	//cout<<"&&"<<endl;
	int i,j,k;
	if(s>n)
	{
		count++;
	}//到最后一个节点为止都着色成功，计数器加一 
	else{
		for(i=1;i<=m;i++){
			c[s]=i;//第s的点着色i 
			if(!same(s)){
				dfs(s+1);//着色成功往下建树 
			}
			c[s]=0;//着色失败取消着色 
		}
	}
}
int main(){
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	cin>>n>>k>>m;
	int i,j;
	int x,y;
	for(i=1;i<=k;i++){
		cin>>x>>y;
		a[x][y]=a[y][x]=1;//无向图建边 
	}
	dfs(1);
	cout<<count<<endl;
	return 0;
}
