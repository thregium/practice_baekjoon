#include <stdio.h>

/*
문제 : N * N(N <= 24) 크기의 흰색과 검은색으로 이루어진 정사각형이 있다. 각 행과 열의 흰색과 검은색 수는 서로 같아야 하고,
연속해서 3개 이상 흰색이나 검은색이 나올 수 없다면 이 정사각형이 조건을 만족하는지 구한다.

해결 방법 : 정사각형의 각 행과 열별 검은색의 수를 센다. 이 수들이 N / 2와 동일한지 확인하고, 하나라도 다르다면 아닌 것이다.
그 다음, 각 줄별로 연속해서 3개가 같은 색인지 확인한다. 나오는 경우가 있다면 역시 아닌 것이고, 나오지 않는다면 만족하는 것이다.

주요 알고리즘 : 구현

출처 : PacNW 2019 W번
*/

char bw[32][32];
int row[32], col[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", bw[i]);
        for (int j = 0; j < n; j++) {
            if (bw[i][j] == 'B') {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (row[i] * 2 != n || col[i] * 2 != n) {
            printf("0");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 2; j++) {
            if ((bw[i][j] == bw[i][j + 1] && bw[i][j] == bw[i][j + 2]) || (bw[j][i] == bw[j + 1][i] && bw[j][i] == bw[j + 2][i])) {
                printf("0");
                return 0;
            }
        }
    }
    printf("1");
    return 0;
}