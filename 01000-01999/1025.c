#include <stdio.h>
#include <math.h>

/*
문제 : N * M(N, M <= 9) 크기의 표에 숫자들이 쓰여 있다. 이 표에서 숫자들을 아무 점에서 한 방향으로 이어붙인 수들 가운데
가장 큰 제곱수를 구한다. 없다면 -1을 출력한다.

해결 방법 : 모든 지점의 모든 방향에 대해 이어붙여 나올 수 있는 수들을 전부 구한 다음, 각각에 대해 제곱수인지 확인한다.
제곱수인지는 sqrt함수의 결과 또는 그 주위 값들의 제곱과 비교해서 같다면 제곱수임을 확인 가능하다.
이들 중 가장 큰 제곱수를 찾으면 된다.

주요 알고리즘 : 브루트 포스
*/

char nums[16][16];

int main(void) {
    int n, m;
    long long p, rt, best = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dx = -9; dx <= 9; dx++) {
                for (int dy = -9; dy <= 9; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    p = 0;
                    for (int i = 0;; i++) {
                        if (x + dx * i < 0 || y + dy * i < 0 || x + dx * i >= n || y + dy * i >= m) break;
                        p *= 10;
                        p += nums[x + dx * i][y + dy * i] - '0';
                        if (p <= best) continue;
                        rt = sqrt(p);
                        for (int i = rt - 10; i <= rt + 10; i++) {
                            if ((long long)i * i == p) best = p;
                        }
                    }
                }
            }
        }
    }
    printf("%lld", best);
    return 0;
}