#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/*
문제 : 후위 표기식으로 표기된 길이 N(N <= 100)의 수식이 주어질 때, M(M <= 100)개의 변수 값의
범위 내에서 나오는 값 가운데 계산 도중 0으로 나누는 경우가 있는 지 구한다.
각 변수는 최대 1번만 쓰이며, 수식은 올바르다. 또한, 수식은 256으로 나눈 나머지로 계산된다.

해결 방법 : 우선 스택을 이용해 각 연산자에 해당하는 위치의 두 항의 위치를 구한다.
그 다음, 수식의 각 항을 보면서 각 항마다 가능한 수를 저장해가면서 다이나믹 프로그래밍을 한다.
수나 변수가 나오면 가능한 범위의 수를 모두 구하고, 연산자가 나오면 앞의 두 항의 모든 경우를
확인하면서, 가능한 수들을 계산해나가는 방식이다. 도중에 0으로 나누는 경우가 생기면 0으로
나누는 경우가 있는 것이다.

주요 알고리즘 : DP, 스택

출처 : JAG 2013S3A B번
*/

char vars[128][32];
int vari[128][2];
char tok[128][32];
int ab[128][2], stk[128], mem[128][256];

int main(void) {
    int m, n, top = 0, res = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d %d", vars[i], &vari[i][0], &vari[i][1]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tok[i]);
        if (tok[i][0] == '+' || tok[i][0] == '-' || tok[i][0] == '*' || tok[i][0] == '/') {
            if (top < 2) return 1;
            ab[i][1] = stk[--top];
            ab[i][0] = stk[--top];
            stk[top++] = i;
        }
        else stk[top++] = i;
    }
    if (top != 1) return 1;
    for (int i = 0; i < n; i++) {
        if (tok[i][0] == '+' || tok[i][0] == '-' || tok[i][0] == '*' || tok[i][0] == '/') {
            for (int j = 0; j < 256; j++) {
                if (!mem[ab[i][0]][j]) continue;
                for (int k = 0; k < 256; k++) {
                    if (!mem[ab[i][1]][k]) continue;
                    if (tok[i][0] == '+') mem[i][(j + k) & 255] = 1;
                    if (tok[i][0] == '-') mem[i][(j + 256 - k) & 255] = 1;
                    if (tok[i][0] == '*') mem[i][(j * k) & 255] = 1;
                    if (tok[i][0] == '/') {
                        if (k == 0) {
                            printf("error\n");
                            return 0;
                        }
                        else mem[i][(j / k) & 255] = 1;
                    }
                }
            }
        }
        else if (isdigit(tok[i][0])) {
            mem[i][strtoll(tok[i], NULL, 10)] = 1;
        }
        else {
            for (int j = 0; j < m; j++) {
                if (!strcmp(vars[j], tok[i])) {
                    for (int k = vari[j][0]; k <= vari[j][1]; k++) mem[i][k] = 1;
                }
            }
        }
    }
    printf("correct\n");
    return 0;
}