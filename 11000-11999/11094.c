#include <stdio.h>
#include <string.h>

/*
���� : �־��� N(N <= 1000)���� ���� 100 ������ ���ڿ� �� Simon says�� �����ϴ� ��� ���ڿ��� Simon says ���� �κ��� ����Ѵ�.
�������� �����ϰų� ������ ���ڿ��� ���� Simon says�� �����ϴ� ���ڿ��� ���� 1�� �̻��� �ܾ �� �ִ�.

�ذ� ��� : strstr�� ���� Simon says�� �� �տ� ������ ��츦 ã�� ��, �� ��� 10��° ����(Simon says) ���� ���ڸ� ����Ѵ�.

�ֿ� �˰��� : ���ڿ�

��ó : NAQ 2015 I�� / 2020 F��
*/

char s[128];

int main(void) {
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        fgets(s, 120, stdin);
        if (strstr(s, "Simon says") == s) {
            printf("%s", s + 10);
        }
    }
    return 0;
}