#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 1000)명에게서 펜을 빌릴 수 있다. 각 사람들이 빌려줄 수 있는 펜의 수(<= 100)가 주어지면,
M * K(M * K <= 10000)개를 빌리기 위해서 빌려야 하는 사람의 수 중 최솟값을 구한다. 불가능하다면 "STRESS"를 출력한다.

해결 방법 : 가장 펜이 많은 사람부터 빌리면 된다. 펜의 수가 M * K를 넘어간 순간 그 때까지 빌린 사람 수를 출력한다.
끝까지 넘어가지 않는다면 STRESS를 출력한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : 인하대 2016 K번
*/

int a[1024];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, m, k, r = 0;
    scanf("%d%d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        r += a[i];
        if (r >= m * k) {
            printf("%d", i + 1);
            return 0;
        }
    }
    printf("STRESS");
    return 0;
}