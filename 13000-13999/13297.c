#include <stdio.h>
#include <string.h>

/*
���� : 10^100 ������ ������ �־��� ��, �� ���� �� �ڸ� ������ ���Ѵ�.

�ذ� ��� : ���� ���ڿ��� �Է¹����� ���ڿ��� ���̰� ���� ���̰� �ȴ�.

�ֿ� �˰��� : ���ڿ�

��ó : NAQ 2016 J��
*/

char s[128];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        printf("%d\n", strlen(s));
    }
    return 0;
}
