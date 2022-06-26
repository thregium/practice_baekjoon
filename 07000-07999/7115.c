#include <stdio.h>

/*
문제 : K(K <= 30000) 단위 크기인 격자에 반지름 R(R <= 30000)인 원을 그렸다.
원의 테두리가 지나는 칸의 개수를 구한다. 꼭짓점만 지나는 칸은 지나가는 칸이 아니다.

해결 방법 : 투 포인터를 이용하여 사분원의 각 X좌표마다의 Y좌표 범위를 찾은 다음 인접한 곳과의
차이를 이용해 그 값을 더하고 4를 곱하면 된다.

주요 알고리즘 : 수학, 기하학, 투 포인터

출처 : LtOI 11_2 3번
*/

int main(void) {
    int k, r, pos = 0, last = 0, now = 0, tnow, tlast;
    long long res = 0;
    scanf("%d %d", &k, &r);
    pos = r - 1;
    while (pos % k) pos--;
    for (; pos >= 0; pos -= k) {
        last = now;
        for (;; now++) {
            if (now & 1) {
                if (((now + 1) >> 1) * ((now + 1) >> 1) + pos * pos > r * r) break;
            }
            else {
                if ((now >> 1) * (now >> 1) + pos * pos >= r * r) break;
            }
        }

        tnow = (now >> 1) / k * 2;
        tlast = (last >> 1) / k * 2;
        if ((now & 1) || (now >> 1) % k) tnow++;
        if ((last & 1) || (last >> 1) % k) tlast++;

        if (tnow & 1) res += ((tnow - tlast) >> 1) + 1;
        else res += (tnow - tlast + 1) >> 1;
    }
    printf("%lld", res * 4);
    return 0;
}