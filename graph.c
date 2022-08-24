#include <stdio.h>
#define n 7
int graph[n][n];
int visit[n],q[100],r=-1,f=0;

void init(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			arr[i][j]=0;
	}
}

void addEdge(int arr[][n],int s,int d)
{
	arr[s][d]=1;
	arr[d][s]=1;
}

void prtGraph(int arr[][n])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}

void dfs(int i)
{
	int j;
	printf("%d ",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visit[j] && graph[i][j]==1)
			dfs(j);
	}
}

void bfs(int i)
{
	
	int j;
	if(!visit[i])
		printf("%d ",i);
	visit[i]=1;
	for(j=0;j<n;j++)
	{
		if(!visit[j] && graph[i][j]==1)
			q[++r]=j;
	}
	if(f<=r)
	{
		bfs(q[f++]);
		
	}
}
void main()
{
	
	init(graph);
	for(int i=0;i<n;i++)
		visit[i]=0;
	
	addEdge(graph,0,1);
	addEdge(graph,0,3);
	addEdge(graph,1,2);
	addEdge(graph,0,4);
	addEdge(graph,4,1);
	addEdge(graph,4,3);
	addEdge(graph,5,4);
	addEdge(graph,5,6);
	addEdge(graph,2,6);
	addEdge(graph,2,4);
	addEdge(graph,5,2);	
	prtGraph(graph);
	printf("\nBFS:");
	bfs(0);
	printf("\nDFS:");
	for(int i=0;i<n;i++)
		visit[i]=0;
	dfs(0);
}

