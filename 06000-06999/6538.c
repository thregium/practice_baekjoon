#include <stdio.h>
#include <string.h>

/*
���� : �־��� ���ڿ��� RLE ���·� ���ڵ��� ���ڿ��� ����Ѵ�. 2���� 9 ������ ���ڸ� �̿��ϸ�,
1�� ������ �յڿ� 1�� �ְ� �� ���̿��� ���ڸ� �߰����� �ʴ´�. 1�� ���δٸ� 1�� 2�� �������� ����.

�ذ� ��� : ���� ������ ������ Ȯ���� �����鼭 ���ڿ����� ����� ������ �ȴ�. ������ �����ϹǷ� �����Ѵ�.

�ֿ� �˰��� : ����, ���ڿ�, �Ľ�

��ó : Ulm 2004 E��
*/

char s[103000];

int main(void) {
    int l, one;
    char c;
    //freopen("E:\\PS\\Contest\\Ulm\\2004\\encoding.in", "r", stdin);
    //freopen("E:\\PS\\Contest\\Ulm\\2004\\encoding _t.out", "w", stdout);
    while (fgets(s, 103000, stdin)) {
        if (s[strlen(s) - 1] == '\n') s[strlen(s) - 1] = '\0';
        l = 0, c = '\0', one = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] != c || l == 9) {
                if (l == 1) {
                    if (one) printf("%c", c);
                    else printf("1%c", c);
                    if (c == '1') printf("1");
                    one = 1;
                }
                else {
                    if (one) printf("1");
                    if (c) printf("%d%c", l, c);
                    one = 0;
                }
                l = 1, c = s[i];
            }
            else l++;
        }
        if (l == 1) {
            if (one) printf("%c", c);
            else printf("1%c", c);
            if (c == '1') printf("1");
            one = 1;
        }
        else {
            if (one) printf("1");
            if (c) printf("%d%c", l, c);
            one = 0;
        }
        if (one) printf("1");
        printf("\n");
    }
    return 0;
}