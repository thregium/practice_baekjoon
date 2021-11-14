#include <stdio.h>
#include <stdlib.h>

/*
���� : �־��� ���ڿ�(100��, �ҹ���)�� ó�� �հ����� ��ġ�� �־��� ��, ���ڿ��� ġ�µ� �ɸ��� �ð��� ���Ѵ�.
ġ�µ� �ɸ��� �ð��� 1�� + ������ �հ������� �Ÿ��̴�.

�ذ� ��� : �޼հ� �������� ������ ��ġ�� ������ ����, �� ���ڿ����� ��� ��ġ�� �ִ��� Ȯ���ϰ�,
�� �Ÿ��� ���س����� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : �Ѿ��E 2020 A��
*/

const char* lt = "qwertasdfgzxcv-";
const char* rt = "-yuiop-hjkl-bnm---";
char s[128];

int main(void) {
    int xl = -1, yl = -1, xr = -1, yr = -1, r = 0;
    char sl, sr;
    scanf("%c %c", &sl, &sr);
    for (int i = 0; i < 15; i++) {
        if (sl == lt[i]) {
            xl = i / 5;
            yl = i % 5;
        }
    }
    for (int i = 0; i < 18; i++) {
        if (sr == rt[i]) {
            xr = i / 6;
            yr = i % 6;
        }
    }
    if (xl < 0 || xr < 0) return 1;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        for (int j = 0; j < 15; j++) {
            if (s[i] == lt[j]) {
                r += abs(j / 5 - xl);
                r += abs(j % 5 - yl);
                xl = j / 5;
                yl = j % 5;
            }
        }
        for (int j = 0; j < 18; j++) {
            if (s[i] == rt[j]) {
                r += abs(j / 6 - xr);
                r += abs(j % 6 - yr);
                xr = j / 6;
                yr = j % 6;
            }
        }
        r++;
    }
    printf("%d", r);
    return 0;
}