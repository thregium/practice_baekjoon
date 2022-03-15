#include <stdio.h>
#include <stdlib.h>

/*
문제 : 달팽이 형태의 배열에서 A번째 수와 B(A, B <= 10^9)번째 수 사이의 맨해튼 거리를 구한다.

해결 방법 : 우선 몇 번째 바퀴인 지 확인하고 배열을 돌려가며 두 수의 좌표를 구한다.
그리고 맨해튼 거리를 구하면 된다.

주요 알고리즘 : 수학

출처: SPPC 2016 A번
*/

typedef struct xy {
    int x, y;
} xy;

xy getpos(int n) {
    int sz = 0;
    xy res = { 0, 0 };
    if (n == 1) return res;
    while ((sz * 2 + 1) * (sz * 2 + 1) < n) sz++;
    n -= (sz * 2 - 1) * (sz * 2 - 1);
    
    for (int i = 0; i < 4; i++) {
        if (n <= sz * 2) {
            if (i == 0) {
                res.x = sz, res.y = n - sz;
            }
            else if (i == 1) {
                res.x = sz - n, res.y = sz;
            }
            else if (i == 2) {
                res.x = -sz, res.y = sz - n;
            }
            else if (i == 3) {
                res.x = n - sz, res.y = -sz;
            }
            break;
        }
        else n -= sz * 2;
    }
    return res;
}

int main(void) {
    int a, b;
    xy posa, posb;
    scanf("%d %d", &a, &b);
    posa = getpos(a);
    posb = getpos(b);
    printf("%d", abs(posa.x - posb.x) + abs(posa.y - posb.y));
    return 0;
}