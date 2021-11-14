#include <stdio.h>

/*
���� : R(R <= 50000) * C(C <= 10) ũ���� �迭�� '.', '#', 'a'�� �־��� ��, 'a'�� �߷¿� �°� '#'�� ���� ����߸�
���¸� ����Ѵ�. 'a'�� ���ʷ� �׿�������.

�ذ� ��� : 'a'�� ����� �ؿ������� ä��������. �Ź� 'a'�� ���� �� �ִ� ���� �Ʒ� ��ġ�� ���´�.
'a'�� ���̸� �� ��ġ�� ��ĭ ���� �ű��, '#'�� ������ �� ��ġ�� '#' ���� �ű��.

�ֿ� �˰��� : ����, �� ������

��ó : MidC 2016 B�� // SEUSA 2016D2 D��
*/

char orig[51200][16], res[51200][16];

int main(void) {
    int r, c, last;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", orig[i]);
        for (int j = 0; j < c; j++) {
            if (orig[i][j] == '#') res[i][j] = '#';
            else res[i][j] = '.';
        }
    }
    for (int i = 0; i < c; i++) {
        last = r - 1;
        for (int j = r - 1; j >= 0; j--) {
            if (orig[j][i] == '#') last = j - 1;
            else if (orig[j][i] == 'a') res[last--][i] = 'a';
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}