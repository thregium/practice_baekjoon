#include <stdio.h>

/*
문제 : N(N <= 10000)개의 수들 가운데 첫 번째 수가 가장 큰지 확인한다.

해결 방법 : 배열에 각 수들을 저장한 후, 2번째 수 이후의 수들을 1번째 수와 비교해 이후 수가 더 큰 경우 가장 큰 수가 아니고,
그러한 수가 없다면 가장 큰 수이다.

주요 알고리즘 : 구현

출처 : Brasil 2019 B번
*/

int v[10240];

int main(void) {
    int n, r = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i < n; i++) {
        if (v[i] > v[0]) r = 0;
    }
    printf("%c", r ? 'S' : 'N');
    return 0;
}