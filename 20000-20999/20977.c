#include <stdio.h>

/*
���� : N(N <= 100)���� 'J', 'O', 'I'�� �̷���� ���ڿ��� 'J' ���ķ� 'O', �� �ڷ� 'I'�� ������
������ �ٲپ� ����Ѵ�.

�ذ� ��� : 'J', 'O', 'I'�� ������ ���� �� ��, �� ���ڸ� 'J', 'O', 'I' ������� ������ ���� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, ����, ����

��ó : JOI 2021��1 1-2��
*/

char s[128];

int main(void) {
    int n, jc = 0, oc = 0, ic = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'J') jc++;
        else if (s[i] == 'O') oc++;
        else ic++;
    }
    for (int i = 0; i < jc; i++) printf("J");
    for (int i = 0; i < oc; i++) printf("O");
    for (int i = 0; i < ic; i++) printf("I");
    printf("\n");
    return 0;
}