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
	int pos=inorder.find(preorder[0]);//查找根节点在中序序列中的位置
	postorder(preorder.substr(1,pos),inorder.substr(0,pos));//后续遍历左子树 1表示起始位置，pos表示长度 
	postorder(preorder.substr(pos+1,len-pos-1),inorder.substr(pos+1,len-pos-1));//后序遍历右子树
	cout<<preorder[0]; 
}
