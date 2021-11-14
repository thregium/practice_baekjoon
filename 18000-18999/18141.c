#include <stdio.h>

/*
문제 : N(N <= 50)개의 자연수(<= 100)가 주어질 때, 서로 다른 i, j, k에 대해 (a[i] - a[j]) / a[k]가 항상 정수인지 확인한다.

해결 방법 : 3중 for 문을 통해 서로 다른 i, j, k를 뽑은 다음 (a[i] - a[j]) % a[k]가 0이 아닌 경우가 있는지 확인해본다.
그러한 경우가 있다면 정수가 아닌 경우가 있는 것이고 그 외에는 항상 정수인 것이다.

주요 알고리즘 : 브루트 포스

출처 : Taipei 2019 C번
*/

int a[64];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if ((a[i] - a[j]) % a[k]) r = 0;
            }
        }
    }
    printf("%s", r ? "yes" : "no");
    return 0;
}
