#include <stdio.h>

/*
���� : ���� N(N <= 100000)�� 2�� e�� �̷���� ���ڿ��� �־��� ��, 2�� e�� ������ ���Ѵ�.

�ذ� ��� : ��� ���ڵ��� ���캸�� 2�� e�� ������ ���� �ȴ�.

�ֿ� �˰��� : ����
*/

char s[103000];

int main(void) {
    int n, t = 0, e = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == '2') t++;
        else e++;
    }
    if (t == e) printf("yee");
    else if (t > e) printf("2");
    else printf("e");
    return 0;
}