#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)개의 대문자로 이루어진 문자열(<= 10자)이 주어진다.
모든 문자열을 이어붙여 그룹 문자열이 되는 것이 가능한지 확인하고 가능하다면 그 방법을 출력한다.

해결 방법 : 각 문자열의 인접한 문자들을 간선으로 잇는다. 단, 같은 문자인 경우 잇지 않는다.
그 다음, 이 그래프에서 진입/진출 차수가 2 이상인 문자가 있는 지 확인한다. 그러한 문자가 있는 경우
조건을 만족하는 문자열을 만들 수 없다.
그 다음으로는 진입 차수가 0인 문자를 선택하고, 그 문자로 시작한 다음 그 문자로 끝나는 문자열들을 출력한 다음
그 문자로 시작하고 다른 문자로 끝나는 문자열이 있는 경우 출력한다.
그리고 다음 정점을 살핀다. 진출 차수가 0인 문자가 나오면 다시 진입 차수가 0인 문자를 선택하는 것을 반복한다.
이 과정에서 사이클이 있어 모든 문자를 살피지 못하는 경우 조건을 만족하는 문자열을 만들 수 없다.
그 외 경우에는 이 순서대로 모든 문자를 살피며 출력하면 조건을 만족하는 문자열이 된다.

주요 알고리즘 : 그래프 이론, 문자열

출처 : GCJ 2022C A번
*/

int ed[26][26], ins[26], outs[26], vis[26];
char word[128][16], se[128][2], res[1024];

int main(void) {
    int t, n, ok, vcnt, x;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ins[i] = 0;
                outs[i] = 0;
                ed[i][j] = 0;
            }
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%s", word[i]);
            for (int j = 1; word[i][j]; j++) {
                if (word[i][j] != word[i][j - 1]) {
                    ed[word[i][j - 1] - 'A'][word[i][j] - 'A']++;
                    ins[word[i][j] - 'A']++;
                    outs[word[i][j - 1] - 'A']++;
                }
            }
            se[i][0] = word[i][0];
            se[i][1] = word[i][strlen(word[i]) - 1];
        }

        ok = 1;
        for (int i = 0; i < 26; i++) {
            if (ins[i] > 1 || outs[i] > 1) ok = 0;
            vis[i] = 0;
        }
        if (!ok) {
            printf("Case #%d: IMPOSSIBLE\n", tt);
            continue;
        }
        printf("Case #%d: ", tt);

        res[0] = '\0';
        vcnt = 0, x = -1;
        while (vcnt < 26) {
            x = -1;
            for (int i = 0; i < 26; i++) {
                if (vis[i]) continue;
                if (ins[i] == 0) {
                    x = i;
                    break;
                }
            }
            if (x < 0) {
                break;
            }
            ok = 1;
            while (ok) {
                vis[x] = 1;
                vcnt++;
                for (int i = 0; i < n; i++) {
                    if (se[i][0] == x + 'A' && se[i][1] == x + 'A') strcat(res, word[i]);
                }
                ok = 0;
                for (int i = 0; i < n; i++) {
                    if (se[i][0] == x + 'A' && se[i][1] != x + 'A') {
                        strcat(res, word[i]);
                    }
                }
                for (int i = 0; i < 26; i++) {
                    if (ed[x][i]) {
                        x = i;
                        ok = 1;
                        break;
                    }
                }
            }
        }
        if (vcnt == 26) printf("%s", res);
        else printf("IMPOSSIBLE");

        printf("\n");
    }
    return 0;
}