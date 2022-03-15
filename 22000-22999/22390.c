#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
���� : ������ �־��� ���·� ������ ���� 80 ������ ���ڿ��� �־�����. �� ���ڿ��� ��й�ȣ�� �ؽ� �Լ��̴�.
�� �ؽ� �Լ��� �̿��Ͽ� 4�ڸ� ��й�ȣ P�� ����Ͽ��� ���� �ؽ� ���� �ش� �ؽð��� ���� 4�ڸ� ��й�ȣ��
������ ���� ���Ѵ�.

�ذ� ��� : 0000���� 9999���� ��� ��й�ȣ�� ���� �־��� �ؽ� �Լ��� ����Ѵ�.
����� ��ȣ�� �������� ��������� ����, ��쿡 ���� ó���� �� ���־�� �Ѵ�.
�ؽ� �Լ��� ����� �������� P�� ���Ͽ� P�� �ؽð� ���� ��ȣ�� ������ �� ��,
P�� �ؽÿ� �Բ� ����ϸ� �ȴ�.

�ֿ� �˰��� : ���ڿ�, �Ľ�, ���Ʈ ����, ���

��ó : JAG 2018D C��
*/

char ha[128];
int res[10240], abcd[4];

int getres(int st, int ed) {
    int x = -1, y = -1, dep = 0, ps = -1;
    if (st == ed) return abcd[ha[st] - 'a'];
    for (int i = st + (ha[st] == '['); i <= ed - (ha[ed] == ']'); i++) {
        if (ha[i] == '[') {
            if (dep == 0) ps = i;
            dep++;
        }
        else if (ha[i] == ']') {
            if (dep == 1) {
                if (x < 0) x = getres(ps, i);
                else y = getres(ps, i);
            }
            dep--;
        }
        else if (islower(ha[i])) {
            if (dep == 0) {
                if (x < 0) x = getres(i, i);
                else y = getres(i, i);
            }
        }
    }
    if (x < 0) {
        exit(1);
    }
    else if (y < 0) {
        exit(1);
    }
    else {
        if (ha[st + (ha[st] == '[')] == '+') return x | y;
        else if (ha[st + (ha[st] == '[')] == '*') return x & y;
        else return x ^ y;
    }
}

int main(void) {
    int l, p, r;
    while (1) {
        scanf("%s", ha);
        if (ha[0] == '.') break;
        l = strlen(ha);
        scanf("%d", &p);
        for (int d1 = 0; d1 < 10; d1++) {
            abcd[0] = d1;
            for (int d2 = 0; d2 < 10; d2++) {
                abcd[1] = d2;
                for (int d3 = 0; d3 < 10; d3++) {
                    abcd[2] = d3;
                    for (int d4 = 0; d4 < 10; d4++) {
                        abcd[3] = d4;
                        res[d1 * 1000 + d2 * 100 + d3 * 10 + d4] = getres(0, l - 1);
                    }
                }
            }
        }

        r = 0;
        for (int i = 0; i < 10000; i++) {
            if (res[i] == res[p]) r++;
        }
        printf("%d %d\n", res[p], r);
    }
    return 0;
}