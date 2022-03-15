#include <stdio.h>
#include <string.h>
#define MOD 1000000007

/*
문제 : 50자 이하의 같은 길이 문자열 A, B, C가 주어진다. 각 문자열은 숫자와 '?'로 이루어져 있다.
이때, A + B = C를 만족하게 하도록 '?'를 숫자로 바꾸는 방법의 가짓수를 구한다.
단, 맨 앞의 '?'는 0으로 바꿀 수 없고, 주어지는 문자열의 맨 앞 글자도 0이 아니다.

해결 방법 : 맨 뒤 자리부터 올림이 있을 때와 없을 때의 가짓수를 저장해가며
다이나믹 프로그래밍을 이용해  답을 풀어나간다. A, B, C의 각 자리에 들어갈 숫자들을 결정하고
가능한 경우 올림 여부를 확인해 가짓수를 하나씩 찾아나가면 된다.
그 후 맨 앞 자리의 올림이 없을 때 값을 출력한다.

주요 알고리즘 : DP, 수학

출처 : JAG 2013P B번
*/

char a[64], b[64], c[64];
int mem[64][2];

int main(void) {
    while (1) {
        scanf("%s", a + 1);
        if (!strcmp(a + 1, "0")) break;
        scanf("%s%s", b + 1, c + 1);
        mem[strlen(c + 1) + 1][0] = 1;
        mem[strlen(c + 1) + 1][1] = 0;
        for (int i = strlen(c + 1); i > 0; i--) {
            mem[i][0] = 0;
            mem[i][1] = 0;
            for (int x = !(i - 1); x <= 9; x++) {
                if (a[i] != '?' && a[i] - '0' != x) continue;
                for (int y = !(i - 1); y <= 9; y++) {
                    if (b[i] != '?' && b[i] - '0' != y) continue;
                    for (int z = !(i - 1); z <= 9; z++) {
                        if (c[i] != '?' && c[i] - '0' != z) continue;
                        if ((x + y) % 10 == z) {
                            if (x + y >= 10) mem[i][1] = (mem[i][1] + mem[i + 1][0]) % MOD;
                            else mem[i][0] = (mem[i][0] + mem[i + 1][0]) % MOD;
                        }
                        else if ((x + y + 1) % 10 == z) {
                            if (x + y + 1 >= 10) mem[i][1] = (mem[i][1] + mem[i + 1][1]) % MOD;
                            else mem[i][0] = (mem[i][0] + mem[i + 1][1]) % MOD;
                        }
                    }
                }
            }
        }
        printf("%d\n", mem[1][0]);
    }
    return 0;
}