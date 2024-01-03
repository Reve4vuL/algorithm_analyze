#include<iostream>
#include<string>
using namespace std;
void postorder(string preorder,string inorder);
int main(){
	string c1,c2;
	while(cin>>c2>>c1){
		postorder(c1,c2); 
		cout<<endl;
	}
	return 0;
}
void postorder(string preorder,string inorder){
	int len = preorder.length();
	if(len==0)return;
	if(len==1){
		cout<<preorder[0];
		return;
	}
	int pos=inorder.find(preorder[0]);//���Ҹ��ڵ������������е�λ��
	postorder(preorder.substr(1,pos),inorder.substr(0,pos));//�������������� 1��ʾ��ʼλ�ã�pos��ʾ���� 
	postorder(preorder.substr(pos+1,len-pos-1),inorder.substr(pos+1,len-pos-1));//�������������
	cout<<preorder[0]; 
}
