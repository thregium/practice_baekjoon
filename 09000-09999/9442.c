#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
문제 : N(N <= 20)개의 길이 30 이하의 대문자로 이루어진 문자열을 정렬하되, 주어진 순열의 순서대로 우선순위를 바꾸어
정렬한 결과를 출력한다.

해결 방법 : 주어진 순열의 역방향으로 된 순열을 만든 다음, 해당 순열을 통해 문자열을 바꾸어서 해당하는 문자열을
정렬한다. 그 다음, 주어진 순열대로 다시 문자열을 바꾸어 출력하면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : MidC 2013 H번
*/

char perm[32], permr[32], word[32][32];

int main(void) {
    int n;
    for (int tt = 1;; tt++) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", perm);
        for (int i = 0; i < 26; i++) permr[perm[i] - 'A'] = 'A' + i;
        for (int i = 0; i < n; i++) {
            scanf("%s", word[i]);
            for (int j = 0; word[i][j]; j++) word[i][j] = permr[word[i][j]- 'A'];
        }
        qsort(word, n, sizeof(char) * 32, strcmp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; word[i][j]; j++) word[i][j] = perm[word[i][j] - 'A'];
        }
        printf("year %d\n", tt);
        for (int i = 0; i < n; i++) {
            printf("%s\n", word[i]);
        }
    }
    return 0;
}