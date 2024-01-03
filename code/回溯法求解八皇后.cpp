#include<iostream>
#include<cmath>
using namespace std;
int q[10];//表示第i行皇后的位置，和modifyable数组搭配使用表示参数的初始值等 
bool modifyable[10];//表示组中的1是输入的，0表示不可修改 
int a[8][8];//用来记录最开始的输入并转换为q数组和modifyable数组 

//这里记录有点小问题，在a数组中第i列是从0开始计数，而q和modifyable数组是从1开始计数，所以要注意转换 
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
		}//这边分两类讨论主要是因为，书上单纯求解八皇后摆放问题是从第一行开始往后摆，所以在本行之后是一定没有皇后摆放的
		//而这里是给定初始皇后让我们去选择通过的情况，所有在此行之后预设好的行（预先摆放好皇后的行）也要考虑进去。 
	}
	return 1;
}
void dis(int n){
	cout<<"%%"<<endl;
	for(int i=1;i<=n;i++){
		cout<<i<<q[i]<<" ";
		
	}
	cout<<endl;
}//展示皇后摆放情况的函数 

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
			modifyable[i+1]=1;//初始置所有行均可以修改 
		}//多组输入
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){
				if(a[i][j]==1){
					q[i+1]=j+1;
					modifyable[i+1]=0;
					break;
				}
			}
		}//存储q[]数组，并且指明那几行不可以修改 
		for(i=1;i<=8;i++){
			if(modifyable[i]){
				begin=i;
				break;
			}
		}//标明开始行 
		for(i=1;i<=8;i++){
			if(modifyable[9-i]){
				end=9-i;
				break;
			}
		}//标明结束行 
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
				}//表明全部摆放成功，计数器加一 
				else{
					i++;
					while(modifyable[i]==0)i++;
					q[i]=0;
				}//表明非最后一行摆放成功，考虑下一行 
			}
			else {
				i--;
				while(modifyable[i]==0)i--;
			}//标明第i行不可摆放 
		}
		cout<<count<<endl;
			
	
		//cout<<"nb!"<<endl;
	}
	return 0;
}
