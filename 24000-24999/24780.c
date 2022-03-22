#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
���� : ������ �� �������� ������� �������� �־��� ��, K�� �������� ������� �������� ����� ���Ѵ�.
�� ������ ��ȣ�� 100 ������ �ڿ����̸�, �������� ���� �� �ִ�.
�������� �ٽ� �������� ���� ����.

�ذ� ��� : Ʈ�� ������ �׷����̹Ƿ� �Ľ��� �� ��Ʈ ������ ã��, �� ��ġ�� ���� �����
DFS�� ���� ã�Ƴ� ���� ��θ� ����ϸ� �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, DFS, Ʈ��, �Ľ�

��ó : VTH 2015 F��
*/

char buff[1024];
int branch[128][128], chk[128], path[128];
int root = -1;

void dfs(int x, int p, int d) {
    if (x == root) {
        for (int i = 0; i < d; i++) {
            printf("%d ", path[i]);
        }
        return;
    }
    for (int i = 1; i <= branch[x][0]; i++) {
        if (branch[x][i] == p) continue;
        path[d] = branch[x][i];
        dfs(branch[x][i], x, d + 1);
    }
}

int main(void) {
    int k, a, b;
    char* c;
    scanf("%d\n", &k);
    while (1) {
        fgets(buff, 103000, stdin);
        if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
        a = strtoll(strtok(buff, " "), NULL, 10);
        if (a < 0) break;
        chk[a] = 1;
        while (1) {
            c = strtok(NULL, " ");
            if (!c) break;
            b = strtoll(c, NULL, 10);
            branch[b][++branch[b][0]] = a;
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (branch[i][0] == 0 && chk[i]) {
            if (root >= 0) return 1;
            root = i;
        }
    }
    path[0] = k;
    dfs(k, -1, 1);
    return 0;
}