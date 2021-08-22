#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 50)개의 자연수가 있다. 이 자연수들에 대해 한 수에 K(K <= 10)를 더하는 것을 무한정 반복할 수 있다면
(물론 여러 수에 적용하는 것도 가능), 이 수들에 1부터 N까지의 자연수가 하나씩 있도록 할 수 있는지 구한다.

해결 방법 : 먼저 각 수들에 K를 더하더라도 K로 나눈 나머지는 변하지 않음을 알 수 있다.
따라서, 각 수들을 K로 나눈 나머지의 분포가 1 ~ N까지와 다르다면 1부터 N까지로 바꿀 수 없다.
그 다음으로는 각 수들을 정렬한 다음, 각 나머지의 1 ~ N까지의 정렬된 수보다 큰 수가 나오는지를 확인한다.
만약 더 큰 수가 나온다면 작은 수로 바꿀 방법이 없으므로 1부터 N까지로 바꾸는 것은 불가능하다.
그 외의 경우는 항상 1부터 N까지로 바꾸는 것이 가능하다.

주요 알고리즘 : 그리디 알고리즘, 수학
*/

int a[64], mods[16], orig[16], cnt[16];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        mods[a[i] % k]++;
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 1; i <= n; i++) {
        orig[i % k]++;
    }
    for (int i = 0; i < k; i++) {
        if (mods[i] != orig[i]) {
            printf("0");
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if ((cnt[a[i] % k] + (a[i] % k == 0)) * k + a[i] % k < a[i]) {
            printf("0");
            return 0;
        }
        else cnt[a[i] % k]++;
    }
    printf("1");
    return 0;
}