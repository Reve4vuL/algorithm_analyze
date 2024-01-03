#include<iostream>
#include<algorithm>
using namespace std;
#define max(x,y)((x)>(y)?(x):(y))
#define N 2000
int n;
int A[2000];
int B[2000];
struct Nodetype{
	int no;
	bool group;
	int time;
	bool operator <(const Nodetype &s)const{
		return time<s.time;
	}
};
int best[2000];
int solve(){
		int i,j,k;
		Nodetype c[N];
		for(i=0;i<n;i++){
			cin>>A[i];
		}
		for(i=0;i<n;i++){
			cin>>B[i];
		}
		for(i=0;i<n;i++){
			c[i].no=i;
			c[i].group=(A[i]<=B[i]);
			c[i].time=A[i]<=B[i]?A[i]:B[i];
		}
		sort(c,c+n);
		j=0;k=n-1;
		for(i=0;i<n;i++){
			if(c[i].group==1){
				best[j]=c[i].no;
//				cout<<"best["<<j<<"]="<<c[i].no;
				j++;
			}
			else {
				best[k]=c[i].no;
//				cout<<"best["<<k<<"]="<<c[i].no;
				k--;
			}
		}
	//	cout<<endl;
		int f1=0;
		int f2=0;
		for(i=0;i<n;i++){	
			f1+=A[best[i]];
			f2=max(f2,f1)+B[best[i]];
		}
		return f2;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		cout<<(solve())<<endl;
		for(int i=0;i<n;i++){
			best[i]=0;
			A[i]=0;
			B[i]=0;
		}
	}
	return 0;
}
