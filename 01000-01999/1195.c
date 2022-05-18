#include <stdio.h>
#include <string.h>

/*
문제 : 길이 100 이하의 두 톱니 형태가 주어질 때, 두 톱니를 맞물리게 하면서 합친 것의 길이를
최소한으로 하는 경우 그 길이를 구한다.

해결 방법 : 두 톱니를 움직여가며 맞물리는 경우 가운데 가장 짧은 경우를 구하면 된다.
모든 경우를 구할 수 있고 그 과정에서 오류가 생기지 않도록 주의해야 한다.

주요 알고리즘 : 브루트 포스

출처 : NEERC 2006 K번
*/

char s1[128], s2[128];

int main(void) {
    int l1, l2, best = 103000, lt, rt, good;
    scanf("%s%s", s1, s2);
    l1 = strlen(s1);
    l2 = strlen(s2);
    for (int offset = -l2; offset <= l1; offset++) {
        lt = 103000, rt = -103000;
        for (int i = 0; i < l1; i++) {
            if (i < lt) lt = i;
            if (i > rt) rt = i;
        }
        good = 1;
        for (int i = offset; i < offset + l2; i++) {
            if (i >= 0 && i < l1) {
                if (s1[i] == s2[i - offset] && s1[i] == '2') good = 0;
            }
            if (i < lt) lt = i;
            if (i > rt) rt = i;
        }
        if (!good) continue;
        if (rt - lt + 1 < best) best = rt - lt + 1;
    }
    printf("%d", best);
    return 0;
}