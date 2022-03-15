#include <stdio.h>
#include <stdlib.h>

/*
문제 : 높이 H(H <= 30)의 이진 트리에서 N번째 이동에 도달하게 되는 리프 정점의 번호를 구한다.
각 이동에서 각 정점마다 마지막으로 이동한 방향의 반대로 이동한다. 단, 첫 이동시에는 왼쪽으로 간다.

해결 방법 : 각 경우를 잘 살펴보면 N을 H + 1비트로 만든 다음 비트 순서를 뒤집은 것임을 알 수 있다.
따라서 그 값을 구해주면 된다.

주요 알고리즘 : 수학, 트리

출처 : ILOCAMP 2011I 1-1번
*/

char s[32];

int main(void) {
    int n, h;
    scanf("%d %d", &n, &h);
    for (int i = n - 1, j = 0; j < h; j++, i >>= 1) s[j] = (i & 1) + '0';
    printf("%lld", strtoll(s, NULL, 2));
    return 0;
}