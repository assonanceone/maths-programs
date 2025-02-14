#include <bits/stdc++.h>
using namespace std;

// To store counts of nodes with two colors
long long count_color[2];

void dfs(vector<int> adj[], int node, int parent, int color)
{
	// Increment count of nodes with current
	// color
	count_color[color]++;

	// Traversing adjacent nodes
	for (int i = 0; i < adj[node].size(); i++) {

		// Not recurring for the parent node
		if (adj[node][i] != parent)
			dfs(adj, adj[node][i], node, !color);
	}
}

// Finds maximum number of edges that can be added
// without violating Bipartite property.
int findMaxEdges(vector<int> adj[], int n)
{
	// Do a DFS to count number of nodes
	// of each color
	dfs(adj, 1, 0, 0);

	return count_color[0] * count_color[1] - (n - 1);
}

// Driver code
int main()
{
	int n = 5;
	vector<int> adj[n + 1];
	adj[1].push_back(2);
	adj[1].push_back(3);
	adj[2].push_back(4);
	adj[3].push_back(5);
	cout << findMaxEdges(adj, n);
	return 0;
}
