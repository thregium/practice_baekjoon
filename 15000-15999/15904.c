#include <stdio.h>

/*
���� : �־��� 1000�� ������ ���ڿ��� ���� UCPC�� �κ� �迭�� ������ ���θ� ���Ѵ�.

�ذ� ��� : ���ۺ��� U�� �ִ��� Ȯ���ϰ�, U�� �ִٸ� �ٽ� C�� �ִ��� Ȯ���ϰ�, P, C�� ���� ������� Ȯ���غ��� �ȴ�.

�ֿ� �˰��� : �׸��� �˰���, ���ڿ�

��ó : UCPC 2018�� G��
*/

char s[1024];
char* ucpc = "UCPC#";

int main(void) {
    int p = 0;
    fgets(s, 1010, stdin);
    for (int i = 0; s[i]; i++) {
        if (s[i] == ucpc[p]) p++;
    }
    if (p >= 4) printf("I love UCPC");
    else printf("I hate UCPC");
    return 0;
}