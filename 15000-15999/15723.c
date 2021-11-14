#include <stdio.h>

/*
���� : N(N <= 26)���� ������ �־��� ��, M(M <= 10)���� �������� Ȯ���� ������ ���θ� ����Ѵ�.

�ذ� ��� : �� ������ �������� ����, �÷��̵�-���� �˰����� ������. ���� �� ������ ������ �ִٸ�
���̰�, ���ٸ� ������ �ȴ�.

�ֿ� �˰��� : �׷��� �̷�, �÷��̵�-����

��ó : �߾Ӵ� 2018R 5��
*/

int chk[32][32];

int main(void) {
    int n;
    char c1, c2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c is %c", &c1, &c2);
        chk[c1 - 'a'][c2 - 'a'] = 1;
    }
    
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (chk[i][k] && chk[k][j]) chk[i][j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c is %c", &c1, &c2);
        printf("%c\n", chk[c1 - 'a'][c2 - 'a'] ? 'T' : 'F');
    }
    return 0;
}