#include<iostream>
#include<cmath>
using namespace std;
int a[2000],b[2000],c[2000],d[2000];//用来记录每一列的分量 
int result[10000];//用来记录前两列合数大于等于零的情况 
int result2[10000];//用来记录前两列合数小于零的情况
//本题遗憾：数组下标为负的话就可以节省很多代码行 

//本题主要突破在于将四组数据分为两组，并通过数组下标表示和来记录和的次数。
//时间复杂度情况  before:O(2000^4)  later:O(2000^2)  可以看到有显著减少 
int main(){
	int T,n;
	cin>>T;
	int i,j,k;
	int sum;
	int count=0;
	for(i=0;i<T;i++){
		cin>>n;
		for(j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j]>>d[j];
		}
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				sum=a[j]+b[k];
				if(sum>=0)result[a[j]+b[k]]++;
				else result2[abs(a[j]+b[k])]++;
			}
		}//记录前两行所有分量和的可能性； 
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				sum=c[j]+d[k];
				if(sum>0){
					if(result2[sum]>0)count+=result2[sum];
				}
				else {
					if(result[-sum]>0)count+=result[-sum];
				}
			}
		}//用来记录后两列和数的情况，并求和。 
		cout<<count<<endl;
		count=0;
		for(j=0;j<10000;j++){
			result[j]=0;
			result2[j]=0;
		}//初始化，以备下一组多组输入。 
	}
	
}
