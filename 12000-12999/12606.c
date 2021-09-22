#include <stdio.h>
#include <string.h>

/*
문제 : 1000자 이하의 문자열이 주어진다. 각 문자열은 알파벳만으로 구성된 단어들로 이루어져 있다.
단어 사이에는 공백 1개씩이 들어간다. 이때, 각 단어들을 뒤집은 문장을 출력한다.

해결 방법 : strtok 함수를 통해 각 단어를 분리해낸 후 각각 저장한다.
그 다음, 저장한 단어를 역순으로 불러오면 된다.

주요 알고리즘 : 문자열, 파싱

출처 : GCJ 2010A QB2번
*/

char s[1024], s2[1024][1024];

int main(void) {
    int n, p;
    char* t;
    scanf("%d\n", &n);
    for (int nn = 1; nn <= n; nn++) {
        fgets(s, 1013, stdin);
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        p = 0;
        while (1) {
            if (p == 0) t = strtok(s, " ");
            else t = strtok(NULL, " ");
            if (t == NULL) break;
            strcpy(s2[p], t);
            p++;
        }
        printf("Case #%d: ", nn);
        for (int i = p - 1; i >= 0; i--) {
            printf("%s", s2[i]);
            if (i > 0) printf(" ");
        }
        printf("\n");
    }
    return 0;
}