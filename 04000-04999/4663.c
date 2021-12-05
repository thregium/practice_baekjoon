#include <stdio.h>
#include <string.h>

/*
���� : �־��� ���ڿ� ������ �������� ǥ�� �����. ù �ٿ��� �� ���� ���� �����,
���� �ٵ鿡�� �� ĭ�� �����Ͱ� �־�����.

�ذ� ��� : ���� �� ĭ�� �����͸� �Ľ��Ͽ� ���� �����Ѵ�. �� ��, �� ������ ���̿� �������� ���� ����,
ǥ�� Ʋ�� ��� �迭�� �����Ѵ�. �� �� ���ڵ��� ��� �迭�� �߰��ϰ�, �����͸� �����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���ڿ�, �Ľ�

��ó : MidC 2000 F��
*/

char buff[128], layout[32], data[32][32][128], res[32][128];
int len[32], start[32];

void cpyto(int x, int y, int len, char* from, char layout) {
    //�ش� ������ �־��� ���� ��Ĵ�� ���ڿ��� �߰��Ѵ�.
    int l = strlen(from), s = 0;
    if (layout == '<') s = y + 2;
    else if (layout == '>') s = y + len - l + 2;
    else if (layout == '=') {
        s = y + ((len - l) >> 1) + 2;
    }
    else return;
    for (int i = 0; from[i]; i++) {
        res[x][s + i] = from[i];
    }
}

int main(void) {
    int n, m;
    char* c;
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\fab\\fab.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\North America\\Mid Central\\mcpc2000\\fab\\fab_t.out", "w", stdout);
    fgets(buff, 100, stdin);
    strcpy(layout, buff);
    if (layout[strlen(layout) - 1] == '\n') layout[strlen(layout) - 1] = '\0';
    while (1) {
        n = 0;
        m = strlen(layout);
        while (1) {
            //�־��� �����͸� �Ľ��Ѵ�.
            fgets(buff, 100, stdin);
            if (buff[strlen(buff) - 1] == '\n') buff[strlen(buff) - 1] = '\0';
            if (strchr(buff, '<') || strchr(buff, '=') || strchr(buff, '>') || strchr(buff, '*')) break;
            c = strtok(buff, "&");
            strcpy(data[n][0], c);
            for (int i = 1; i < m; i++) {
                c = strtok(NULL, "&");
                strcpy(data[n][i], c);
            }
            n++;
        }
        for (int i = 0; i < m; i++) {
            //�� ���� ���̸� ���Ѵ�.
            len[i] = 0;
            for (int j = 0; j < n; j++) {
                if (strlen(data[j][i]) > len[i]) len[i] = strlen(data[j][i]);
            }
        }
        start[0] = 0;
        for (int i = 1; i <= m; i++) start[i] = start[i - 1] + len[i - 1] + 3;
        
        for (int i = 0; i <= n + 2; i++) {
            //ǥ�� Ʋ�� ��´�.
            for (int j = 0; j <= start[m]; j++) {
                if ((i == 0 && j == 0) || (i == n + 2 && j == 0) ||
                    (i == 0 && j == start[m]) || (i == n + 2 && j == start[m])) res[i][j] = '@';
                else if (j == 0 || j == start[m]) res[i][j] = '|';
                else if (i == 0 || i == 2 || i == n + 2) res[i][j] = '-';
                else res[i][j] = ' ';
            }
            res[i][start[m] + 1] = '\0';
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j <= n + 1; j++) res[j][start[i]] = '|';
            res[2][start[i]] = '+';
        }

        for (int i = 0; i < m; i++) {
            //ǥ�� �����͸� �߰��Ѵ�.
            cpyto(1, start[i], len[i], data[0][i], layout[i]);
            for (int j = 1; j < n; j++) {
                cpyto(j + 2, start[i], len[i], data[j][i], layout[i]);
            }
        }

        for (int i = 0; i <= n + 2; i++) {
            //ǥ�� ����Ѵ�.
            printf("%s\n", res[i]);
        }
        if (!strcmp(buff, "*")) break;
        strcpy(layout, buff);
    }
    return 0;
}