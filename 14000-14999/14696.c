#include <stdio.h>

/*
문제 : 4, 3, 2, 1의 수가 임의의 개수만큼 적힌 카드 2개가 주어질 때, 큰 수부터 비교해서 개수가 다른 경우, 더 많은 쪽이 이긴다고 한다.
이때, 이기는 쪽을 찾는다. 모든 수가 같다면 비긴다.

해결 방법 : 문제에 쓰인대로 구현한다.

주요 알고리즘 : 구현

출처 : 정올 2017 초1번
*/

int ac[8], bc[8];

int main(void) {
    int n, a, b, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i <= 4; i++) {
            ac[i] = 0;
            bc[i] = 0;
        }
        scanf("%d", &a);
        for (int j = 0; j < a; j++) {
            scanf("%d", &x);
            ac[x]++;
        }
        scanf("%d", &b);
        for (int j = 0; j < b; j++) {
            scanf("%d", &x);
            bc[x]++;
        }
        if (ac[4] > bc[4]) printf("A");
        else if (ac[4] < bc[4]) printf("B");
        else if (ac[3] > bc[3]) printf("A");
        else if (ac[3] < bc[3]) printf("B");
        else if (ac[2] > bc[2]) printf("A");
        else if (ac[2] < bc[2]) printf("B");
        else if (ac[1] > bc[1]) printf("A");
        else if (ac[1] < bc[1]) printf("B");
        else printf("D");
        printf("\n");
    }
    return 0;
}