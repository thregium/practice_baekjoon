#include <stdio.h>
#include <string.h>

/*
���� : �� ���� ������� ������ �� �������� �̸��� �־��� ��, �� ���� ������ ���� ã�´�.

�ذ� ��� : ������ ���� ���� �����Ƿ� ���� �̸��� ���ذ��� ã�Ƶ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : AIPO 2017P 2��
*/

char sa[32][32], sb[32][32], t[32];

int main(void) {
    int a, b, g, f, ta = 0, tb = 0;
    scanf("%d %d %d", &a, &b, &g);
    for (int i = 0; i < a; i++) {
        scanf("%s", sa[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%s", sb[i]);
    }
    for (int i = 0; i < g; i++) {
        scanf("%s", t);
        f = 0;
        for (int j = 0; j < a; j++) {
            if (!f && !strcmp(t, sa[j])) f = 1;
        }
        for (int j = 0; j < b; j++) {
            if (!f && !strcmp(t, sb[j])) f = 2;
        }
        if (f == 1) ta++;
        if (f == 2) tb++;
    }
    printf("%s", ta > tb ? "A" : ta == tb ? "TIE" : "B");
    return 0;
}