#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 100)개의 팀이 리그를 한 기록이 주어질 때, 각 팀의 순위를 구한다. 득실차/승자승 등은 고려하지 않고
승점만으로 순위를 구한다. 동점이 있으면 같은 순위로 매기고, 다음 순위는 동점팀의 수만큼 밀린다.

해결 방법 : 리그 경기를 각각 확인하며 이긴 팀에는 승점 3점을 추가하고, 비긴 경우 승점 1점씩을 양 팀에 추가한다.
그 다음, 승점 순으로 팀들을 정렬하고, 순위를 각각 매긴 다음, 다시 팀 번호 순서대로 정렬해서
각 팀의 순위를 출력하면 된다.

주요 알고리즘 : 구현, 정렬

출처 : JOI 2012예 2번
*/

int wp[128][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int cmp2(const void* a, const void* b) {
    int ai = *((int*)a + 1);
    int bi = *((int*)b + 1);
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, a, b, c, d;
    scanf("%d", &n);
    for (int i = 0; i < (n * (n - 1)) >> 1; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (c > d) wp[a][0] += 3;
        else if (c < d) wp[b][0] += 3;
        else {
            wp[a][0]++;
            wp[b][0]++;
        }
    }
    for (int i = 1; i <= n; i++) wp[i][1] = i;
    qsort(wp + 1, n, sizeof(int) * 3, cmp1);
    wp[1][2] = 1;
    for (int i = 1; i <= n; i++) {
        if (wp[i][0] == wp[i - 1][0]) wp[i][2] = wp[i - 1][2];
        else wp[i][2] = i;
    }
    qsort(wp + 1, n, sizeof(int) * 3, cmp2);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", wp[i][2]);
    }
    return 0;
}