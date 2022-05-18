#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : 5�� �̻� 12�� ������ ���ڿ��� 12 * 10^6 ������ �ڿ����� �־��� ��, ���ڿ����� 5���� ���ڸ�
�����Ͽ� ������ �־��� ���� ����Ͽ� �־��� ���� ���� �� �ִ� ���ڿ� ��� ���������� ���� ����
���ڿ��� ����Ѵ�. ���� ��� "no solution"�� ����Ѵ�.

�ذ� ��� : �־��� ���ڿ��� ���� ������� ������ ����, ���������� ���� Ž���� ������.
���� �Ǵ� ������ �߰��ϸ� �̸� �信 ������ ���� �ݺ��ϰ�, ���������� ���� ���� ����ϸ� �ȴ�.
ó�� ���°� �״�ζ�� ���� ���� ���̴�.

�ֿ� �˰��� : ���Ʈ ����

��ó : MidC 2002 D��
*/

char s[16], res[8];

int cmp1(const void* a, const void* b) {
    char ai = *(char*)a;
    char bi = *(char*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

long long getform(long long v, long long w, long long x, long long y, long long z) {
    return v - w * w + x * x * x - y * y * y * y + z * z * z * z * z;
}

int main(void) {
    long long targ, len;
    while (1) {
        scanf("%lld %s", &targ, s);
        if (targ == 0) break;
        len = strlen(s);
        qsort(s, len, sizeof(char), cmp1);

        strcpy(res, "-----");
        for (long long v = 0; v < len; v++) {
            for (long long w = 0; w < len; w++) {
                if (w == v) continue;
                for (long long x = 0; x < len; x++) {
                    if (x == v || x == w) continue;
                    for (long long y = 0; y < len; y++) {
                        if (y == v || y == w || y == x) continue;
                        for (long long z = 0; z < len; z++) {
                            if (z == v || z == w || z == x || z == y) continue;

                            if (getform(s[v] - 'A' + 1, s[w] - 'A' + 1, s[x] - 'A' + 1,
                                s[y] - 'A' + 1, s[z] - 'A' + 1) == targ) {
                                res[0] = s[v];
                                res[1] = s[w];
                                res[2] = s[x];
                                res[3] = s[y];
                                res[4] = s[z];
                            }
                        }
                    }
                }
            }
        }

        if (res[0] == '-') printf("no solution\n");
        else printf("%s\n", res);
    }
    return 0;
}