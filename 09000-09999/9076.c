#include <stdio.h>
#include <stdlib.h>

/*
문제 : 5개의 수가 주어질 때, 두 번째로 큰 수와 두 번째로 작은 수의 차가 4 이상이면 KIN을, 그 외에는 가장 큰 수와 가장 작은 수를 제외한 합을 출력한다.

해결 방법 : 수를 정렬하고 2번째로 작은 수와 4번째로 작은 수의 차를 확인한 다음 경우에 맞게 출력하면 된다.
(정렬하지 않고 구할 수도 있다.)

주요 알고리즘 : 구현, 정렬?

출처 : Seoul 2004 A번
*/

int n[5];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int t;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        for (int i = 0; i < 5; i++) {
            scanf("%d", &n[i]);
        }
        qsort(n, 5, sizeof(int), cmp1);
        if (n[3] - n[1] >= 4) printf("KIN\n");
        else printf("%d\n", n[1] + n[2] + n[3]);
    }
    return 0;
}