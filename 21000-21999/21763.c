#include <stdio.h>

/*
문제 : N * N(N <= 100) 크기의 빙고에서 K(K <= N * N)칸을 빙고 줄을 하나도 만들지 않으면서
채우는 방법이 있는 지 찾고 있다면 그러한 방법을 출력한다.

해결 방법 : 비둘기집 원리에 의해 N개 미만의 칸이 비었다면 적어도 한 줄은 차게 되므로
답이 될 수 없다. 그 이상의 경우에는 대각선으로 비우되 맨 앞뒤 칸만 서로 좌우를 바꾸어 주면
최소한으로 빈칸을 남기고 칸들을 채우는 방법이 된다. 단, 2 * 2에서 2칸을 채우는 것은 불가능함에 주의한다.

주요 알고리즘 : 구성적

출처 : KAIST 2021S A번
*/

char res[128][128];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    if (k > n * (n - 1) || (n == 2 && k == 2)) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (k == 0) res[i][j] = '.';
            else if (i == j) {
                if (i > 0 && i < n - 1) res[i][j] = '.';
                else res[i][j] = '#';
            }
            else if (i == 0 && j == n - 1) res[i][j] = '.';
            else if (i == n - 1 && j == 0) res[i][j] = '.';
            else res[i][j] = '#';

            if (res[i][j] == '#') k--;
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}