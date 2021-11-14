#include <stdio.h>

/*
문제 : 8자리의 두 수가 주어질 때, 문제에서 주어진 방법대로 두 수의 궁합을 구한다.

해결 방법 : 문자열 형태로 입력받은 다음, 각 자리 수를 교차해 놓고, 앞의 수를 기준으로 인접한 두 수의 합을
10으로 나눈 수를 적용하는 것을 반복한다. 14회 반복하면 두 자리만 남게 된다.

주요 알고리즘 : 구현, DP

출처 : 중앙대 2019N B번
*/

char s1[16], s2[16], cat[32];
int mem[16][16];

int main(void) {
    int a, b;
    scanf("%s%s", s1, s2);
    for (int i = 0; i < 8; i++) {
        cat[i * 2] = s1[i];
        cat[i * 2 + 1] = s2[i];
    }
    for (int i = 0; i < 16; i++) {
        mem[0][i] = cat[i] - '0';
    }
    for (int i = 1; i <= 14; i++) {
        for (int j = 0; i + j < 16; j++) {
            mem[i][j] = (mem[i - 1][j] + mem[i - 1][j + 1]) % 10;
        }
    }
    printf("%d%d", mem[14][0], mem[14][1]);
    return 0;
}