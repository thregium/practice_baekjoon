#include <stdio.h>

/*
문제 : 한 팀의 ACM 대회 채점 기록이 주어질 때, 이 팀의 맞은 개수와 페널티를 구한다. 맞은 이후의 제출은 기록되지 않는다.

해결 방법 : 만약 틀린 기록이 주어지면 그 문제의 제출 횟수를 1 늘린다. 맞은 기록이 주어지면(많아야 1번뿐일 것이다.)
지금까지 틀린 횟수 * 20 + 현재까지 흐른 시간을 페널티에 더하고 맞은 문제수를 늘린다.

주요 알고리즘 : 구현

출처 : MidC 2015 A번
*/

char buff[8];
int tries[26];

int main(void) {
    int n, m, s = 0, t = 0;
    char c;
    while (1) {
        scanf("%d", &m);
        if (m < 0) break;
        scanf(" %c %s", &c, buff);
        if (buff[0] == 'w') tries[c - 'A']++;
        else {
            t += tries[c - 'A'] * 20 + m;
            s++;
        }
    }
    printf("%d %d", s, t);
    return 0;
}