#include<iostream>
#include<cmath>
using namespace std;
int a[2000],b[2000],c[2000],d[2000];//������¼ÿһ�еķ��� 
int result[10000];//������¼ǰ���к������ڵ��������� 
int result2[10000];//������¼ǰ���к���С��������
//�����ź��������±�Ϊ���Ļ��Ϳ��Խ�ʡ�ܶ������ 

//������Ҫͻ�����ڽ��������ݷ�Ϊ���飬��ͨ�������±��ʾ������¼�͵Ĵ�����
//ʱ�临�Ӷ����  before:O(2000^4)  later:O(2000^2)  ���Կ������������� 
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
		}//��¼ǰ�������з����͵Ŀ����ԣ� 
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
		}//������¼�����к��������������͡� 
		cout<<count<<endl;
		count=0;
		for(j=0;j<10000;j++){
			result[j]=0;
			result2[j]=0;
		}//��ʼ�����Ա���һ��������롣 
	}
	
}
