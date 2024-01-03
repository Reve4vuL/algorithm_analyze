#include<iostream>
#include<cmath>
using namespace std;
bool su(int n);
void solve(int x){
	int i;
	int a=x;
	for(i=2;i<sqrt(a*1.0);i++){
		if(su(i))
		{
			while(x%i==0){
				x/=i;
				cout<<i<<" ";
			}
		}
	}
	cout<<endl;
}

bool su(int n){
	for(int i=2;i<sqrt(n*1.0);i++){
		if(n%i==0)return 0;
	}
	return 1;
}
int main(){
	int x;
	while(scanf("%d",&x)!=EOF){
		solve(x);
	}
	return 0;
} 
