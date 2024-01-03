#include <stdio.h>
char a[10000][10000];
int f(int n);
void work(int n,int line,int row);
int main(){
	int n;
	int i,j,k;
	while((scanf("%d",&n))!=EOF){
		for(i=1;i<=f(n-1);i++){
			for(j=1;j<=f(n-1);j++){
				a[i][j]=' ';
			}
		}
		work(n,1,1);
		for(i=1;i<=f(n-1);i++){
			for(j=1;j<=f(n-1);j++){
				printf("%c",a[i][j]);
			}
			
			printf("\n");
		}
		//请注意，本题中line和work都是从1开始计数 
		printf("-\n");
	}
	
	return 0;
}
int f(int n){
	int i;
	int sum=1;
	for(i=1;i<=n;i++){
		sum*=3;
	}
	return sum;
}//此函数声明对于每次输入要输出是多少行多少列 
void work(int n,int line,int row){
	if(n==1){a[line][row]='*';return;}
	else {
		work(n-1,line+f(n-2),row+f(n-2));
		work(n-1,line,row);
		work(n-1,line+2*f(n-2),row);
		work(n-1,line+2*f(n-2),row+2*f(n-2));
		work(n-1,line,row+2*f(n-2));
	} 
}
//我们不妨举例，对于输入元素3，子问题为
//work(2,1+3,1+3);->中间 
//work(2,1,1);    ->左上角 
//work(2,1+6,1);  ->左下角
//work(2,1+6,1+6);->右下角
//work(2,1,1+6);  ->右上角
//终止条件是每次n为1时即输出符号
//很典型的分治法思路 
