#include<iostream>
using namespace std;
int main(){
	int a[10];
	memset(a,1,sizeof(a));
	cout<<a[0];
	return 0;
}