#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

int findMinVertex(const vector<int> &distance,const vector<bool>&visited)
{
	int minVertex =-1;
	for (int i = 0;i<static_cast<int>(distance.size());i++)
	{
		if (!visited[i] && (minVertex ==-1 || distance[i]<distance[minVertex]))
		{
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(const vector<vector<int>>&graph,int source)
{
	int n = graph.size(); 
	
	vector<int>distance(n,INF);
	vector<bool>visited(n,false);
	
	distance[source] = 0;
	
	for (int count = 0 ; count <n-1;count++)
	{
		int u = findMinVertex(distance,visited);
		if (u == -1 || distance[u] == INF)
		break;
		
		visited[u]=true;
		
		for (int v = 0 ;v<n;v++)
		{
			if (!visited[v]&&graph[u][v] != 0 && distance[u] !=INF && distance[u]+ graph[u][v]<distance[v])
			{
				distance[v]= distance [u] +  graph[u][v];
			}
		}
	}
	
	cout<<"\nShortest distance from source vertex :" <<source<<"\n";
	for (int i =0 ;i<n; i++)
	{
		if (distance[i]==INF)
		{
			cout << "Vertex " << i << " : unreachable\n";
		}
		else
		{
			cout << "Vertex " << i << " : " << distance[i] << "\n";
		}
	}
}

int main()
{
	int n;
	
	cout << "Enter number of vertices";
	cin >> n;
	
	vector <vector<int>> graph(n,vector<int>(n));
	
	cout <<"\nEnter the weighted adjacency matrix :\n";
	for(int i = 0 ;i<n;i++)
	{
		for(int j = 0 ;j<n;j++)
		{
			cin >> graph[i][j];
		}
	}
	int source;
	
	cout << "\nEnter source vertex : ";
	cin>>source;
	
	dijkstra(graph,source);
	return 0;
}