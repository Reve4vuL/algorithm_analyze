//回溯法求，每个点都用jie[]数组存放每种药材的稳定剂（int型）
//f[]数组存放是否存放此药材
//使用子集树来求解此问题
#include<iostream>
using namespace std;
int jie[1000001];
bool f[1000001];
int n;
long long count=0;
bool pan0(){
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			return 0;
		}
	}
	return 1;
}
bool pan(int nn){
	if(nn==n&&pan0())return 0;
	else 
	if (nn==n)for(int i=1;i<=nn;i++){//结束时判定 
		if(f[i]){//此药材被选入 
			if(!f[jie[i]])return 0;//此药材的稳定剂不在 
		}
	}
	else {
		for(int i=1;i<=nn;i++){//剪枝函数，在前nn个元素已被确定时，如果某个药材的稳定剂在前n个中且未出现，则剪枝 
			if(f[i]){//此药材被选入 
				if(jie[i]<=nn&&!f[jie[i]])return 0;//此药材的稳定剂不在 
			}
		}
	}
	return 1;//所有药材的稳定剂都在 
}
void solve(int next,bool choose){
	if(next==0){
		solve(next+1,1);
		solve(next+1,0);
	}
	else if(next==n+1){
		//cout<<"haha你真棒！"<<endl;
		if(pan(n)){
			count=count+1;
//			for(int i=1;i<=n;i++){
//				cout<<"f["<<i<<"]="<<f[i]<<endl;
//			}
		}
	}
	else {
		f[next]=choose;
		if(pan(next)){
			solve(next+1,1);
			solve(next+1,0);
		}
	}
}
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>jie[i];
	}
	solve(0,0);
//	f[1]=1;f[2]=1;f[3]=1;f[4]=1;f[5]=1;f[6]=1;
//	cout<<"pan="<<pan()<<endl;	
	cout<<(count/2)%998244353<<endl;
} 
