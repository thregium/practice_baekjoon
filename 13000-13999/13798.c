#include <stdio.h>

/*
���� : ���� 100000 ������ 1 �̻� 9 ������ ����(5 ����)�� �̷���� ���ڿ��� �־��� ��,
�� ���ڿ��� �ش��ϴ� ������ ������� ������ ���� �������� �ʱ� ����
�� ���� ���޾� ��ƾ� �ϴ� �ּ� Ƚ���� ���Ѵ�.

�ذ� ��� : �� ���� ��ġ�� �����ϸ鼭 �޹��� ���� ���� ���� �������� ���� ���� ���� ���� Ƚ���� ���� ���Ѵ�.
�� Ƚ���� ���� ������ ���ʷ� ���� ������ ����� ��ƺ� ���� �׷��� �� �� ���ٸ� �������� ��´�.
�̸� �ݺ��� ���� �� ���� Ƚ�� ��� ���� ���� ���� �ȴ�.

�ֿ� �˰��� : ����, �ùķ��̼�

��ó : JAG 2010P B��
*/

char s[103000];

int getx(char c) {
    return (c - '1') % 3;
}

int stepcount(int p1, int p2, int t) {
    int r1 = 0;
    for (int i = 1; s[i]; i++) {
        if (t) {
            if (getx(s[i]) < p1) {
                p1 = getx(s[i]);
                r1++;
            }
            else {
                p2 = getx(s[i]);
                t = !t;
            }
        }
        else {
            if (getx(s[i]) > p2) {
                p2 = getx(s[i]);
                r1++;
            }
            else {
                p1 = getx(s[i]);
                t = !t;
            }
        }
    }
    return r1;
}

int main(void) {
    int p1, p2, r1, r2, t;
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010P\\regional-2010-data\\B.txt", "r", stdin);
    //freopen("E:\\PS\\Contest\\Japanese Alumni Group\\2010P\\regional-2010-data\\B_t.out", "w", stdout);
    while (1) {
        scanf("%s", s);
        if (s[0] == '#') break;
        if (s[1] == '\0') {
            printf("0\n");
            continue;
        }
        r1 = stepcount(getx(s[0]), 4, 1);
        r2 = stepcount(-1, getx(s[0]), 0);
        if (r1 > r2) printf("%d\n", r2);
        else printf("%d\n", r1);
    }
    return 0;
}