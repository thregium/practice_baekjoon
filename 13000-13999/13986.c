#include <stdio.h>

/*
���� : R(R <= 64) * C(C <= 64) ũ���� �迭�� '.', '#', 'a'�� �־��� ��, 'a'�� �߷¿� �°� '#'�� ���� ����߸�
���¸� ����Ѵ�. 'a'�� ���ʷ� �׿�������.

�ذ� ��� : 'a'�� ����� �ؿ������� ä��������. �Ź� 'a'�� ���� �� �ִ� ���� �Ʒ� ��ġ�� ���´�.
'a'�� ���̸� �� ��ġ�� ��ĭ ���� �ű��, '#'�� ������ �� ��ġ�� '#' ���� �ű��.

�ֿ� �˰��� : ����, �� ������

��ó : PacNW 2016 S��
*/

char orig[64][64], res[64][64];

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
            else if (orig[j][i] == 'o') res[last--][i] = 'o';
        }
    }
    for (int i = 0; i < r; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}