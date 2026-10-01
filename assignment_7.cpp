#include <iostream>
using namespace std;
#define INF 9999

struct Edge
{
 int source;
 int destination;
 int weight;
};

int findParent(int parent[], int vertex)
{
 while (parent[vertex] != vertex)
 {
 vertex = parent[vertex];
 }
 return vertex;
}

void unionSet(int parent[], int a, int b)
{
 int parentA = findParent(parent, a);
 int parentB = findParent(parent, b);
 parent[parentB] = parentA;
}

void prim(int graph[5][5], int n)
{
 int selected[5] = {0};
 int edges = 0;
 int totalCost = 0;
selected[0] = 1;

cout << "\nMinimum Spanning Tree using Prim's Algorithm\n";

while (edges < n - 1)
{
int min = INF;
int x = 0;
int y = 0;


for (int i = 0; i < n; i++)
{
if (selected[i] == 1)
{
for (int j = 0; j < n; j++)
{
if (selected[j] == 0 && graph[i][j] != 0)
{
if (graph[i][j] < min)
{
min = graph[i][j];
x = i;
y = j;
}

}
}
}
}

cout << "Edge: " << x << " - " << y;
cout << " Cost: " << min << endl;

totalCost = totalCost + min;

selected[y] = 1;

edges++;
}

cout << "Total Cost = " << totalCost << endl;
}

void kruskal(Edge edges[], int n, int m)
{
for (int i = 0; i < m - 1; i++)
{
for (int j = 0; j < m - i - 1; j++)
{

if (edges[j].weight > edges[j + 1].weight)
{
Edge temp = edges[j];

edges[j] = edges[j + 1];

edges[j + 1] = temp;
}
}
}

int parent[5];


for (int i = 0; i < n; i++)
{
parent[i] = i;
}

int selectedEdges = 0;
int totalCost = 0;

cout << "\nMinimum Spanning Tree using Kruskal's Algorithm\n";
cout << "-----------------------------------------------\n";

for (int i = 0; i < m; i++)
{

int source = edges[i].source;
int destination = edges[i].destination;

int parentSource = findParent(parent, source);
int parentDestination = findParent(parent, destination);

if (parentSource != parentDestination)
{
cout << "Edge: " << source << " - " << destination;
cout << " Cost: " << edges[i].weight << endl;

totalCost = totalCost + edges[i].weight;

unionSet(parent, source, destination);

selectedEdges++;

if (selectedEdges == n - 1)
{
break;
}
}
}

cout << "Total Cost = " << totalCost << endl;

}



int main()
{
int n = 5;


int graph[5][5] =
{
{0, 2, 3, 0, 0},
{2, 0, 1, 4, 0},
{3, 1, 0, 2, 5},
{0, 4, 2, 0, 3},
{0, 0, 5, 3, 0}
};

Edge edges[7] =
{
{0, 1, 2},
{0, 2, 3},
{1, 2, 1},
{1, 3, 4},
{2, 3, 2},
{2, 4, 5},
{3, 4, 3}
};
int m = 7;
int choice;
cout << " COLLEGE CAMPUS MST PROGRAM\n";
cout << "====================================\n";

cout << "\nVertices:\n";
cout << "0 = Main Gate\n";
cout << "1 = Admin Block\n";
cout << "2 = Library\n";
cout << "3 = Canteen\n";
cout << "4 = Computer Lab\n";

cout << "\n1. Prim's Algorithm";
cout << "\n2. Kruskal's Algorithm";

cout << "\n3. Both Algorithms";

cout << "\n\nEnter your choice: ";
cin >> choice;

if (choice == 1)
{
prim(graph, n);
}
else if (choice == 2)
{
kruskal(edges, n, m);
}
else if (choice == 3)
{
prim(graph, n);

kruskal(edges, n, m);
}
else
{
cout << "\nInvalid Choice!";
}

return 0;
}
