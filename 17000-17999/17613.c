#include <stdio.h>

/*
문제 : [X, Y](1 <= X <= Y <= 10^9)에서 가장 큰 점프 수를 구한다.
점프 수는 0부터 1, 2, 4, 8, ... 단위로 점프하며 각 칸에 도달 가능한 최소 점프 횟수이다.
점프 도중 언제라도 점프 거리를 1로 되돌릴 수 있다.

해결 방법 : 각 지점의 점프 횟수는 그리디 알고리즘이 성립한다. 넘어가기 전 부분까지
점프한 다음 거리를 초기화하는 것을 반복하면 최소 점프 횟수가 되기 때문이다.
이를 이용해 구간의 가장 큰 점프 수 분할 정복으로 구할 수 있다.
임의의 위치 x에서 뺄 수 있는 가장 큰 2^i - 1을 뺀 값이 i + (jump(x - (2^i - 1)))과 같다는 점을 이용한다.
왼쪽과 오른쪽 지점을 빼 나가면 되는데, 이때 (2^i - 1) * 2가 x보다 작은 경우
중간의 값은 수학적으로 계산하고 그 외의 경우는 직접 분할해 풀면 시간 내에 푸는 것이 가능하다.
중간의 값은 i가 1이 아니라면 sum(1, i - 1) + 1과 같다.

주요 알고리즘 : 수학, 분할 정복, 그리디 알고리즘?

출처 : 정올 2019_1 고2번
*/

int mem[103000][32], res[103000];

int small(int a, int b) {
    return a < b ? a : b;
}

int big(int a, int b) {
    return a > b ? a : b;
}

int gethighest(int s, int e, int n) {
    if (s > e) return -1;
    if (s == e && s == 0) return n;
    int r = -1;
    for (int i = 30; i >= 1; i--) {
        if (s <= (1LL << i) - 1 && (1LL << i) - 1 <= e) {
            r = big(r, gethighest(s, (1LL << i) - 2, n));
            if (((1LL << i) - 1) * 2 <= e) {
                //r = big(r, gethighest(0, ((1LL << i) - 1), n + i));
                if (i > 1) r = big(r, n + i + (((i - 1) * i) >> 1) + 1);
                r = big(r, gethighest(0,
                    e - ((1LL << i) - 1) * 2, n + i * 2));
            }
            else {
                r = big(r, gethighest(0, e - (1LL << i) + 1, n + i));
            }
            break;
        }
        else if ((1LL << i) - 1 < s) {
            r = big(r, gethighest(s - (1LL << i) + 1, e - (1LL << i) + 1, n + i));
            break;
        }
    }
    return r;
}

int main(void) {
    int n, m, c = 0, t, a, b;
    //scanf("%d", &n);
    n = 1000;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 32; j++) mem[i][j] = 1012345678;
    }
    mem[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 25; j++) {
            mem[i + 1][1] = small(mem[i + 1][1], mem[i][j] + 1);
            if (i + (1 << j) <= n) {
                mem[i + (1 << j)][j + 1] = small(mem[i + (1 << j)][j + 1], mem[i][j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        m = 103000;
        for (int j = 0; j < 25; j++) {
            if (mem[i][j] < m) m = mem[i][j];
        }
        if (((i + 1) & (-(i + 1))) == i + 1) c++;
        //printf("%d: %d %d\n", i, m, m - c);
        res[i] = m;
        if (res[i] - c != res[i - (1 << c) + 1]) {
            printf("%d != %d\n", res[i] - c, res[i - (1 << c) + 1]);
            return 1;
        }
    }
    /*
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            printf("%d-%d: %d\n", i, j, gethighest(i, j, 0, 3));
            m = -1;
            for (int k = i; k <= j; k++) {
                m = big(m, res[k]);
            }
            if (gethighest(i, j, 0, 3) != m) {
                printf("%d != %d", gethighest(i, j, 0, 3), m);
                return 1;
            }
        }
    }
    */
    
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", gethighest(a, b, 0));
    }
    
    return 0;
}