//��������ͨ��ͼ�ķ������������
//������Ե�֪ÿ��ҩ��ֻ����Ϊ�ȶ���һ�Σ���������ߵ��յ�ֻ������һ��
//���ǾͲ��ÿ��Ƿֲ��ϵ���ͨ��ͼ
#include<iostream>
#include<cstring>
using namespace std;
int g[1000001];//��¼ҩ�ĵ��ȶ���
bool xuan[1000001];//��¼��ҩ���Ƿ���Ϊ�ȶ����� 
int n;
int count=0;
void dfs(int x){
	int i=x;
	while(xuan[i]==false){
		xuan[i]=true;
		i=g[i];
	}
	if(x==i)count=(count+1)%998244353;
}
int main(){
	cin>>n;
	int i,j,k;
	unsigned long long sum=1;
	memset(xuan,0,sizeof(xuan));
	for(i=1;i<=n;i++){
		cin>>g[i];
	}
	for(i=1;i<=n;i++){
		if(xuan[i])continue;
		dfs(i);
	}
	for(i=1;i<=count;i++){
		sum=(sum*2)%998244353;//��һ���Ƚϲ������뵽��������n��Ԫ�أ������Ӽ������һ���Ԫ�ظ�����2^n-1 
	}
	cout<<sum-1<<endl;
	return 0;
} 
