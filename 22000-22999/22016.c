#include <stdio.h>
#include <ctype.h>

/*
���� : N(N <= 100)���� ���ڿ����� K��° ������ ������ ��ҹ��ڸ� ������Ų��.

�ذ� ��� : K��°���� ���ڸ� ���Ǹ� �빮�ڶ�� �ҹ��ڷ� �ٲٰ� �ҹ��ڶ�� �빮�ڷ� �ٲ۴�.

�ֿ� �˰��� : ���ڿ�, ����

��ó : JOIG 2021 2��
*/

char t[128];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", t);
    for (int i = k - 1; t[i]; i++) {
        if (isupper(t[i])) t[i] = tolower(t[i]);
        else t[i] = toupper(t[i]);
    }
    printf("%s", t);
    return 0;
}