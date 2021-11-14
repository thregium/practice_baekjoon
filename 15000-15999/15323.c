#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
문제 : K(K <= 100000)개의 문자열(소문자, 21자)이 주어지고, N(N <= 100000)개의 소문자가 주어진다.
각 문자가 주어질 때 마다 그 문자로 시작하는 문자열 가운데 사전순으로 그 문자가 주어진 번째의 문자열을 구한다.

해결 방법 : 각 문자열을 입력받은 다음, 첫 글자별로 분류하고 각각 정렬한다. 그 후로는 각 문자별로 개수와 등장 횟수를
저장해두고 문자가 주어질 때 마다 그때의 단어를 출력하고 등장 횟수를 바꾸면 된다.

주요 알고리즘 : 문자열, 정렬

출처 : COCI 17/18#2 2번
*/

char buff[24], s2[26][103000][24];
int cnt[26], pos[26];

int main(void) {
    int k, n;
    char c;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) {
        scanf("%s", buff);
        strcpy(s2[buff[0] - 'a'][cnt[buff[0] - 'a']++], buff);
    }
    for (int i = 0; i < 26; i++) {
        qsort(s2[i], cnt[i], sizeof(char) * 24, strcmp);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %c", &c);
        printf("%s\n", s2[c - 'a'][pos[c - 'a']]);
        pos[c - 'a'] = (pos[c - 'a'] + 1) % cnt[c - 'a'];
    }
    return 0;
}