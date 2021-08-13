#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 1000)개의 9자로 된 코드들이 주어질 때, 원본 패턴과 일치하는 코드의 수와 그러한 코드들을 구한다.
원본 패턴은 *과 코드의 문자들로 주어지고, *인 칸에는 어떠한 문자가 와도 상관없다.

해결 방법 : 각 코드를 입력받으며 패턴과 일치하는지 확인한다. 모든 문자가 원본 패턴이 * 또는 원본 패턴과 일치하면 된다.
패턴과 일치하는 코드들을 미리 저장해둔 다음 일치하는 수의 개수를 출력하고 그 코드들도 출력하면 된다.

주요 알고리즘 : 구현, 문자열

출처 : NEERC 2013 F번
*/

char cd[16], buff[16], mat[1024][16];

int main(void) {
    int n, r = 0, t;
    scanf("%s", cd);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", buff);
        t = 1;
        for (int j = 0; j < 9; j++) {
            if (cd[j] == '*' || cd[j] == buff[j]) continue;
            else t = 0;
        }
        if (t) {
            strcpy(mat[r++], buff);
        }
    }
    printf("%d\n", r);
    for (int i = 0; i < r; i++) {
        printf("%s\n", mat[i]);
    }
    return 0;
}