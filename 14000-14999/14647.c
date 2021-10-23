#include <stdio.h>

/*
문제 : N * M(N, M <= 500) 크기의 배열에서 숫자 9가 가장 많이 쓰인 행 또는 열을 제외한 칸들의 숫자 9의 개수를 구한다.

해결 방법 : 전체 배열의 숫자 9의 개수를 구한 다음, 각 행과 열의 숫자 9의 개수 가운데 가장 많은 것의 개수를 찾는다.
전체 9의 수에서 그 값을 빼면 된다.

주요 알고리즘 : 구현

출처 : 선린 1회예 C번
*/

int bingo[512][512];

int main(void) {
    int n, m, tot = 0, sum = 0, best = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &bingo[i][j]);
            for (int x = bingo[i][j]; x; x /= 10) sum += (x % 10 == 9);
        }
        tot += sum;
        if (sum > best) best = sum;
    }
    for (int i = 0; i < m; i++) {
        sum = 0;
        for (int j = 0; j < n; j++) {
            for (int x = bingo[j][i]; x; x /= 10) sum += (x % 10 == 9);
        }
        if (sum > best) best = sum;
    }
    printf("%d", tot - best);
    return 0;
}
