#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int father[2001];
//�����Ǻܵ��͵�����ķ�㷨
//ע�⼸���㷨������
//����ķ�㷨       ->��һ���㼯��Ϊ��㣬Ѱ����Щ�㼯�����ڵı߼�������С���Ǹ��ߣ��ߵ��յ㲻�����ڵ㼯���У���ֱ�����е㶼�ڵ㼯����
//                 ->���ľ���father[]���飬������¼ 
//��³˹�����㷨   ->ÿ�ζ������б���Ѱ����̱ߵ��ҽ����ߵ�ʼ����յ㲻ȫ�ڵ㼯���У����Ѵ˱ߵ����������㼯��
//���������㷨     ->ѭ������ k,i,j   ij��ʾ����k��ʾ�������� 
struct road{
	int s;
	int e;
	int length;
	bool choose=0;
	bool operator <(const road &c){
		return length<c.length; 
	}
};
road a[10001];
int baba(int x){
	return x==father[x]?x:father[x]=baba(father[x]);
}
int main(){
	cin>>n>>m;
	int i,j,k;
	int x,y,z;
	int count=0;
	int maxx=-1;
	for(i=1;i<=n;i++){
		father[i]=i;
	}
	for(i=1;i<=m;i++){
		cin>>x>>y>>z;
		a[i].e=x;
		a[i].s=y;
		a[i].length=z;//��ߵ�©������û�н������յ��С�����ŷ� 
	}

	sort(a+1,a+m+1);//�����С��������ʱ����Ҫ���ߴ�С����������� 
//	for(i=1;i<=m;i++){
//		cout<<a[i].e<<"<->"<<a[i].s<<"="<<a[i].length<<endl;
//	}
	for(i=1;i<=m;i++){
		x=a[i].s;
		y=a[i].e;
		int u=baba(x); 
		int v=baba(y);//ÿ���ҳ�ԭʼ������ĸ��ڵ㣬��Ϊ�˱��ѱ�ѡȡ���������ĸ��ڵ㲻һ��������ΪС���Ǹ���ĸ��ڵ� 
		if(u!=v){
			//cout<<i<<endl;
			father[v]=u;
			maxx=max(maxx,a[i].length);//ѡ��������ߣ���Ҫ�ж����Ƿ��ǰ��ѡ�е�Ҫ���� 
		}

	}
	cout<<maxx<<endl;
	return 0;
}
