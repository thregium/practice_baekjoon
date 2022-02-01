#include <stdio.h>

/*
문제 : 2차원 평면의 격자의 좌표 (X, Y)에 X * Y의 값이 적혀있다. 이때, 좌표축과 같은 방향의 직사각형
형태로 격자를 선택하였을 때, 선택한 격자에 쓰인 값의 합이 S(S <= 100000)가 되는 경우의 수를 구한다.

해결 방법 : S 이하의 각 자연수마다 좌표 (1, A)에서 (1, B)까지의 합이 해당 수인 (A, B)의 개수를 구한다.
그러면 합이 S가 되는 경우의 수를 구할 수 있다. 행으로 R, 열로 C의 합을 갖는 (A, B)의 쌍을 찾으면
그 합은 R * C가 된다는 점을 이용하면 곱하여 S가 되는 모든 자연수 쌍에 대해
R * C의 값을 더하면 답이 된다.

주요 알고리즘 : 수학, 조합론

출처 : JAG 2018S3 I번
*/

int cnt[103000];

int main(void) {
    int s, t, r = 0;
    scanf("%d", &s);
    for (int i = 1; i <= 100000; i++) {
        t = 0;
        for (int j = i;; j++) {
            t += j;
            if (t > 100000) break;
            else cnt[t]++;
        }
    }
    for (int i = 1; i <= s; i++) {
        if (s % i) continue;
        r += cnt[i] * cnt[s / i];
    }
    printf("%d\n", r);
    return 0;
}