#include <iostream>
using namespace std;
int N = 0;
int map[17][17] = {0, };
// 오른쪽(이동가능:0,2), 아래(이동가능:1,2), 대각선(이동가능:0,1,2)
int dx[] = {1,0,1};
int dy[] = {0,1,1};
int maxCnt = 0;

void DFS(int x, int y, int pipe) {
	// 종료 조건
	if(x == N-1 && y == N-1) {
		maxCnt++;
	}
	
	for(int i = 0; i < 3; i++) {
		// 파이프 예외처리
		if((i == 0 && pipe == 1) || (i==1 && pipe == 0)) {
			continue;
		}
		// 범위 예외처리
		int nextX = x + dx[i];
		int nextY = y + dy[i];
		if(nextX < 0 || nextX > N-1 || nextY < 0 || nextY > N-1 || map[nextY][nextX] == 1)
			continue;
		
		if(i == 2) {
			if(map[y][x+1] == 1 || map[y+1][x] == 1 || map[y+1][x+1] == 1)
				continue;
		}
		DFS(nextX,nextY,i);
	}

}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	DFS(1,0,0);
	cout << maxCnt;
	return 0;
}
