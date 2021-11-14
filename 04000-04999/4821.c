#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 1000)���� ������ �� ����ϴ� ������ �־�����. ����ϴ� �������� ��� ���Ѵ�.
st-ed�� p ���°� �޸��� ���̿� �ΰ� ���еǸ�, st > ed�� ���� ������� �ʰ� ������ ����� ��쵵 ������� �ʴ´�.
�־����� ���ڿ��� 1000�� �̳��̴�.

�ذ� ��� : strtok() �Լ��� �̿��� �Ľ��Ѵ�. �� �������� ������ �ٽ� strtoll() �Լ��� �̿��� �̾Ƴ���,
����� ���������� �迭�� �̿��� �����Ѵ�. �迭���� ����� �������� �� ���������� ���� �� ������ ���ϸ� ���� �ȴ�.

�ֿ� �˰��� : ����, �Ľ�

��ó : Rocky 2010 E��
*/

char s[1024];
int toprint[1024];

int main(void) {
    int n, r = 0, st, ed;
    char* c;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s", s);
        c = strtok(s, ",");
        while (c) {
            if (strchr(c, '-')) {
                st = strtoll(c, &c, 10);
                c++;
                ed = strtoll(c, NULL, 10);
                for (int i = st; i > 0 && i <= ed && i <= n; i++) toprint[i] = 1;
            }
            else {
                st = strtoll(c, NULL, 10);
                if (st >= 1 && st <= n) toprint[st] = 1;
            }
            c = strtok(NULL, ",");
        }
        r = 0;
        for (int i = 1; i <= n; i++) {
            r += toprint[i];
            toprint[i] = 0;
        }
        printf("%d\n", r);
    }
    return 0;
}