#include <stdio.h>
#include <string.h>

/*
���� : ���� 50 ������ �� A�� B�� �̷���� ���ڿ� S�� T�� �־��� ��, ���� �������� S���� T�� �ٲ� �� �ִ��� ���Ѵ�.
1. ���ڿ��� �� �ڿ� A�� �߰��Ѵ�.
2. ���ڿ��� �� �ڿ� B�� �߰��ϰ� ���ڿ��� �����´�.

�ذ� ��� : S���� T���� �̵��� ��� Ȯ���ϱ⿡�� S�� T�� ���̰� �� ���̴�.
������ T���� S���� �̵��� �������� �������� �׶��� ������ ��� ��츦 �������� ����� ���� �پ��Ƿ� �׷��� �ϸ� �ȴ�.

�ֿ� �˰��� : ��Ʈ��ŷ

��ó : SRM 663 D1A
*/

char s[1024], t[1024];
int ls, res = 0;

void swap(char* a, char* b) {
    char c = *a;
    *a = *b;
    *b = c;
}

void track(int st, int ed, int d) {
    if (ed - st == ls - 1) {
        int tmp = 1;
        if (d == 0) {
            for (int i = st; i <= ed; i++) {
                if (s[i - st] != t[i]) tmp = 0;
            }
        }
        else {
            for (int i = 0; i < ls; i++) {
                if (s[i] != t[ed - i]) tmp = 0;
            }
        }
        res |= tmp;
    }

    if (d) {
        if (t[st] == 'A') track(st + 1, ed, 1);
        if (t[ed] == 'B') track(st, ed - 1, 0);
    }
    else {
        if (t[ed] == 'A') track(st, ed - 1, 0);
        if (t[st] == 'B') track(st + 1, ed, 1);
    }
}

int main(void) {
    scanf("%s%s", s, t);
    ls = strlen(s);
    track(0, strlen(t) - 1, 0);
    printf("%d", res);
    return 0;
}