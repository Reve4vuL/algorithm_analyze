#include<iostream>
using namespace std;
int n;
int a[600000];
int main(){
	int sum=0;
	int i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j])sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
} 
