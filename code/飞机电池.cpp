#include<iostream>
//此题的关键在于  先将所有电池大小升序排序
//分成两种情况，一种是前n-1个电池的容量之和大于最后一个电池，
//此时可以将最后一个电池用完（max（最后一个）+max（前面电池分出来的）） 在加上（sum-max-max）/2
//第二种情况是小于等于，此时无法将最后一个电池用尽，即前面所有电池寿命和便是总寿命 

using namespace std;
int a[3000];
int n;
int sum;
int main(){
	int i,j,k;
	while(scanf("%d",&n)!=EOF){
		sum=0;
		int max=-1;
		for(i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
			if(max<a[i])max=a[i];
		}
		if(sum-max<max){
			printf("%.1f\n",(sum-max)*1.0);
		}
		else printf("%.1f\n",max+(sum-max-max)*1.0/2);
		
	}
	return 0;
}
