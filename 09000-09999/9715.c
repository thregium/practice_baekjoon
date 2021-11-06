#include <stdio.h>
#include <ctype.h>

/*
���� : R * C(R, C <= 50) ������ �� ĭ���� 1 * 1 * 1 ũ���� ����� 0 ~ 9�� �׾Ҵ�. �̶�, ��ü ����� ������ �����
�ѳ��̸� ���Ѵ�.

�ذ� ��� : �� ����� �ѳ��̴� ������� �ʾҴٸ� 6�̴�. ��� �� * 6���� ���Ḷ�� 2�� ���ָ� ���� �ȴ�.
�ߺ��� �ذ��ϱ� ���� ������, �Ʒ��ʰ��� Ȯ���ϰ�, ���Ʒ��� �̾����� ��쿡�� 0 ó���� �������ָ� �ȴ�.

�ֿ� �˰��� : ����, 3���� ������

��ó : Khwarizmi 2011 C��
*/

char mat[64][64];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int t, r, c, a;
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &r, &c);
        for (int i = 0; i < r; i++) {
            scanf("%s", mat[i]);
        }
        a = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == '0') continue; //0�� ���� �Ű澵 �ʿ䰡 ����.
                a += (mat[i][j] - '0') * 4 + 2; //���Ʒ� ��ϰ��� ������ �ٷ� ó���ϸ� �⺻���� �ִ´�.
                if (isdigit(mat[i][j + 1])) a -= small(mat[i][j + 1] - '0', mat[i][j] - '0') * 2; //������ ��ϰ��� ����
                if (isdigit(mat[i + 1][j])) a -= small(mat[i + 1][j] - '0', mat[i][j] - '0') * 2; //�� ��ϰ��� ����
                mat[i][j] = '\0';
            }
        }
        printf("%d\n", a);
    }
    return 0;
}