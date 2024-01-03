#include<iostream>
#include<string>
#include<sstream>
using namespace std;
long long a[200];
string A[200];
int main(){
	int n;
	int i,j,k;
	int count;
	string jieguo;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			cin>>a[i];
		}
		for(i=0;i<n;i++){
			stringstream ss;
			ss << a[i];
			ss >> A[i];
		}
		string huan;
		int huan1;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				if(A[i]+A[j]<A[j]+A[i]){
					huan=A[i];
					A[i]=A[j];
					A[j]=huan;
				}
			}
		}
		for(i=0;i<n;i++){
			jieguo+=A[i];
		}
		for(i=0;i<200;i++){
			if(jieguo[i])cout<<jieguo[i]-'0';
			else break;
		}
		jieguo="\0";
		cout<<endl;
	}
	return 0;
} 
