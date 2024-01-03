#include<iostream>
using namespace std;
long long num[2000];
int main(){
	int n;
	int i,j,k;
	int huan;
	long long mult;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
				cin>>num[i];
			}
			while(n!=1){
			
			for(i=0;i<n;i++){
				for(j=0;j<n-i-1;j++){
					if(num[j]>num[j+1]){
						huan=num[j];
						num[j]=num[j+1];
						num[j+1]=huan;
					}
				}
			}
			mult=num[0]*num[1]+1;
			num[0]=mult;
			for(i=1;i<n-1;i++){
				num[i]=num[i+1];
			}
			n--;
		}
		cout<<num[0]<<endl;
	}
	return 0;
}
