#include <stdio.h>
#include <stdlib.h>

/*
문제 : N(N <= 300000)명의 난이도 의견(1 <=, <= 30)이 주어질 때, 최종적으로 적용된 난이도를 구한다.
의견이 0개인 경우 난이도는 0이고, 그 외에는 상하위 15%를 반올림하여 자르고 나온 평균을 반올림한 값을 결과로 적용한다.

해결 방법 : 우선 N이 0인지 확인한다. 그렇다면 0을 출력한다. 그 이외에는 난이도 의견들을 입력받은 다음, 정렬해준다.
매번 상하위에서 잘리는 의견 수는 (N * 15 + 50) / 100이므로 이를 이용해 잘리는 의견 수를 구한 다음,
그 범위를 제외한 의견이 합을 구한다. 그 다음, (적용된 의견 수) / 2를 더하고 (적용된 의견 수)를 나누면
평균이 되므로 그 값을 출력해주면 된다.

주요 알고리즘 : 수학, 정렬

출처 : 서강대 2019C A번
*/

int a[327680];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int n, del, s = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("0");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    del = (n * 15 + 50) / 100;
    for (int i = del; i < n - del; i++) {
        s += a[i];
    }
    printf("%d", (s + ((n - del * 2) >> 1)) / (n - del * 2));
    return 0;
}