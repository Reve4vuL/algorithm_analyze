#include<iostream>
#include<malloc.h>
using namespace std;
void mergepass(int a[],int length,int n);
void mergesort(int a[],int n);
void merge(int a[],int low,int mid,int high);
int a[600000];
struct group{
	int a[10];
	int ans = 0;
	int count();
};
int group::count(){
	int i;
	int c=0;
	for(i=0;a[i]!=-1;i++){
		cout<<a[i];
		c++;
	}
	return c;
}
long long ans = 0;		 		//ȫ�ֱ���,�ۼ�������
int main(){
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	mergesort(a,n);
	cout<<ans<<endl;
	return 0;
}


void merge(int a[],int low,int mid,int high) //������������ι鲢
{  int i=low;
   int j=mid+1;
   int k=0;
   int *tmp=(int *)malloc((high-low+1)*sizeof(int));
   while(i<=mid && j<=high) 		//��·�鲢
   {  if(a[i]>a[j])
      {  tmp[k++]=a[j++];
         ans+=mid-i+1;
      }
      else tmp[k++]=a[i++];
   }
   while(i<=mid) tmp[k++]=a[i++];
   while(j<=high) tmp[k++]=a[j++];
   for(int k1=0;k1<k;k1++)		//tmp[0..k-1]=>a[low..high]
       a[low+k1]=tmp[k1];
   free(tmp);
}

void mergepass(int a[],int length,int n){
	int i;
	for(i=0;i+2*length-1<n;i+=2*length)
	merge(a,i,i+length-1,i+2*length-1);
	if(i+length-1<n){//���������ӱ����߳���С��length 
		merge(a,i,i+length-1,n-1);
	}
} 
void mergesort(int a[],int n){
	int length;
	for(length=1;length<n;length=2*length)
	mergepass(a,length,n);
}
