//���ݷ���ÿ���㶼��jie[]������ÿ��ҩ�ĵ��ȶ�����int�ͣ�
//f[]�������Ƿ��Ŵ�ҩ��
//ʹ���Ӽ�������������
#include<iostream>
using namespace std;
int jie[1000001];
bool f[1000001];
int n;
long long count=0;
bool pan0(){
	for(int i=1;i<=n;i++){
		if(f[i]==1){
			return 0;
		}
	}
	return 1;
}
bool pan(int nn){
	if(nn==n&&pan0())return 0;
	else 
	if (nn==n)for(int i=1;i<=nn;i++){//����ʱ�ж� 
		if(f[i]){//��ҩ�ı�ѡ�� 
			if(!f[jie[i]])return 0;//��ҩ�ĵ��ȶ������� 
		}
	}
	else {
		for(int i=1;i<=nn;i++){//��֦��������ǰnn��Ԫ���ѱ�ȷ��ʱ�����ĳ��ҩ�ĵ��ȶ�����ǰn������δ���֣����֦ 
			if(f[i]){//��ҩ�ı�ѡ�� 
				if(jie[i]<=nn&&!f[jie[i]])return 0;//��ҩ�ĵ��ȶ������� 
			}
		}
	}
	return 1;//����ҩ�ĵ��ȶ������� 
}
void solve(int next,bool choose){
	if(next==0){
		solve(next+1,1);
		solve(next+1,0);
	}
	else if(next==n+1){
		//cout<<"haha�������"<<endl;
		if(pan(n)){
			count=count+1;
//			for(int i=1;i<=n;i++){
//				cout<<"f["<<i<<"]="<<f[i]<<endl;
//			}
		}
	}
	else {
		f[next]=choose;
		if(pan(next)){
			solve(next+1,1);
			solve(next+1,0);
		}
	}
}
int main(){
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>jie[i];
	}
	solve(0,0);
//	f[1]=1;f[2]=1;f[3]=1;f[4]=1;f[5]=1;f[6]=1;
//	cout<<"pan="<<pan()<<endl;	
	cout<<(count/2)%998244353<<endl;
} 
