#include <iostream>
using namespace std;
#define INF 9999
// Structure for Kruskal's Algorithm
struct Edge
{
 int source;
 int destination;
 int weight;
};
// Find parent for Kruskal
int findParent(int parent[], int vertex)
{
 while (parent[vertex] != vertex)
 {
 vertex = parent[vertex];
 }
 return vertex;
}
// Union for Kruskal
void unionSet(int parent[], int a, int b)
{
 int parentA = findParent(parent, a);
 int parentB = findParent(parent, b);
 parent[parentB] = parentA;
}
// ---------------- PRIM'S ALGORITHM ----------------
void prim(int graph[5][5], int n)
{
 int selected[5] = {0};
 int edges = 0;
 int totalCost = 0;
 // Start from vertex 0
selected[0] = 1;

cout << "\nMinimum Spanning Tree using Prim's Algorithm\n";
cout << "---------------------------------------------\n";

while (edges < n - 1)
{
int min = INF;
int x = 0;
int y = 0;

// Find minimum edge
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

cout << "---------------------------------------------\n";
cout << "Total Cost = " << totalCost << endl;
}

// ---------------- KRUSKAL'S ALGORITHM ----------------

void kruskal(Edge edges[], int n, int m)
{
// Sort edges according to weight
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

// Initially every vertex is its own parent
for (int i = 0; i < n; i++)
{
parent[i] = i;
}

int selectedEdges = 0;
int totalCost = 0;

cout << "\nMinimum Spanning Tree using Kruskal's Algorithm\n";
cout << "-----------------------------------------------\n";

// Select edges
for (int i = 0; i < m; i++)
{

int source = edges[i].source;
int destination = edges[i].destination;

int parentSource = findParent(parent, source);
int parentDestination = findParent(parent, destination);

// Check whether edge creates cycle
if (parentSource != parentDestination)
{
cout << "Edge: " << source << " - " << destination;
cout << " Cost: " << edges[i].weight << endl;

totalCost = totalCost + edges[i].weight;

unionSet(parent, source, destination);

selectedEdges++;

// MST contains n-1 edges
if (selectedEdges == n - 1)
{
break;
}
}
}

cout << "-----------------------------------------------\n";
cout << "Total Cost = " << totalCost << endl;

}

// ---------------- MAIN FUNCTION ----------------

int main()
{
int n = 5;

/*
Campus Vertices:

0 = Main Gate
1 = Admin Block
2 = Library
3 = Canteen
4 = Computer Lab
*/

int graph[5][5] =
{
{0, 2, 3, 0, 0},
{2, 0, 1, 4, 0},
{3, 1, 0, 2, 5},
{0, 4, 2, 0, 3},
{0, 0, 5, 3, 0}
};

// Edges for Kruskal

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

cout << "====================================\n";
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
