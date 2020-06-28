#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> arr[1001];
bool visit[1001];
queue<int> q;
void BFS(int node)
{
	visit[node] = true;
	q.push(node);
	while(!q.empty())
	{
		int cur = q.front(); q.pop();
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
	cin >> N >> M;
	int a,b = 0;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	int num = 0;
	for(int i = 1; i <= N; i++)
	{
		if(visit[i] == false)
		{
			num++;
			//cout << i << endl;
			BFS(i);
		}
	}

	cout<< num;
	return 0;
}
