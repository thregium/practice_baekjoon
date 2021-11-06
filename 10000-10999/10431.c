#include <stdio.h>

/*
문제 : 20개의 서로 다른 수들이 순서대로 주어질 때, 삽입정렬시 교환 횟수를 구한다.

해결 방법 : 매번 새 수를 넣을 때 마다 앞에 있는 수 가운데 더 큰 수의 개수만큼 교환을 해야 한다.
따라서, 이 값을 전부 더하면 답이 된다.

주요 알고리즘 : 구현?

출처 : GNY 2014 A번
*/

int height[32];

int main(void) {
    int p, t, r = 0;
    scanf("%d", &p);
    for (int pp = 0; pp < p; pp++) {
        scanf("%d", &t);
        r = 0;
        for (int i = 0; i < 20; i++) {
            scanf("%d", &height[i]);
            for (int j = 0; j < i; j++) {
                if (height[j] > height[i]) r++;
            }
        }
        printf("%d %d\n", t, r);
    }
    return 0;
}