#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� �� ���ĺ����θ� �̷���� ���ڿ��� �־��� ��, �� ���ڿ� ���� �ٸ� ������ ������ ���Ѵ�.
��, ��ҹ��ڸ� �����Ѵ�.

�ذ� ��� : �� ���ڿ��� ���� ���� ��� ���ڿ� ���� �ٸ��� Ȯ���ϰ� �ٸ� ������ ���� ���� �ȴ�.

�ֿ� �˰����� : ���ڿ�

��ó : PA 2007 1-1��
*/

char s1[103000], s2[103000];

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    scanf("%s%s", s1, s2);
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) r++;
    }
    printf("%d", r);
    return 0;
}