#include <stdio.h>

/*
문제 : N * N(N <= 1000) 크기의 배열이 있을 때, 오른쪽과 아래쪽으로만 움직일 수 있다면
왼쪽 위에서 오른쪽 아래까지 움직이면서 이동하는 경로의 수를 전부 곱한 값에서 0의 갯수가 최소인 경우 0의 갯수를 출력한다.
단, 값이 0인 칸으로는 이동할 수 없다.

해결 방법 : 0의 갯수는 2와 5가 곱해지는 경우 늘어나게 되므로 이동하며 이동하며 소인수 가운데 2가 최소한인 경우와 5가 최소한인 경우로
나누어 생각할 수 있다. 그 가운데 더 적은 수가 0의 최솟값이 된다. 이때, 0인 칸으로는 이동할 수 없으므로 이 점에 유의해야 한다.

주요 알고리즘 : 
*/

int two[1024][1024], five[1024][1024], mem2[1024][1024], mem5[1024][1024];

int small(int a, int b) {
    if (a < 0 && b < 0) return -1;
    if (a < 0) return b;
    if (b < 0) return a;
    return a < b ? a : b;
}

int main(void) {
    int n, x, c, u, l;
    scanf("%d", &n);
	//각 칸의 2와 5의 수를 저장한다.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (x == 0) {
				//배열값이 0인 경우
                two[i][j] = -1;
                five[i][j] = -1;
                continue;
            }
            c = 0;
            for (int y = x; !(y % 2); y /= 2) c++;
            two[i][j] = c;
            c = 0;
            for (int y = x; !(y % 5); y /= 5) c++;
            five[i][j] = c;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
				//2나 5로 나누어 떨어지지 않는 경우
                mem2[i][j] = two[i][j];
                mem5[i][j] = five[i][j];
                continue;
            }
            u = (i == 0) ? -1 : mem2[i - 1][j];
            l = (j == 0) ? -1 : mem2[i][j - 1];
            mem2[i][j] = small(u, l);
            if (mem2[i][j] >= 0) mem2[i][j] += two[i][j];
            if (two[i][j] < 0) mem2[i][j] = -1;
            u = (i == 0) ? -1 : mem5[i - 1][j];
            l = (j == 0) ? -1 : mem5[i][j - 1];
            mem5[i][j] = small(u, l);
            if (mem5[i][j] >= 0) mem5[i][j] += five[i][j];
            if (five[i][j] < 0) mem5[i][j] = -1;
        }
    }
    printf("%d", small(mem2[n - 1][n - 1], mem5[n - 1][n - 1])); //2와 5 중 더 작은 것을 선택
    return 0;
}