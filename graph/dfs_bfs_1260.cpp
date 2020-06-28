#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> arr[1001];
bool visit[1001];
int N , M, V;

void DFS(int node)
{
	visit[node] = true;
	cout << node << " ";
	for(int i = 0; i < arr[node].size(); i++)
	{
		int next = arr[node][i];
		if(visit[next] == false)
		{
			DFS(next);
		}
	}
}

void BFS(int node)
{
	queue<int> q;
	visit[node] = true;
	q.push(node);
	
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << " "; 
		for(int i = 0; i < arr[cur].size(); i++)
		{
			int next = arr[cur][i];
			if(visit[next] == false)
			{
				visit[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	// your code goes here
	cin >> N >> M >> V;
	int a, b = 0;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	for(int i = 0; i < N; i++)
	{
		if(arr[i].size() > 0)
			sort(arr[i].begin(), arr[i].end());
	}
	DFS(V);
	cout << endl;
	memset(visit, false, sizeof(visit));
	BFS(V);
	return 0;
} 
