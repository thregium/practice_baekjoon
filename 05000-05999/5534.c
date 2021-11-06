#include <stdio.h>
#include <string.h>

/*
문제 : 길이 25 이하의 소문자로 이루어진 첫 문자열이 주어지고, 이후로 N(N <= 100)개의 길이 100 이하의 소문자로 이루어진
문자열들이 주어진다. 이때, 이후 주어지는 문자열들 중 글자들을 지워서 첫 문자열을 만들 수 있는 문자열의 개수를 구한다.
단, 문자열을 만들 때 남아있는 문자열들은 간격이 일정해야 한다.

해결 방법 : 각 문자열을 확인할 때 마다 가능한 모든 시작점과 간격마다 문자열을 확인해본다. 그때의 문자열이
첫 문자열과 일치하는 경우를 모두 구하면 된다. 문자열 길이를 벗어나는 경우와 탈출 설정에 유의해야 한다.

주요 알고리즘 : 브루트 포스, 문자열

출처 : JOI 2013예 3번
*/

char bd[32], s[256];

int main(void) {
    int n, bl, l, ok = 0, r = 0;
    scanf("%d", &n);
    scanf("%s", bd);
    bl = strlen(bd);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        l = strlen(s);
        ok = 0;
        for (int j = 0; j < l; j++) {
            for (int k = 1; k < l; k++) {
                if (j + (bl - 1) * k >= l) break;
                ok = 1;
                for (int ii = 0; ii < bl; ii++) {
                    if (j + ii * k >= l || bd[ii] != s[j + ii * k]) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) break;
        }
        r += ok;
    }
    printf("%d", r);
    return 0;
}