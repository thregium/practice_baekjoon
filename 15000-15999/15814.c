#include <stdio.h>

/*
���� : ���ڿ����� ���� �۾��� T(T <= 50)ȸ ���� ��, ���ڿ��� ����Ѵ�.
A��° ���ڿ� B��° ���ڸ� �ٲ۴�. ��, 0��°���� �����ϴ� ������ �����ϰ�, A�� B�� ���ڿ��� ���̺��� �۴�.

�ذ� ��� : ���ڿ��� �迭ó�� ���� ���ڳ��� �ٲٴ� ���� �ݺ��ϸ� �ȴ�.

�ֿ� �˰����� : ���ڿ�, ����

��ó : ���ϴ� 2018 F��
*/

char s[128];

int main(void) {
    int t, a, b;
    char c;
    scanf("%s", s);
    scanf("%d", &t);
    for (int tt = 0; tt < t; tt++) {
        scanf("%d %d", &a, &b);
        c = s[b];
        s[b] = s[a];
        s[a] = c;
    }
    printf("%s", s);
    return 0;
}