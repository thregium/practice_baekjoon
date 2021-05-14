#include <stdio.h>

/*
문제 : N * M(N, M <= 10) 크기의 배열을 좌우로 뒤집은 결과를 출력한다.

해결 방법 : 배열을 입력받은 후 줄 단위로 뒤집는다.

주요 알고리즘 : 구현

출처 : 고려대 2016 D번
*/

char shape[16][16];

void swap(char* a, char* b) {
    char t = *a;
    *a = *b;
    *b = t;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", shape[i]);
        for (int j = 0, k = m - 1; j < k; j++, k--) {
            swap(&shape[i][j], &shape[i][k]);
        }
        printf("%s\n", shape[i]);
    }
    return 0;
}