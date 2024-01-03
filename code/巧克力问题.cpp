//巧克力问题，最短边从大到小排序
//每次都吃最大的那个
#include<iostream>
#include<algorithm>
#define int long long

//此题夸张就夸张在所有的数据都用了longlong才给过
//算法的思路很简单，就是先按照最短边给所有的巧克力排序，每次吃最短边最大的那个，吃完之后减一下，然后再次排序，以此类推
using namespace std; 
int n,m;
struct choc{
	int a;
	int b;
	bool operator <(choc &s){
		return b<s.b;
	}
};
choc rec[1001];
signed main(){
	int i,j,k;
	unsigned long long sum=0;
	cin>>n>>m;
	int x,y;
	for(i=1;i<=n;i++){
		cin>>x>>y;
		rec[i].a=x>y?x:y;
		rec[i].b=x<=y?x:y;
	}
	int zana,zanb;
	sort(rec+1,rec+1+n);
//	for(i=1;i<=n;i++){
//		cout<<"rec["<<i<<"].b="<<rec[i].b<<endl;
//	}
	for(i=1;i<=m;i++){
		if(rec[n].b==0||rec[n].a==0)break;
		sum+=rec[n].b*rec[n].b;
		zana=rec[n].a-rec[n].b;
		zanb=rec[n].b;
		rec[n].a=zana>zanb?zana:zanb;
		rec[n].b=zana<=zanb?zana:zanb;
		sort(rec+1,rec+1+n);
	}
	cout<<sum<<endl;
	return 0;
} 
