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
		//��ע�⣬������line��work���Ǵ�1��ʼ���� 
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
}//�˺�����������ÿ������Ҫ����Ƕ����ж����� 
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
//���ǲ�����������������Ԫ��3��������Ϊ
//work(2,1+3,1+3);->�м� 
//work(2,1,1);    ->���Ͻ� 
//work(2,1+6,1);  ->���½�
//work(2,1+6,1+6);->���½�
//work(2,1,1+6);  ->���Ͻ�
//��ֹ������ÿ��nΪ1ʱ���������
//�ܵ��͵ķ��η�˼· 
