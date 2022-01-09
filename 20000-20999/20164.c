#include <stdio.h>
#include <string.h>

/*
문제 : 자연수 N(N < 10^9)이 주어질 때, N을 주어진 규칙대로 자르는 경우 가운데 과정에서 볼 수 있는 홀수인 숫자의 개수가
가장 적은 경우와 가장 많은 경우의 홀수인 숫자의 개수를 각각 구한다.
1. 한 자리 수인 경우 그대로 종료한다.
2. 두 자리 수인 경우 두 숫자를 합한 값을 새로운 값으로 하여 다음 단계를 진행한다.
3. 세 자리 이상의 수인 경우 임의의 두 자리에서 수를 자른 다음, 자른 값을 모두 더한 값을 새 값으로 다음 단계를 진행한다.

해결 방법 : 재귀를 통해 각 단계를 진행하며 확인 가능한 홀수인 숫자의 개수를 센다.
한 자리가 되면 현재 숫자의 개수를 바탕으로 최대, 최소인 경우를 갱신한다.
두 자리인 경우는 간단히 구현 가능하며, 세 자리인 경우는 각 자리 수를 문자열로 바꾼 다음 위치를 정해서
수를 더해나가는 방식을 쓸 수 있다.

주요 알고리즘 : 브루트 포스, 재귀, 수학

출처 : 류호석 1회 1번
*/

int best = -1, worst = 99999;

void track(int n, int s) {
    char c[16] = { 0, };
    sprintf(c, "%d", n);
    int l = strlen(c), t, u, v;
    for (int m = n; m; m /= 10) {
        if (m & 1) s++;
    }
    if (n < 10) {
        if (s > best) best = s;
        if (s < worst) worst = s;
        return;
    }
    else if (n < 100) {
        track(n / 10 + n % 10, s);
    }
    else {
        t = 0;
        for (int i = 1; i < l; i++) {
            t *= 10;
            t += c[i - 1] - '0';
            u = 0;
            for (int j = i + 1; j < l; j++) {
                u *= 10;
                u += c[j - 1] - '0';
                v = 0;
                for (int k = j; k < l; k++) {
                    v *= 10;
                    v += c[k] - '0';
                }
                track(t + u + v, s);
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    track(n, 0);
    printf("%d %d", worst, best);
    return 0;
}