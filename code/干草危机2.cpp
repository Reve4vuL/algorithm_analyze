#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int father[2001];
//此题是很典型的普利姆算法
//注意几种算法的区别
//普利姆算法       ->以一个点集合为起点，寻找这些点集合所在的边集合中最小的那个边（边的终点不可以在点集合中），直至所有点都在点集合中
//                 ->核心就是father[]数组，用来记录 
//克鲁斯卡尔算法   ->每次都在所有边中寻找最短边当且仅当边的始点和终点不全在点集合中，并把此边的两个点加入点集合
//佛洛依德算法     ->循环变量 k,i,j   ij表示矩阵，k表示迭代次数 
struct road{
	int s;
	int e;
	int length;
	bool choose=0;
	bool operator <(const road &c){
		return length<c.length; 
	}
};
road a[10001];
int baba(int x){
	return x==father[x]?x:father[x]=baba(father[x]);
}
int main(){
	cin>>n>>m;
	int i,j,k;
	int x,y,z;
	int count=0;
	int maxx=-1;
	for(i=1;i<=n;i++){
		father[i]=i;
	}
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[i].e=x;
		a[i].s=y;
		a[i].length=z;//这边的漏洞在于没有将起点和终点从小到大排放 
	}

	sort(a+1,a+m+1);//求解最小生成树的时候需要将边从小到大进行排列 
//	for(i=1;i<=m;i++){
//		cout<<a[i].e<<"<->"<<a[i].s<<"="<<a[i].length<<endl;
//	}
	for(i=1;i<=m;i++){
		x=a[i].s;
		y=a[i].e;
		int u=baba(x); 
		int v=baba(y);//每次找出原始两个点的父节点，因为此边已被选取，如果两点的父节点不一样，即改为小的那个点的父节点 
		if(u!=v){
			//cout<<i<<endl;
			father[v]=u;
			maxx=max(maxx,a[i].length);//选中了这个边，就要判断它是否比前面选中的要更大 
		}

	}
	cout<<maxx<<endl;
	return 0;
}
