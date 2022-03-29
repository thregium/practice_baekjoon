#include <stdio.h>
#include <string.h>

/*
���� : N(N <= 1000)���� ���ڿ��� �̷���� �迭�� �־�����. S(S <= 5000)���� ������ �����Ѵ�.
insert. i��°�� �־��� ���ڿ��� �����Ѵ�.
depart. �־��� ���ڿ��� �迭���� �����Ѵ�.
relocate. �־��� ���ڿ��� ��ġ�� iĭ ���������� �ű��(������ ��� ���񰪸�ŭ ��������)
��� ���ڿ��� ���� �ٸ���, 10�� ������ �ҹ��� �Ǵ� ���ڷ� �̷���� �ִ�.

�ذ� ��� : N�� S�� ���� ������ ���� ���ڿ��� �̵��� �ùķ��̼��Ѵ�. 1ĭ�� ���� ���ڿ���
�а� ���� �۾��� �ϴ��� �ð� ���� ���� ����� ���ư���.

�ֿ� �˰��� : ����, ���ڿ�, �ùķ��̼�

��ó : Tehran 2020 H��
*/

char bird[8192][16], op[16], bn[16];

int main(void) {
    int n, s, p, d;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++) {
        scanf("%s", bird[i]);
    }
    for (int ss = 0; ss < s; ss++) {
        scanf("%s %s", op, bn);
        if (!strcmp(op, "insert")) {
            scanf("%d", &p);
            for (int i = n; i > p; i--) strcpy(bird[i], bird[i - 1]);
            strcpy(bird[p], bn);
            n++;
        }
        else if (!strcmp(op, "depart")) {
            p = -1;
            for (int i = 0; i < n; i++) {
                if (!strcmp(bn, bird[i])) {
                    p = i;
                    break;
                }
            }
            if (p < 0) return 21;
            for (int i = p; i < n - 1; i++) strcpy(bird[i], bird[i + 1]);
            n--;
        }
        else if (!strcmp(op, "relocate")) {
            scanf("%d", &d);
            p = -1;
            for (int i = 0; i < n; i++) {
                if (!strcmp(bn, bird[i])) {
                    p = i;
                    break;
                }
            }
            if (p + d < 0 || p + d >= n) return 31;
            if (d > 0) {
                for (int i = p; i < p + d; i++) strcpy(bird[i], bird[i + 1]);
                strcpy(bird[p + d], bn);
            }
            else if (d < 0) {
                for (int i = p; i > p + d; i--) strcpy(bird[i], bird[i - 1]);
                strcpy(bird[p + d], bn);
            }
        }
        else return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("%s ", bird[i]);
    }
    return 0;
}