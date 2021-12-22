#include <stdio.h>

/*
문제 : 3가지 종류의 물고기가 있다. 각 물고기의 점수(<= 100, 음이 아닌 정수)가 주어질 때, M(M <= 100, 음이 아닌 정수)점
이하로 물고기를 잡는 모든 방법을 출력한다. 단, 물고기를 1마리 이상 잡아야 한다.

해결 방법 : 각 물고기를 0마리부터 100마리까지 한번씩 잡아보며 M점 이하가 되고 1마리 이상 잡았는지 확인한다.
그러한 경우 그 조합을 출력한다.

주요 알고리즘 : 브루트 포스

출처 : CCC 2009J 2번
*/

int main(void) {
    int a, b, c, m, r = 0;
    scanf("%d%d%d%d", &a, &b, &c, &m);
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                if (i + j + k == 0 || a * i + b * j + c * k > m) continue;
                printf("%d Brown Trout, %d Northern Pike, %d Yellow Pickerel\n", i, j, k);
                r++;
            }
        }
    }
    printf("Number of ways to catch fish: %d", r);
    return 0;
}