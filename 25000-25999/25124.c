#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 100)���� �빮�ڷ� �̷���� ���ڿ�(<= 10��)�� �־�����.
��� ���ڿ��� �̾�ٿ� �׷� ���ڿ��� �Ǵ� ���� �������� Ȯ���ϰ� �����ϴٸ� �� ����� ����Ѵ�.

�ذ� ��� : �� ���ڿ��� ������ ���ڵ��� �������� �մ´�. ��, ���� ������ ��� ���� �ʴ´�.
�� ����, �� �׷������� ����/���� ������ 2 �̻��� ���ڰ� �ִ� �� Ȯ���Ѵ�. �׷��� ���ڰ� �ִ� ���
������ �����ϴ� ���ڿ��� ���� �� ����.
�� �������δ� ���� ������ 0�� ���ڸ� �����ϰ�, �� ���ڷ� ������ ���� �� ���ڷ� ������ ���ڿ����� ����� ����
�� ���ڷ� �����ϰ� �ٸ� ���ڷ� ������ ���ڿ��� �ִ� ��� ����Ѵ�.
�׸��� ���� ������ ���ɴ�. ���� ������ 0�� ���ڰ� ������ �ٽ� ���� ������ 0�� ���ڸ� �����ϴ� ���� �ݺ��Ѵ�.
�� �������� ����Ŭ�� �־� ��� ���ڸ� ������ ���ϴ� ��� ������ �����ϴ� ���ڿ��� ���� �� ����.
�� �� ��쿡�� �� ������� ��� ���ڸ� ���Ǹ� ����ϸ� ������ �����ϴ� ���ڿ��� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, ���ڿ�

��ó : GCJ 2022C A��
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