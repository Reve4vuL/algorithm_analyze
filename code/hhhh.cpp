#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int most=0;
struct chocolate{
	int a,b;
	int les;//短边长度 
}c[1200];
bool cmp(chocolate a,chocolate b){
	return a.les>b.les;
}
void fun(){
	sort(c,c+n,cmp);	
	int i=0;//从第i块开始有效 
	while(m!=0&&i<n){
		for(int j=0;j<n;j++) cout<<c[j].les<<" ";cout<<endl;
		most+=c[i].les*c[i].les;
		m--;
		if(c[i].a>c[i].b) c[i].a-=c[i].les;
		else c[i].b-=c[i].les;
		c[i].les=c[i].a<c[i].b?c[i].a:c[i].b;
		//更新这块巧克力的数据 
		if(c[i].les==0) 
		{
			i++;
			sort(c+i,c+n,cmp);
		}
	
		//这块巧克力吃完了 
		else{
			sort(c+i,c+n,cmp);	
			}  
		}//将这块巧克力重新排序 
	}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i].a>>c[i].b;
		c[i].les=c[i].a<c[i].b?c[i].a:c[i].b;
	}
	fun();
	cout<<most<<endl;
	return 0;
}
