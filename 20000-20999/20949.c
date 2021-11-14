#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)개의 모니터의 가로와 세로 픽셀 수가 주어질 때, PPI가 높은 순 -> 번호가 낮은 순으로
모니터들의 번호를 출력한다. 대각선 길이는 모두 같다.

해결 방법 : 가로 픽셀 수의 제곱 * 세로 픽셀 수의 제곱을 비교해서 서로 다른 경우 그 기준으로 정렬하고,
같다면 번호 기준으로 정렬한다. 그 후 정렬한 순서대로 번호를 출력하면 된다.

주요 알고리즘 : 수학, 정렬

출처 : 강원대 1회예 A번
*/

int mon[1024][3];

int cmp1(const void* a, const void* b) {
    int aw = *((int*)a + 1);
    int ah = *((int*)a + 2);
    int bw = *((int*)b + 1);
    int bh = *((int*)b + 2);
    int ai = aw * aw + ah * ah;
    int bi = bw * bw + bh * bh;
    if (ai != bi) return ai < bi ? 1 : ai == bi ? 0 : -1;
    ai = *(int*)a;
    bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &mon[i][1], &mon[i][2]);
        mon[i][0] = i + 1;
    }
    qsort(mon, n, sizeof(int) * 3, cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d\n", mon[i][0]);
    }
    return 0;
}