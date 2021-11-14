#include <stdio.h>
#include <stdlib.h>

/*
문제 : 게임 N(N <= 1000)개의 가격과 만족도(, <= 10^8)가 주어질 때,
게임들을 가성비(내림차순) -> 가격(오름차순) -> 번호(오름차순) 기준으로 정렬하여 상위 K(K <= N)개만 출력한다.

해결 방법 : 문제에 주어진 대로 정렬한다. 이때, 가성비는 정수형으로 계산해야 실수 오차를 피할 수 있다.

주요 알고리즘 : 수학, 정렬

출처 : 숭실대 2017 E번
*/

int game[1024][3];

int cmp1(const void* a, const void* b) {
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    int a2 = *((int*)a + 1);
    int b2 = *((int*)b + 1);
    int a3 = *((int*)a + 2);
    int b3 = *((int*)b + 2);
    if ((long long)a3 * b2 != (long long)b3 * a2) return (long long)a3 * b2 < (long long)b3* a2 ? 1 : -1;
    if (a2 != b2) return a2 > b2 ? 1 : -1;
    return a1 > b1 ? 1 : a1 == b1 ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &game[i][0], &game[i][1], &game[i][2]);
    }
    qsort(game, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < k; i++) {
        printf("%d\n", game[i][0]);
    }
    return 0;
}