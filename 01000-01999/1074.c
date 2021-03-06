#include <stdio.h>

/*
문제 : 2^N * 2^N (N <= 15) 크기의 배열을 Z 모양으로 탐색할 때, R행 C열을 몇 번째로 방문하는지 출력한다.

해결 방법 : 전체 배열을 행과 열을 기준으로 반씩 나누었을 때 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 순으로 탐색하게 된다.
해당 구간의 모든 원소를 탐색한 후 다음 구간을 탐색하게 되므로 해당하는 구간을 찾고, 결괏값으로는 해당하는 구간의 이전 구간에 있는 수들에
해당 구간에서 재귀적으로 탐색한 값을 더한 값을 출력한다.

주요 알고리즘 : 재귀
*/

int div(int n, int r, int c) {
	//n : 현재 재귀 깊이, r : 현재 구간에서의 상대적 행, c : 현재 구간에서의 상대적 열
    if (n == 0) return 0; //한 칸만 범위인 경우
    if (r < (1 << (n - 1))) {
        if (c < (1 << (n - 1))) {
            return div(n - 1, r, c); //왼쪽 위에 있는 경우
        }
        else {
            return (1 << ((n - 1) * 2)) + div(n - 1, r, c - (1 << (n - 1))); //오른쪽 위에 있는 경우
        }
    }
    else {
        if (c < (1 << (n - 1))) {
            return (1 << ((n - 1) * 2)) * 2 + div(n - 1, r - (1 << (n - 1)), c); //왼쪽 아래에 있는 경우
        }
        else {
            return (1 << ((n - 1) * 2)) * 3 + div(n - 1, r - (1 << (n - 1)), c - (1 << (n - 1))); //오른쪽 아래에 있는 경우
        }
    }
}

int main(void) {
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    printf("%d", div(n, r, c));
    return 0;
}
