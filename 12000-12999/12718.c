#include <stdio.h>

/*
문제 : 좌표평면상의 N(N <= 100000)개의 점의 위치(를 만드는 선형 동차 함수)가 주어질 때,
서로 다른 3개의 점의 무게중심이 격자점 위인 쌍의 개수를 구한다.
각 점의 좌표는 10^9 이하의 음이 아닌 정수이다.

해결 방법 : 서로 다른 세 개의 점에 대해 X, Y 좌표에서 합이 3으로 나누어 떨어지면
무게중심이 격자점 위에 존재하게 된다. 각 X, Y 좌표의 모듈로에 따른 점의 개수를 저장한 다음,
각 모듈로의 쌍에 따라 3개의 점에 대한 모듈로 쌍을 확인하고, X, Y좌표에서의 합이 모두
3으로 나누어 떨어지는 경우 서로 다른 3개의 점을 뽑는 경우의 수를 결괏값에 더한다.

이러한 경우의 수는 3개의 모듈로가 같다면 n_C_3(n은 그러한 점의 개수),
2개가 같고 한 개가 다르다면 n_C_2 * m(n은 2개인 점의 개수, m은 1개인 점의 개수),
모두 다르다면 n * m * l(n, m, l은 각 점의 개수)이다.
전부 구한 다음에는 그 합을 출력하면 된다.

주요 알고리즘 : 수학, 정수론, 조합론

출처 : GCJ 2008B A2번
*/

int pos[103000][2], cnt[3][3];

long long comb(long long x, int a) {
    if (a == 1) return x;
    else if (a == 2) return (x * (x - 1)) / 2;
    else if (a == 3) return (x * (x - 1) * (x - 2)) / 6;
}

int main(void) {
    int t, n, b, d, m;
    long long a, c, r;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%d %lld %d %lld %d %d %d %d", &n, &a, &b, &c, &d, &pos[0][0], &pos[0][1], &m);
        for (int i = 1; i < n; i++) {
            pos[i][0] = (a * pos[i - 1][0] + b) % m;
            pos[i][1] = (c * pos[i - 1][1] + d) % m;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cnt[i][j] = 0;
        }
        for (int i = 0; i < n; i++) {
            cnt[pos[i][0] % 3][pos[i][1] % 3]++;
        }

        r = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = i; j < 9; j++) {
                for (int k = j; k < 9; k++) {
                    if ((i / 3 + j / 3 + k / 3) % 3 || (i % 3 + j % 3 + k % 3) % 3) continue;
                    if (i == k) r += comb(cnt[i / 3][i % 3], 3);
                    else if (i == j) r += comb(cnt[i / 3][i % 3], 2) * comb(cnt[k / 3][k % 3], 1);
                    else if (j == k) r += comb(cnt[j / 3][j % 3], 2) * comb(cnt[i / 3][i % 3], 1);
                    else r += comb(cnt[i / 3][i % 3], 1) * comb(cnt[j / 3][j % 3], 1) * comb(cnt[k / 3][k % 3], 1);
                }
            }
        }
        printf("Case #%d: %lld\n", tt, r);
    }
    return 0;
}