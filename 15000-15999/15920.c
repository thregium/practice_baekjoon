#include <stdio.h>

/*
���� : ���ο� ������ ���� ��, �־��� N(N <= 10)ȸ�� ���� �� ����ŷ�� �� �� ġ�� �Ǵ��� ���Ѵ�.

�ذ� ��� : ������ �־������ �����Ѵ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : ���� 2ȸ E��
*/

char s[16];

int main(void) {
    int n, t = 1, p = 0;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') t++;
        else if (s[i] == 'P') {
            if (t == 2) p = 2;
            else if (t == 1 && p == 0) p = 1;
            else if (t == 1 && p == 1) p = 0;
            else if (t <= 1) return 1;
        }
        else return 2;
    }
    if (t >= 3) {
        if (p == 2) printf("6");
        else if (p == 1) printf("1");
        else if (p == 0) printf("5");
        else return 3;
    }
    else printf("0");
    return 0;
}