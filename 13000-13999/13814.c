#include <stdio.h>
#include <string.h>

/*
문제 : 80000자 이하의 수가 주어질 때, 이 수에서 볼 수 있는 11의 배수인 부분 문자열의 개수를 구한다.
단, 0으로 시작하는 경우는 세지 않는다.

해결 방법 : 맨 앞에서부터 보면서 그 수에서 끝나는 나머지가 X인 부분 문자열의 개수를
다이나믹 프로그래밍을 통해 구한다. 매 숫자마다 0이 아닌 경우 그 숫자를 더해 나가고,
앞의 수에서 1자씩을 더한 것을 계산해 나가면 된다. 답은 나머지가 0인 모든 부분 문자열 개수의 합이다.

주요 알고리즘 : DP, 정수론

출처 : JAG 2009P H번
*/

char s[103000];
int mem[103000][11];

int main(void) {
    int l, r;
    while (1) {
        scanf("%s", s + 1);
        if (s[1] == '0') break;
        l = strlen(s + 1);
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j < 11; j++) {
                mem[i][(j * 10 + (s[i] - '0')) % 11] = mem[i - 1][j];
            }
            if (s[i] != '0') mem[i][s[i] - '0']++;
        }
        r = 0;
        for (int i = 1; i <= l; i++) {
            r += mem[i][0];
            for (int j = 0; j < 11; j++) mem[i][j] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}