#include <stdio.h>
#include <string.h>

/*
���� : Z(Z <= 100)���� ���� 100 ������ ���ڿ��� N_i, C_i(C_i <= 12)�� �־��� ��, (N_i + 1)��° ������ �κ� ���ڿ���
���� ���ڿ��� ���̴� ���� C_iȸ �ݺ��� ����� ���� ����Ѵ�.

�ذ� ��� : ���ڿ����� strcpy �Լ��� n�� �ε����� �����͸� �Է��ϸ� �ش� (N_i + 1)�� ������ �κ� ���ڿ��� �߰��ȴ�.
���⿡ ���� ���ڿ��� strcat�ϸ� ���� ���ڿ��� ������, �̸� C_iȸ �ݺ��ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : USACO 2011O B4��
*/

char str[16][524288];

int main(void) {
    int z, n, c;
    scanf("%d", &z);
    for (int zz = 0; zz < z; zz++) {
        scanf("%d %d %s", &n, &c, str[0]);
        for (int i = 1; i <= c; i++) {
            strcpy(str[i], &str[i - 1][n]);
            strcat(str[i], str[i - 1]);
        }
        printf("%s\n", str[c]);
    }
    return 0;
}