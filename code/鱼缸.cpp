//
#include<iostream>
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int minsize,maxsize;
int n;
int count=0;
int fishsize[10001];
bool fishput[INF];//1表示不能放，0表示可以放 

signed main(){
	cin>>minsize>>maxsize;
	cin>>n;
	int i,j,k;
	for(i=1;i<=n;i++){
		cin>>fishsize[i];
		for(j=fishsize[i]/10;j<=fishsize[i]/2;j++){
			fishput[j]=1;
		}
		for(j=fishsize[i]*2;j<=fishsize[i]*10;j++){
			fishput[j]=1;
		} 
	}
	for(i=minsize;i<=maxsize;i++){
		if(!fishput[i])count++;
	}
	cout<<count<<endl;
	return 0;
}
