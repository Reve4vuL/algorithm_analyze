# include<iostream>
# include<cstdio>
# include<cstring>
# include<queue>
# define inf 0x3f3f3f3f
using namespace std;
const int maxn=2505;
struct edge{
	int from;
	int to;
	int dis;
	edge(int u,int v,int w):from(u),to(v),dis(w)
	{
	}
	edge()
	{
	}
};
struct Bellman{
	int n,m,u,v;
	vector<edge> edges;
	vector<int> g[maxn];
	int d[maxn];
	void init()
	{
		for(int i=0;i<n;i++)
		  g[i].clear();
		edges.clear();
	}
	void addedge(int u,int v,int w)
	{
		edges.push_back((edge){u,v,w});
		int m=edges.size();
		g[u].push_back(m-1);
	}
	void read_graph()
	{
		init();
		cin>>n>>m>>u>>v;
		
		for(int i=1;i<=m;i++)
		{
			int from,to,w;
			scanf("%d %d %d",&from,&to,&w);
			from--;
			to--;
			addedge(from,to,w);
			addedge(to,from,w);
			}
		
	}
	bool bellman(int s)
	{
		//memset(cnt,0,sizeof(cnt));
		//memset(inq,0,sizeof(inq));
		for(int i=0;i<n;i++)
		  d[i]=inf;
		d[s]=0;
		for(int i=1;i<n;i++)
		{
			
			for(int k=0;k<n;k++)
			{
			  for(int j=0;j<g[k].size();j++)
			    {
			    	edge e=edges[g[k][j]];
			    	if(d[e.to]>d[e.from]+e.dis)
			    	 d[e.to]=d[e.from]+e.dis;
				}
			
		     }
		}
		for(int k=0;k<n;k++)
			{
			  for(int j=0;j<g[k].size();j++)
			    {
			    	edge e=edges[g[k][j]];
			    	if(d[e.to]>d[e.from]+e.dis)
			    	  return false;
				}
			
		     }
		return true;

	}
};
int main()
{
	int u,v;
	Bellman ss;
	ss.read_graph();
	ss.bellman(ss.u-1);
	cout<<ss.d[ss.v-1]<<endl;
	return 0;
}