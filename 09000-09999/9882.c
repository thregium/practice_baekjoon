#include <stdio.h>
#define FOUT 0
#define INF 1012345678
#define scanf(s, ...) fscanf(fi, s, __VA_ARGS__)
#define printf(s, ...) fprintf(fo, s, __VA_ARGS__)

/*
���� : 12���� 4���� ������ �������� �Ѵ�. �� ���� �ɷ�ġ ���� ���� �յ��ϰ�(���� �ɷ�ġ ���� ���� ���� ���� ���� �� ����
���̰� ���� ������) ���� ��, ���� �ɷ�ġ ���� ���� ���� ���� ���� ������ �ּڰ��� ���Ѵ�.

�ذ� ��� : ������ ��� ��쿡 ���� ���� ������ ����, ������ �ɷ�ġ ���� ���� ��� ���� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����, ��Ʈ��ŷ

��ó : USACO 2014J B3��
*/

int skill[16], chk[16], team[4];
int res = INF;

void track(int x, int y) {
    if (x == y) {
        int l = INF, h = 0;
        for (int i = 0; i < x; i++) {
            if (team[i] < l) l = team[i];
            if (team[i] > h) h = team[i];
        }
        if (h - l < res) res = h - l;
        return;
    }

    for (int i = 0; i < 12; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        for (int j = i + 1; j < 12; j++) {
            if (chk[j]) continue;
            chk[j] = 1;
            for (int k = j + 1; k < 12; k++) {
                if (chk[k]) continue;
                chk[k] = 1;
                team[y] = skill[i] + skill[j] + skill[k];
                track(x, y + 1);
                chk[k] = 0;
            }
            chk[j] = 0;
        }
        chk[i] = 0;
    }
}

int main(void) {
    FILE* fi = stdin;
    FILE* fo = stdout;
    if (FOUT) {
        fi = fopen("bteams.in", "r");
        fo = fopen("bteams.out", "w");
    }
    for (int i = 0; i < 12; i++) {
        scanf("%d", &skill[i]);
    }
    track(4, 0);
    printf("%d", res);
    return 0;
}