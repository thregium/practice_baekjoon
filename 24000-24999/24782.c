#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 11)���� �������� �̷���� ����� ���� �׷����� �ִ� ��ĥ ���� ���� ���Ѵ�.
�������� �̾��� �� ������ �ٸ� ������ ĥ������ �Ѵ�.

�ذ� ��� : �켱 DFS ������� �׷����� Ž���� ����, �� ������ ����� �д�.
�׸��� �� ��ȣ ������� �׷����� �������� ĥ�س����� �ȴ�. ������� ���� �ִ� ���� �� + 1����
ū ������ ĥ�� �ʿ䰡 ���� ������ �̻��� ���� ���� ������ �ٷ� Ž���� �����Ͽ�
�ð��� ���� ������ �� �ִ�.

�ֿ� �˰��� : �׷��� �̷�, ��Ʈ��ŷ

��ó : VTH 2015 H��
*/

char buff[1024];
int ed[16][16], dfsn[16], dfsv[16], color[16];
int dcnt = 0, best = 103000;

void dfs(int x) {
    dfsn[dcnt] = x;
    dfsv[x] = ++dcnt;
    for (int i = 0; i < 16; i++) {
        if (!ed[x][i]) continue;
        if (dfsv[i]) continue;
        dfs(i);
    }
}

void track(int n, int x, int ccnt) {
    if (ccnt >= best) return;
    if (x == n) {
        if (ccnt < best) best = ccnt;
        return;
    }
    int tmp;
    for (int i = 1; i <= ccnt + 1; i++) {
        color[dfsn[x]] = i;
        tmp = 1;
        for (int j = 0; j < n; j++) {
            if (!ed[dfsn[x]][j] || dfsv[j] > x) continue;
            if (color[dfsn[x]] == color[j]) {
                tmp = 0;
                break;
            }
        }
        if (tmp) track(n, x + 1, i > ccnt ? ccnt + 1 : ccnt);
    }
}

int main(void) {
    int n, x;
    char* c;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(buff, 1013, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        c = strtok(buff, " ");
        while (c) {
            x = strtoll(c, NULL, 10);
            ed[i][x] = 1;
            c = strtok(NULL, " ");
        }
    }
    dfs(0);
    track(n, 0, 0);
    if (best > 25) return 1;
    printf("%d", best);
    return 0;
}