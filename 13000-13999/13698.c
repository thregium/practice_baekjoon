#include <stdio.h>

/*
���� : 4���� �ſ� �� 2���� �ְ�, ���� �־��� ������ �°� �ű� ��, �������� �� ���� �ִ� ��ġ�� ���Ѵ�.

�ذ� ��� : �־��� ������ �°� ������ ���� �Űܺ���.

�ֿ� �˰��� : ����, �ùķ��̼�, ���̽� ��ũ?

��ó : ȫ�ʹ� 2016 A��
*/

char s[256];

int main(void) {
    int b = 4, l = 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (s[i] == 'A') {
            if (b == 1) b = 2;
            else if (b == 2) b = 1;
            if (l == 1) l = 2;
            else if (l == 2) l = 1;
        }
        else if (s[i] == 'B') {
            if (b == 1) b = 3;
            else if (b == 3) b = 1;
            if (l == 1) l = 3;
            else if (l == 3) l = 1;
        }
        else if (s[i] == 'C') {
            if (b == 1) b = 4;
            else if (b == 4) b = 1;
            if (l == 1) l = 4;
            else if (l == 4) l = 1;
        }
        else if (s[i] == 'D') {
            if (b == 2) b = 3;
            else if (b == 3) b = 2;
            if (l == 2) l = 3;
            else if (l == 3) l = 2;
        }
        else if (s[i] == 'E') {
            if (b == 2) b = 4;
            else if (b == 4) b = 2;
            if (l == 2) l = 4;
            else if (l == 4) l = 2;
        }
        else if (s[i] == 'F') {
            if (b == 3) b = 4;
            else if (b == 4) b = 3;
            if (l == 3) l = 4;
            else if (l == 4) l = 3;
        }
    }
    printf("%d\n%d", l, b);
    return 0;
}