#include<iostream>
//����Ĺؼ�����  �Ƚ����е�ش�С��������
//�ֳ����������һ����ǰn-1����ص�����֮�ʹ������һ����أ�
//��ʱ���Խ����һ��������꣨max�����һ����+max��ǰ���طֳ����ģ��� �ڼ��ϣ�sum-max-max��/2
//�ڶ��������С�ڵ��ڣ���ʱ�޷������һ������þ�����ǰ�����е�������ͱ��������� 

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
