#include <stdio.h>
#include <string.h>

/*
문제 : 여우와 다른 동물들의 울음 소리(<= 10100자)가 주어진다. 이때, 다른 동물들의 울음 소리가 각각 주어지면
여우의 울음 소리를 출력한다.

해결 방법 : 전체 울음 소리를 단어 단위로 잘라놓은 다음, 각 단어들을 저장해둔 다른 동물들의 울음 소리와 비교한다.
같은 것이 나오면 넘어가고, 모두와 다른 울음 소리들을 출력하면 된다.

주요 알고리즘 : 문자열, 파싱, 브루트 포스

출처 : CERC 2013 B번
*/

char saying[16384], word[128][128], buff1[128], buff2[128], ani[128][128];

int main(void) {
    int t, n, m;
    char* c;
    //freopen("E:\\PS\\ICPC\\Europe\\CERC\\2013\\b\\b-all.in", "r", stdin);
    scanf("%d", &t);
    getchar();
    for (int tt = 0; tt < t; tt++) {
        fgets(saying, 14400, stdin);
        if (saying[strlen(saying) - 1] == '\n') saying[strlen(saying) - 1] = '\0';

        n = 0;
        c = strtok(saying, " ");
        while (c) {
            strcpy(word[n++], c);
            c = strtok(NULL, " ");
        }
        m = 0;
        while (1) {
            scanf("%s %s %s", buff1, buff2, ani[m++]);
            if (buff2[0] == 'd') {
                m--;
                fgets(buff1, 120, stdin);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!strcmp(word[i], ani[j])) word[i][0] = '\0';
            }
            if (word[i][0] != '\0') printf("%s ", word[i]);
        }
        printf("\n");
    }
    return 0;
}