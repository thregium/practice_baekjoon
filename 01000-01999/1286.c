#include <stdio.h>

/*
문제 : N * M(N, M <= 50) 크기의 알파벳 배열이 주어질 때, 이 배열을 2 * 2로 나열하고 난 후, 모든 부분 직사각형들에 대해
각 알파벳의 횟수를 센다면, 각 알파벳의 등장 횟수를 출력한다.

해결 방법 : 알파벳 배열을 2 * 2로 나열한 후 각 위치의 알파벳들마다 해당 위치를 포함하는 부분 직사각형의 개수를 센다.
이는 상하좌우로 남는 칸 수 + 1을 전부 곱한 값과 같다. 이를 해당 알파벳마다 더해나가면 된다.

주요 알고리즘 : 수학, 조합론

출처 : SRM 429 D1A / D2B
*/

char s[128][128];
long long cnt[26];

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m * 2; j++) {
            s[i][j] = s[i % n][j % m];
        }
    }
    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m * 2; j++) {
            cnt[s[i][j] - 'A'] += (i + 1) * (n * 2 - i) * (j + 1) * (m * 2 - j);
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%lld\n", cnt[i]);
    }
    return 0;
}