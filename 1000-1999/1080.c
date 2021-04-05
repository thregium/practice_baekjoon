#include <stdio.h>

/*
문제 : N * M (N, M <= 50) 크기의 두 행렬이 있을 때, 앞쪽 행렬을 뒷쪽 행렬로 만드는데 필요한 연산 횟수의 최솟값을 출력한다.
연산은 3 * 3 크기의 부분행렬의 값을 뒤집는 것이다.

해결 방법 : 맨 윗줄부터 확인해가면서 해당하는 칸에서 두 행렬의 값이 다르다면 해당 칸을 시작으로 하는 3 * 3 행렬을 뒤집는다.
가능한 모든 칸에 대해 확인한 후에는 두 행렬이 같은지 확인하고, 같지 않다면 -1, 같다면 지금까지 시행한 연산의 횟수를 출력한다.

주요 알고리즘 : 그리디 알고리즘
*/

char a[64][64], b[64][64];

int main(void) {
	int n, m, r = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%s", b[i]);
	}
	for(int i = 0; i < n - 2; i++) {
		for(int j = 0; j < m - 2; j++) {
			if(a[i][j] != b[i][j]) {
				for(int x = 0; x < 3; x++) {
					for(int y = 0; y < 3; y++) {
						a[i + x][j + y] = (!(a[i + x][j + y] - '0') + '0');
					}
				}
				r++;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] != b[i][j]) r = -1;
		}
	}
	printf("%d", r);
	return 0;
}
