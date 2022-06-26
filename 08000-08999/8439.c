#include <stdio.h>
#include <math.h>

/*
���� : ���� ����� ������ ���� �������� ���� N(N <= 20000)ȸ�� �������� �̵��� �Ͽ��� ��,
���� ������ ũ�⸦ ���Ѵ�.

�ذ� ��� : �������� ���� ���� ������ ���̿� �ܺ� ������ ���̸� ���� ����� ���ϸ� �ȴ�.
���� ���̴� �ٰ����� ���� ������, �ܺ� ���̴� ȸ�� �淮�� ���� ���� ����� �Ѵ�.

�ֿ� �˰��� : ������, �ٰ����� ����

��ó : PA 2003 3-2��
*/

int mv[20480], pos[20480][2];

long long getarea(int n) {
    long long res = 0;
    for (int i = 0; i < n - 1; i++) {
        res += pos[i][0] * pos[i + 1][1] - pos[i][1] * pos[i + 1][0];
    }
    res += pos[n - 1][0] * pos[0][1];
    res -= pos[0][0] * pos[n - 1][1];
    return llabs(res);
}

int main(void) {
    int n = 0;
    char c;
    long long res = 0, res2 = 0;
    pos[0][0] = 0, pos[0][1] = 0;
    //scanf("%d", &n);
    scanf(" %c", &c);
    for (int i = 1;; i++) {
        scanf(" %c", &c);
        pos[i][0] = pos[i - 1][0];
        pos[i][1] = pos[i - 1][1];
        if (c == 'N') {
            pos[i][0]--;
            mv[i - 1] = 0;
        }
        else if (c == 'E') {
            pos[i][1]++;
            mv[i - 1] = 1;
        }
        else if (c == 'S') {
            pos[i][0]++;
            mv[i - 1] = 2;
        }
        else if (c == 'W') {
            pos[i][1]--;
            mv[i - 1] = 3;
        }
        else if (c == 'K') {
            n = i - 1;
            break;
        }
        else return -1;
    }
    if (pos[0][0] != pos[n][0] || pos[0][1] != pos[n][1]) return 2;

    res = getarea(n) * 2;
    if (res & 3) return 3;
    for (int i = 1; i < n; i++) {
        res2 += ((((mv[i - 1] - mv[i] + 4) & 3) + 1) & 3) + 1;
    }
    res2 += ((((mv[n - 1] - mv[0] + 4) & 3) + 1) & 3) + 1;
    if (res2 & 3) return 4;
    printf("%lld", (res + res2) >> 2);
    return 0;
}