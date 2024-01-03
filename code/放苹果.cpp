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
	if(n>m)return f(m,m);//如果盘子比苹果多，则就相当于m个盘子放m个苹果的情况 
	else return f(m,n-1)+f(m-n,n);//否则便是两种子情况之和，即有一个盘子不放苹果和没有盘子不放苹果两种子情况。 
}

