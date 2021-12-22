#include <stdio.h>
#define INF 1012345678

/*
문제 : N * N(N <= 100) 크기의 격자에 절댓값 10^6 이하의 정수들이 쓰여 있다. 이때, 격자에 테트리스 블록을 놓아서
얻을 수 있는 수의 합 가운데 가장 큰 것을 구한다. 회전은 가능하지만 뒤집기는 불가능하다.

해결 방법 : 우선 각 격자에서 일직선으로 블록을 놓아본다. 그 외의 경우는 모두 2 * 3 크기의 블록에 들어가기 때문에,
2 * 3 크기 블록 가운데 제외되는 경우를 빼는 것이 더 빠르다.

주요 알고리즘 : 구현, 브루트 포스

출처 : Arab 2006 B번
*/

int board[128][128];
char exc[][2] = { {0, 3}, {1, 2}, {2, 3}, {2, 5}, {3, 4} };

int big(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int t, n, s1, s2, best = 0;
	//freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\B. The Game of Tetris [tetris]\\tetris.in", "r", stdin);
	//freopen("E:\\PS\\ICPC\\Africa and Arab\\Arab Collegiate\\2006\\B. The Game of Tetris [tetris]\\tetris_t.out", "w", stdout);
	for (int tt = 1;; tt++) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n + 10; i++) {
			for (int j = 0; j < n + 10; j++) {
				if (i < n && j < n) scanf("%d", &board[i][j]);
				else board[i][j] = -1234567;
			}
		}
		best = -INF;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				best = big(best, board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 3][j]);
				best = big(best, board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i][j + 3]);
				s1 = 0;
				s2 = 0;
				for (int p = 0; p < 6; p++) {
					s1 += board[i + (p >> 1)][j + (p & 1)];
					s2 += board[i + (p & 1)][j + (p >> 1)];
				}

				for (int p = 0; p < 6; p++) {
					for (int q = p + 1; q < 6; q++) {
						t = 0;
						for (int e = 0; e < 5; e++) if (p == exc[e][0] && q == exc[e][1]) t = 1;
						if (t) continue;
						if (!(p == 1 && (q == 3 || q == 4)) && !(p == 2 && q == 4)) {
							best = big(best, s1 - board[i + (p >> 1)][j + (p & 1)] - board[i + (q >> 1)][j + (q & 1)]);
						}
						if (!(p == 0 && (q == 2 || q == 5)) && !(p == 3 && q == 5)) {
							best = big(best, s2 - board[i + (p & 1)][j + (p >> 1)] - board[i + (q & 1)][j + (q >> 1)]);
						}
					}
				}
			}
		}
		printf("%d. %d\n", tt, best);
	}
	return 0;
}