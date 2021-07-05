#include <stdio.h>

/*
문제 : N(N <= 100)개의 정사각형 테두리가 한 점에서 퍼져나가는 형태로 별을 출력한다.

해결 방법 : 미리 배열을 만들어둔 후, 가장 바깥쪽 정사각형부터 채워나간다. 이때 공백과 별을 교대로 덮어나가는 방식을
사용하더라도 충분히 시간 내로 돌아가는 것이 가능하다.

주요 알고리즘 : 구현
*/

char s[512][512];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int sz = n - 1; sz >= 0; sz--) {
        for (int i = n * 2 - sz * 2 - 2; i <= n * 2 + sz * 2 - 2; i++) {
            for (int j = n * 2 - sz * 2 - 2; j <= n * 2 + sz * 2 - 2; j++) s[i][j] = '*';
        }
        for (int i = n * 2 - sz * 2 - 1; i <= n * 2 + sz * 2 - 3; i++) {
            for (int j = n * 2 - sz * 2 - 1; j <= n * 2 + sz * 2 - 3; j++) s[i][j] = ' ';
        }
    }
    for (int i = 0; i <= n * 4 - 4; i++) {
        for (int j = 0; j <= n * 4 - 4; j++) {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
    return 0;
}