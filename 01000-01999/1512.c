#include <stdio.h>

/*
문제 : 길이 3000 이하의 DNA 문자열이 주어질 때, 이 문자열을 주기 M 이하의 주기문으로 바꾸기 위해
바꿔야 하는 문자의 개수를 구한다.

해결 방법 : 각 길이의 주기문으로 만드는 횟수를 모두 확인한 다음 그 중 최솟값을 구한다.
주기문으로 만드는 횟수는 각 번째의 문자마다 개수를 센 다음,
그 중 가장 많은 것이 아닌 것의 개수를 모두 더하면 최소가 된다.

주요 알고리즘 : 문자열, 브루트 포스, 그리디 알고리즘

출처 : SRM 396D1 1번 // 396D2 2번
*/

char s[3072];
int cnt[3072][4];

int dnatoint(char c) {
    if (c == 'A') return 0;
    else if (c == 'C') return 1;
    else if (c == 'G') return 2;
    else if (c == 'T') return 3;
    else return -1;
}

int main(void) {
    int m, res = 103000, tres, hi, sum;
    scanf("%d", &m);
    scanf("%s", s);
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < 4; k++) cnt[j][k] = 0;
        }
        for (int j = 0; s[j]; j++) {
            cnt[j % i][dnatoint(s[j])]++;
        }
        tres = 0;
        for (int j = 0; j < i; j++) {
            hi = 0, sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += cnt[j][k];
                if (cnt[j][k] > hi) hi = cnt[j][k];
            }
            tres += sum - hi;
        }
        if (tres < res) res = tres;
    }
    printf("%d", res);
    if (res == 103000) return 1;
    return 0;
}