#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 1000
int N;
int T;

//���ֱ����������̰���㷨
//ֻҪ��ÿ����Ʒ�ĵ�λ��ֵ��������մӴ�С���� 
struct Node{
	double w;
	double v;
	double p;
	bool operator <(const Node &s){
		return p>s.p;
	}//����ʹ������������ڣ�����sort��������Ϊ��ֻ��<�������������ͨ�����ش��ڵ���ֵ��ʹ�併������ 
};
Node A[2000];
double V=0;

void Knap(){
	V=0;
	double weight = T;
	int i=0;
	while(A[i].w<weight){
		weight-=A[i].w;
		V+=A[i].v;
		i++;
	}//����ֱ����һ����Ʒ�޷��������� 
	if(weight>0){
		V+=weight/A[i].w*A[i].v;
	}//�������һ����Ʒ�Ĳ��� 
}

int main(){
	cin>>N>>T;
	int i,j,k;
	for(i=0;i<N;i++){
		cin>>A[i].w>>A[i].v;
		A[i].p=A[i].v/A[i].w;
	}
	sort(A,A+N);
	Knap();
	printf("%.2lf",V);
	cout<<endl;
	return 0;
}
