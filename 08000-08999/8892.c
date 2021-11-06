#include <stdio.h>
#include <string.h>

/*
문제 : K(K <= 100)개의 단어 가운데 서로 다른(실제로 같더라도 다른 위치라면 다른 것이다) 두 단어를 합쳐서
만들 수 있는 팰린드롬 가운데 아무거나 하나를 출력한다. 없다면 0을 출력한다. 단어의 길이 총 합은 10000 이하다.

해결 방법 : 단어의 길이 총 합이 크지 않기 때문에 모든 단어를 직접 합쳐보며 직접 팰린드롬 여부를 확인해보면 된다.
팰린드롬인 문자열이 나오면 바로 반복문을 빠져나와 그 문자열을 출력하고, 끝까지 나오지 않는 경우 0을 출력한다.

주요 알고리즘 : 브루트 포스, 문자열

출처 : Daejeon 2012 E번
*/

char word[128][10240], buff[20480];

int main(void) {
    int t, k, l, r, tmp;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d", &k);
        for (int i = 0; i < k; i++) {
            scanf("%s", word[i]);
        }
        r = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                sprintf(buff, "%s%s", word[i], word[j]);
                l = strlen(buff);
                tmp = 1;
                for (int ii = 0, jj = l - 1; ii <= jj; ii++, jj--) {
                    if (buff[ii] != buff[jj]) {
                        tmp = 0;
                        break;
                    }
                }
                if (tmp) {
                    r = 1;
                    break;
                }
            }
            if (r) break;
        }
        printf("%s\n", r ? buff : "0");
    }
    return 0;
}