#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int n,m;
int most=0;
struct chocolate{
	int a,b;
	int les;//�̱߳��� 
}c[1200];
bool cmp(chocolate a,chocolate b){
	return a.les>b.les;
}
void fun(){
	sort(c,c+n,cmp);	
	int i=0;//�ӵ�i�鿪ʼ��Ч 
	while(m!=0&&i<n){
		for(int j=0;j<n;j++) cout<<c[j].les<<" ";cout<<endl;
		most+=c[i].les*c[i].les;
		m--;
		if(c[i].a>c[i].b) c[i].a-=c[i].les;
		else c[i].b-=c[i].les;
		c[i].les=c[i].a<c[i].b?c[i].a:c[i].b;
		//��������ɿ��������� 
		if(c[i].les==0) 
		{
			i++;
			sort(c+i,c+n,cmp);
		}
	
		//����ɿ��������� 
		else{
			sort(c+i,c+n,cmp);	
			}  
		}//������ɿ����������� 
	}
signed main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i].a>>c[i].b;
		c[i].les=c[i].a<c[i].b?c[i].a:c[i].b;
	}
	fun();
	cout<<most<<endl;
	return 0;
}
