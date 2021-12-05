#include <stdio.h>

/*
문제 : G(G < 1000, G는 홀수)개의 정수들이 주어진다. 이때, 한 정수를 제외하고는 모두 같은 정수인 쌍이 있을 때,
쌍이 없는 정수를 구한다.

해결 방법 : 배열을 입력받은 다음, 배열의 앞에서부터 뒤에 있는 수 가운데 쌍을 지을 수 있는 수가 있나 확인한다.
있다면 그 수와 쌍을 지었다는 표시를 하고 다음 수를 살펴본다. 만약 이미 쌍을 지은 수가 있으면 넘어간다.
이를 반복한 후 쌍을 짓지 못한 수가 답이 된다.

주요 알고리즘 : 구현

출처 : GCJ 2010A OA2번
*/

int a[1024], chk[1024];

int main(void) {
    int t, g;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d", &g);
        if (~g & 1) return 1;
        for (int i = 0; i < g; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < g; i++) {
            if (chk[i]) continue;
            for (int j = i + 1; j < g; j++) {
                if (chk[j]) continue;
                if (a[i] == a[j]) {
                    chk[i] = 1;
                    chk[j] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < g; i++) {
            if (!chk[i]) {
                printf("Case #%d: %d\n", tt, a[i]);
            }
            else chk[i] = 0;
        }
    }
    return 0;
}