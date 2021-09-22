#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 200000)개의 화재를 진압해야 한다. 각 불을 끄는데 걸리는 시간은 현재까지 소요된 시각 * a + b라는 일차식을 따른다.
이동하는데는 시간이 걸리지 않는다면 불을 끄는데 필요한 최소 시간을 구한다. a와 b는 음이 아닌 40000 이하의 정수이다.

해결 방법 : 두 화재를 진압하는데 우선순위를 확인해보면 a / b가 큰 것이 우선이 되는 것이 더 좋음을 알 수 있다.
이를 전체 화재에 적용해보면 a / b 순으로 정렬을 해두고 순서대로 화재를 진압할 때의 시간을 구하면 된다.
단, 이 과정에서 a와 b가 모두 0인 화재에 대해서는 예외처리를 해줘야 한다. 언제 처리되든 상관 없기 때문에
임의의 수로 바꾸어 주면 된다.

주요 알고리즘 : 그리디 알고리즘, 수학, 정렬
*/

int fires[204800][2], chk[16], perm[16];
long long correct = 1234567890987654321;

int cmp1(const void* a, const void* b) {
    int ax = *(int*)a;
    int bx = *(int*)b;
    int ay = *((int*)a + 1);
    int by = *((int*)b + 1);
    if (ax == 0 && ay == 0) ay = 1;
    if (bx == 0 && by == 0) by = 1;
    int r = ay * bx - ax * by;
    return r;
}

void check(int n) {
    long long r = 0;
    for (int i = 0; i < n; i++) {
        r = (r + fires[perm[i]][0] * r + fires[perm[i]][1]);
    }
    if (r < correct) correct = r;
}

int track(int n, int x) {
    if (n == x) {
        check(n);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chk[i]) continue;
        perm[x] = i;
        chk[i] = 1;
        track(n, x + 1);
        chk[i] = 0;
    }
}

int main(void) {
    int n;
    long long r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &fires[i][0], &fires[i][1]);
    }
    qsort(fires, n, sizeof(int) * 2, cmp1);
    for (int i = 0; i < n; i++) {
        r = (r + fires[i][0] * r + fires[i][1]) % 40000;
    }
    printf("%d", r);
    
    /*
    scanf("%d", &n);
    for (long long i = 0; i < 100; i++) {
        for (int j = 0; j < n; j++) {
            fires[j][0] = (rand() & 15);
            fires[j][1] = (rand() & 15);
        }
        correct = 1234567890987654321;
        r = 0;
        track(n, 0);
        qsort(fires, n, sizeof(int) * 2, cmp1);
        for (int j = 0; j < n; j++) {
            r = (r + fires[j][0] * r + fires[j][1]);
        }
        if (r != correct) {
            printf("ERROR! at %d ---- %lld : %lld\n", i, r, correct);
            for (int j = 0; j < n; j++) {
                printf("%d %d / ", fires[j][0], fires[j][1]);
            }
            printf("\n");
        }
    }
    */
    return 0;
}