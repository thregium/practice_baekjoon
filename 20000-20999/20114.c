#include <stdio.h>

/*
문제 : N(N <= 100)자로 이루어진 문자열이 세로로 H배, 가로로 W(H, W <= 10)배 번졌다 할 때, 원래 문자열을 구한다.
단, 일부 문자열은 ?인 상태이고, 알 수 없는 문자는 ?로 출력한다. 모순되는 경우는 주어지지 않는다.

해결 방법 : 각 문자가 번진 위치에 대해 ?가 아닌 문자가 있는지 확인한다. 있다면 원래 문자는 그것이고,
없다면 알 수 없으므로 ?로 그대로 가면 된다.

주요 알고리즘 : 문자열, 구현

출처 : 경북대 2020 C번
*/

char note[16][1024], res[128];

int main(void) {
    int n, h, w;
    scanf("%d %d %d", &n, &h, &w);
    for (int i = 0; i < h; i++) {
        scanf("%s", note[i]);
    }
    for (int i = 0; i < n; i++) {
        res[i] = '?';
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < w; k++) {
                if (note[j][i * w + k] != '?') res[i] = note[j][i * w + k];
            }
        }
    }
    printf("%s", res);
    return 0;
}