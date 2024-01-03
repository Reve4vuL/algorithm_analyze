//上一个子集树算法的复杂度时2^n，此次争取优化到n^2
//想法：从第一个药方遍历到最后一个，每次遍历时，选取药方，再选取其稳定剂，再选取稳定剂的稳定剂，直至有回边 
//数组还是类似，jie[]数组存放每种药材的稳定剂，f[]数组存放是否存放此药材
#include<iostream>
using namespace std;
int jie[1000001];
bool f[1000001];
int n;
int count=0;
void solve(){
	int i,j,k;
	for(i=1;i<=n;i++){
		
	}
}

int main(){
	return 0;
} 
