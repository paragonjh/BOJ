#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> arr[2001];
bool visit[2001];
int N,M;
//ref: https://kyc0517.tistory.com/33
bool dfs(int node, int level)
{
	if(level == 5)
		return true;

	visit[node] = true;
	
	for(int i = 0; i < arr[node].size(); i++)
	{
		int nextNode = arr[node][i];
		if(visit[nextNode] == false)
		{
			if(dfs(nextNode, level+1) == true)
				return true;
		}
	}
	visit[node] = false;
	return false;
}
int main() {
	// your code goes here
	cin >> N >> M;
	int a,b;
	for(int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	
	for(int i = 0; i < N; i++)
	{
		memset(visit, false, sizeof(visit));
		if(dfs(i,1) == true)
		{
			cout << 1;
			return 0 ;
		}
	}
	cout << 0;
	return 0;
}
