#include <stdio.h>
#include <stdlib.h>

/*
문제 : 주파수를 1 올리는 버튼, 1 내리는 버튼, 저장된 주파수로 바꾸는 버튼이 있을 때, A에서 B(A, B <= 1000, 자연수)로
바꾸는 데 필요한 최소 버튼 수를 구한다. 저장된 주파수는 N(N <= 5)개 이하다.

해결 방법 : A에서 B로 직접 가는 경우와 각 저장된 주파수에서 B로 가는 경우를 한 번씩 해본다.
각 경우 필요한 버튼 수는 주파수 차이만큼과 같다. 후자는 저장된 주파수로 바꾸어야 하므로 1을 더한다.

주요 알고리즘 : 브루트 포스

출처 : CHCI 2007RJ 1번
*/

int stor[1024];

int main(void) {
    int a, b, n, r;
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stor[i]);
    }
    r = abs(a - b);
    for (int i = 0; i < n; i++) {
        if (abs(stor[i] - b) + 1 < r) r = abs(stor[i] - b) + 1;
    }
    printf("%d", r);
    return 0;
}