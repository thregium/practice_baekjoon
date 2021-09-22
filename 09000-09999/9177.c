#include <stdio.h>
#include <string.h>

/*
문제 : 200자 이하의 문자열 2개와 두 문자열 길이의 합과 같은 길이의 문자열이 주어진다.
이때, 두 문자열을 순서를 바꾸지 않고 섞어서 세 번째 문자열을 만들 수 있는지 구한다.

해결 방법 : 다이나믹 프로그래밍을 통해 해결한다. 세 번째 문자열을 순서대로 확인하며 첫 번째 문자열과 두 번째 문자열에서
마지막으로 본 위치에서 추가 가능한지를 매번 확인해본다. 마지막 문자까지 가능하다면 만들 수 있는 것이고,
불가능하다면 만들 수 없는 것이다.

주요 알고리즘 : DP

출처 : PacNW 2004 B번
*/

char s1[256], s2[256], s3[512];
int mem[256][256];

int main(void) {
    int t, l1, l2;
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\b.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Pacific Northwest\\2004\\sampleInput\\b_t.out", "w", stdout);
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        scanf("%s %s %s", s1, s2, s3);
        l1 = strlen(s1), l2 = strlen(s2);
        mem[0][0] = 1;
        for (int i = 1; i <= l1 + l2; i++) {
            for (int j = 0; j <= l2; j++) {
                if (i - j > l1) continue;
                if (i - j < 0) break;
                if (i - j > 0 && mem[i - j - 1][j] && s1[i - j - 1] == s3[i - 1]) mem[i - j][j] = 1;
                else if (j > 0 && mem[i - j][j - 1] && s2[j - 1] == s3[i - 1]) mem[i - j][j] = 1;
                else mem[i - j][j] = 0;
            }
        }
        printf("Data set %d: %s\n", tt, mem[l1][l2] ? "yes" : "no");
    }
    return 0;
}