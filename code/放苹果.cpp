#include <stdio.h>
int f(int m,int n);
int main(){
	int m,n;
	int i,j;
	int sum;
	while (scanf ("%d %d",&m,&n)!=EOF){
		printf("%d\n",f(m,n));
	}
	return 0;
}
int f(int m,int n){
	if(m==0||n==1){
		return 1;
	}
	if(n>m)return f(m,m);//������ӱ�ƻ���࣬����൱��m�����ӷ�m��ƻ������� 
	else return f(m,n-1)+f(m-n,n);//����������������֮�ͣ�����һ�����Ӳ���ƻ����û�����Ӳ���ƻ������������� 
}

