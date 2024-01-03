#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[200000];
int b[200000];
int main(){
	int i,j,k;
	int ans=0;
	cin>>n;
	int lefta=0;int leftb=0;
	int righta=n-1;int rightb=n-1;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		cin>>b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	while(lefta<=righta){
		if(a[righta]>b[rightb]){
			ans+=200;
			righta--;
			rightb--;
		}
		else if(a[righta]<b[rightb]){
			ans-=200;
			lefta++;
			rightb--;
		}
		else {
			if(a[lefta]>b[leftb]){
				ans+=200;
				lefta++;
				leftb++;
			}
			else {
				if(a[lefta]<b[rightb]){
					ans-=200;
				}
				lefta++;
				rightb--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
