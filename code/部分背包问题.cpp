#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAXN 1000
int N;
int T;

//部分背包问题采用贪心算法
//只要将每个物品的单位价值算出并按照从大到小排序 
struct Node{
	double w;
	double v;
	double p;
	bool operator <(const Node &s){
		return p>s.p;
	}//这里使用了巧妙方法在于，对于sort函数，因为它只认<，所以这里可以通过返回大于的真值来使其降序排序 
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
	}//放入直至下一个物品无法完整放下 
	if(weight>0){
		V+=weight/A[i].w*A[i].v;
	}//放入最后一个物品的部分 
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
