#include <stdio.h>

/*
문제 : N * M(N, M <= 100) 크기의 그림을 왼쪽으로 90도 회전시킨 그림을 출력한다. 90도 돌렸을 때의 입력과 출력은
문제에 주어진대로 한다. 문제에 주어진 문자들만 입력으로 들어온다.

해결 방법 : 각 칸에 대응하는 문자들을 확인하고, 출력해야 하는 각 칸마다 그 문자에 대응하는 문자를 출력한다.

주요 알고리즘 : 구현

출처 : UCPC 2019예 B번
*/

char s[128][128];
const char* before = ".O-|/\\^<v>";
const char* after = ".O|-\\/<v>^";

int main(void) {
    int n, m, t;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            t = 1;
            for (int k = 0; k < 10; k++) {
                if (s[j][m - i - 1] == before[k]) {
                    printf("%c", after[k]);
                    t = 0;
                }
            }
            if (t) return 1;
        }
        printf("\n");
    }
    return 0;
}