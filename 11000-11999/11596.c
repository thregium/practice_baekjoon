#include <stdio.h>
#include <stdlib.h>

/*
문제 : 두 삼각형의 각 변의 길이(<= 100)가 주어질 때, 직사각형을 잘라서
두 삼각형을 만드는 방법이 있는 지 구한다.

해결 방법 : 우선 두 삼각형을 정렬한 다음, 두 삼각형의 각 변의 길이가 모두 같은 지(합동인지) 확인한다.
그 다음, 두 삼각형이 모두 직각 삼각형인 지 확인한다. 두 조건을 모두 만족하면
조건에 맞는 직사각형이 있고, 하나라도 만족하지 않는다면 조건에 맞는 직사각형이 없다.

주요 알고리즘 : 기하학, 정렬

출처 : PacNW 2015 D/T번 // SEUSA 2015D2 K번
*/

int t1[3], t2[3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int r = 1;
    scanf("%d %d %d%d %d %d", &t1[0], &t1[1], &t1[2], &t2[0], &t2[1], &t2[2]);
    qsort(t1, 3, sizeof(int), cmp1);
    qsort(t2, 3, sizeof(int), cmp1);
    for (int i = 0; i < 3; i++) {
        if (t1[i] != t2[i]) r = 0;
    }
    if (t1[0] * t1[0] + t1[1] * t1[1] != t1[2] * t1[2]) r = 0;
    if (t2[0] * t2[0] + t2[1] * t2[1] != t2[2] * t2[2]) r = 0;

    if (r) printf("YES");
    else printf("NO");
    return 0;
}