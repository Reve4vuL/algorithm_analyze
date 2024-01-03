#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int q[8];
int cts=0;
void dispasolution(int n)
{
	cout<<cts<<endl;
	cts++;
}
bool place(int i)
{
	int j=1;
	if(i==1)
	{
		return true;
	}
	while(j<i)
	{
		if((q[j]==q[i])||(abs(q[j]-q[i])==abs(j-i)))
		{
			return false;
		}
		j++;
	}
	return true;
}
void Queens(int n)
{
	int i=1;
	q[i]=0;
	while(i>=1)
	{
		q[i]++;
		while(q[i]<=n&&!place(i))
		{
			q[i]++;
		}
		if(q[i]<=n)
		{
			if(i==n)
			{
				dispasolution(n);
			}
			else
			{
				i++;
				q[i]=0;
			}
		}
		else i--;
	}
}
int main()
{
	/*int i,j;
	int loc[8][8]={0};
	for(i=0;i<8;i++)
	{
		for(j=0;j<8;j++)
		{
			cin>>loc[i][j];
		}
	}*/
	Queens(8);
}

