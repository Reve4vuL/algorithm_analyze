#include<iostream>
#include<cmath>
using namespace std;
int q[10];//��ʾ��i�лʺ��λ�ã���modifyable�������ʹ�ñ�ʾ�����ĳ�ʼֵ�� 
bool modifyable[10];//��ʾ���е�1������ģ�0��ʾ�����޸� 
int a[8][8];//������¼�ʼ�����벢ת��Ϊq�����modifyable���� 

//�����¼�е�С���⣬��a�����е�i���Ǵ�0��ʼ��������q��modifyable�����Ǵ�1��ʼ����������Ҫע��ת�� 
bool place(int i){
	int j;
	for(j=1;j<=8;j++){
		if(j<i){
			if(q[i]==q[j]||abs(q[j]-q[i])==abs(j-i))return 0;
		}
		if(j>i){
			if(modifyable[j]==0){
				if(q[i]==q[j]||abs(q[j]-q[i])==abs(j-i))return 0;
			}
		}//��߷�����������Ҫ����Ϊ�����ϵ������˻ʺ�ڷ������Ǵӵ�һ�п�ʼ����ڣ������ڱ���֮����һ��û�лʺ�ڷŵ�
		//�������Ǹ�����ʼ�ʺ�������ȥѡ��ͨ��������������ڴ���֮��Ԥ��õ��У�Ԥ�Ȱڷźûʺ���У�ҲҪ���ǽ�ȥ�� 
	}
	return 1;
}
void dis(int n){
	cout<<"%%"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<q[i]<<" ";
		
	}
	cout<<endl;
}//չʾ�ʺ�ڷ�����ĺ��� 

int main(){
	int i,j,k;
	int a1;
	int count;
	int begin;
	int end;
	while(scanf("%d",&a1)!=EOF){
		a[0][0]=a1;
		count=0;
		for(i=1;i<=8;i++){
			q[i]=0;
		}
		for(i=0;i<8;i++){
			if(i!=0)for(j=0;j<8;j++){
				cin>>a[i][j];
			}
			else for(j=1;j<8;j++){
				cin>>a[i][j];
			}
			modifyable[i+1]=1;//��ʼ�������о������޸� 
		}//��������
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(a[i][j]==1){
					q[i+1]=j+1;
					modifyable[i+1]=0;
					break;
				}
			}
		}//�洢q[]���飬����ָ���Ǽ��в������޸� 
		for(i=1;i<=8;i++){
			if(modifyable[i]){
				begin=i;
				break;
			}
		}//������ʼ�� 
		for(i=1;i<=8;i++){
			if(modifyable[9-i]){
				end=9-i;
				break;
			}
		}//���������� 
		//cout<<"begin="<<begin<<" end="<<end<<endl;
		i=begin;
		q[i]=0;
		while(i>=begin){
			q[i]++;
			while(q[i]<=8&&!place(i)){
				q[i]++;
			}
			if(q[i]<=8){
				if(i==end){
					count++;
					//dis(8);
				}//����ȫ���ڷųɹ�����������һ 
				else{
					i++;
					while(modifyable[i]==0)i++;
					q[i]=0;
				}//���������һ�аڷųɹ���������һ�� 
			}
			else {
				i--;
				while(modifyable[i]==0)i--;
			}//������i�в��ɰڷ� 
		}
		cout<<count<<endl;
			
	
		//cout<<"nb!"<<endl;
	}
	return 0;
}
