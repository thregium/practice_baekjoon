#include <stdio.h>

/*
���� : R * C(R, C <= 100) ũ���� ���ڿ� P�� �� ���簢���� G�� �� ���簢���� �ִ�. �� ���簢���� ũ���
������ ���°� �־����� P�� �Ϻθ� G�� �������� Ȯ���Ѵ�.

�ذ� ��� : ���ڿ��� P�� ������ ����, �� ������ P�� ���̺��� ������ Ȯ���Ѵ�. ���� ��� ������ ���̰�,
�׷��� �ʴٸ� ������ �ʴ� ���̴�.

�ֿ� �˰��� : �ֵ� Ȥ

��ó : ���� 1ȸ 1��
*/

char s[128][128];

int main(void) {
    int r, c, rg, cg, rp, cp, cnt = 0;
    scanf("%d %d", &r, &c);
    scanf("%d %d %d %d", &rg, &cg, &rp, &cp);
    for (int i = 0; i < r; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (s[i][j] == 'P') cnt++;
        }
    }
    if (cnt > rp * cp) return 1;
    printf("%d", cnt < rp * cp);
    return 0;
}