#include <stdio.h>

/*
문제 : N * N 크기의 공간에서 파이프를 가로, 세로, 대각선으로 하여 옮길 때, 파이프를 왼쪽 위에서 오른쪽 아래로 옮기는
방법의 가짓수를 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 각 칸의 각 방향마다 가짓수를 세서 합치면 된다.

주요 알고리즘 : DP
*/

long long room[32][32], mem[32][32][3]; //0 : 가로, 1 : 대각선, 2 : 세로

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) scanf("%lld", &room[i][j]);
	}
	mem[0][1][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > 0 && !room[i][j]) {
				mem[i][j][2] += mem[i - 1][j][2];
				mem[i][j][2] += mem[i - 1][j][1];
			}
			if (j > 0 && !room[i][j]) {
				mem[i][j][0] += mem[i][j - 1][0];
				mem[i][j][0] += mem[i][j - 1][1];
			}
			if (i > 0 && j > 0 && !room[i][j] && !room[i][j - 1] && !room[i - 1][j]) {
				mem[i][j][1] += mem[i - 1][j - 1][0];
				mem[i][j][1] += mem[i - 1][j - 1][1];
				mem[i][j][1] += mem[i - 1][j - 1][2];
			}
		}
	}
	printf("%lld", mem[n - 1][n - 1][0] + mem[n - 1][n - 1][1] + mem[n - 1][n - 1][2]);
	return 0;
}
