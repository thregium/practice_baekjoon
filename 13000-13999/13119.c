#include <stdio.h>
#include <malloc.h>

/*
문제 : N * M(N, M <= 100000, N * M <= 200000) 크기의 그림에 각 지점 별 산의 높이와 도로의 높이가 주어질 때,
산과 도로의 형태를 출력한다.

해결 방법 : 동적 할당을 통해 N * M 크기의 배열을 생성한 다음, 우선 산을 그린다.
그 후 도로와 터널을 그리고 교각을 그린 다음 출력하면 된다.

주요 알고리즘 : 구현

출처 : Coder's 2016R2 B번
*/

char* res[103000];

int main(void) {
    int n, m, x, h;
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 0; i < n; i++) {
        res[i] = malloc(sizeof(char) * (m + 1));
        for (int j = 0; j < m; j++) res[i][j] = '.';
        res[i][m] = '\0';
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &h);
        for (int j = n - h; j < n; j++) {
            res[j][i] = '#';
        }
    }
    for (int i = 0; i < m; i++) {
        if (res[n - x][i] == '#') res[n - x][i] = '*';
        else res[n - x][i] = '-';
        if (i % 3 == 2) {
            for (int j = n - x + 1; j < n; j++) {
                if (res[j][i] == '#') break;
                else res[j][i] = '|';
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}