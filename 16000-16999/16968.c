#include <stdio.h>

/*
���� : 4�ڸ� ������ �����ǿ� ���� �Ǵ� �빮�� ���ĺ��� ���� �� �ִ�. ����, ������ ���ڴ� ���� �޶�� �Ѵ�.
�� �����ǿ� ����� �ϴ� ������ ����(����, ���ĺ�)�� �־��� ��, ���������� ���� �� �ִ� ���ڿ��� ������ ���Ѵ�.

�ذ� ��� : �� �����ǿ� ���� �� �ִ� ���ڵ��� �־�� ���� �� �ִ��� Ȯ���� ������.
���� �� ���� ���ڰ� ������ ���� ���ڸ� �־��, ������ ���ڿ��� �ᱣ���� �÷����� ����̴�.

�ֿ� �˰��� : ���Ʈ ����
*/

char s[8];
int a[4];

int check(int a, char c) {
    //�ش� ���ڰ� �� �� �ִ��� Ȯ���Ѵ�.
    if (a >= 0 && a < 10 && c == 'd') return 1;
    if (a >= 10 && a < 36 && c == 'c') return 1;
    return 0;
}

int main(void) {
    int r = 0;
    scanf("%s", s);
    for (int i1 = 0; i1 < 36; i1++) {
        if (!check(i1, s[0])) continue;
        a[0] = i1;
        if (!s[1]) {
            r++;
            continue;
        }
        for (int i2 = 0; i2 < 36; i2++) {
            if (!check(i2, s[1]) || i2 == a[0]) continue;
            a[1] = i2;
            if (!s[2]) {
                r++;
                continue;
            }
            for (int i3 = 0; i3 < 36; i3++) {
                if (!check(i3, s[2]) || i3 == a[1]) continue;
                a[2] = i3;
                if (!s[3]) {
                    r++;
                    continue;
                }
                for (int i4 = 0; i4 < 36; i4++) {
                    if (!check(i4, s[3]) || i4 == a[2]) continue;
                    a[3] = i4;
                    if (s[4]) return 1;
                    r++;
                }
            }
        }
    }
    printf("%d", r);
    return 0;
}