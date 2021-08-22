#include <stdio.h>

/*
문제 : N(N <= 50)개의 트로피가 일렬로 있다. 왼쪽에서부터 이 트로피들의 높이가 주어질 때,
왼쪽에서 보았을 때와 오른쪽에서 보았을 때 보이는 트로피의 개수를 각각 구한다.

해결 방법 : 왼쪽에서 보았을 때와 오른쪽에서 보았을 때 모두 앞의 최대 높이보다 높은 트로피만 볼 수 있다.
따라서, 현재까지의 최대 높이를 저장하며 그보다 높은 트로피가 나올 때만 개수를 늘려가면 된다.

주요 알고리즘 : 구현
*/

int trophy[64];

int main(void) {
    int n, h, l = 0, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &trophy[i]);
    }
    h = 0;
    for (int i = 0; i < n; i++) {
        if (trophy[i] > h) {
            h = trophy[i];
            l++;
        }
    }
    h = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (trophy[i] > h) {
            h = trophy[i];
            r++;
        }
    }
    printf("%d\n%d", l, r);
    return 0;
}