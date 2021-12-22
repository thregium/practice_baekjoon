#include <stdio.h>
#include <stdlib.h>
#define INF 1012345678

/*
���� : �ڿ��� N(N <= 10^6)�� �־�����, N���� �����Ͽ� N�� �� �κ� ���ڿ� ��� 0���� ū ���� �� ������.
���̻� �� �κ� ���ڿ��� ���� �� ���� ����� ���ٸ� N�� �־����� �� ������ �̱�� ����� �ִ� �� ���ϰ� �ִٸ�
�����ؾ� �ϴ� �� �κ� ���ڿ� ��� ���� ���� ���� ����ϰ�, ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : �켱 1�ڸ� ���� ���� ��� �� �κ� ���ڿ��� ���� ������ ���� �ȴ�. �� ���� ������ �� �κ� ���ڿ���
���� ���� �� �ִ� �� ��� ���� ���� �ִٸ� �̱��, ���ٸ� ���� �ȴ�.
�̷��� ������ ���̳��� ���α׷����� ���� ���� ������ �ȴ�. ����� Ȯ���� ������ ���� ����� -1�� ����ϸ� �ǰ�,
�̱�� ����� �� �κ� ���ڿ��� �� �� ��� ���� ���� ������ ���� ���� �� �κ� ���ڿ��� ã�� ����ϸ� �ȴ�.

�ֿ� �˰��� : DP, ���� �̷�, ���ڿ�

��ó : SRM 360 D2C��
*/

int mem[1048576];
char buff[16];

int main(void) {
    int n, win, sub, best = INF;
    for (int i = 10; i <= 1000000; i++) {
        sprintf(buff, "%d", i);
        win = 0;
        while (1) {
            if (buff[0] == '\0') break;
            for (int j = 0; buff[j]; j++) {
                sub = strtoll(buff + j, NULL, 10);
                if (buff[j + 1] == '\0') buff[j] = '\0';
                if (sub >= i || sub == 0) continue;
                if (mem[i - sub] == 0) win = 1;
            }
        }
        mem[i] = win;
    }
    scanf("%s", buff);
    n = strtoll(buff, NULL, 10);
    while (1) {
        if (buff[0] == '\0') break;
        for (int j = 0; buff[j]; j++) {
            sub = strtoll(buff + j, NULL, 10);
            if (buff[j + 1] == '\0') buff[j] = '\0';
            if (sub >= n || sub >= best || sub == 0) continue;
            if (mem[n - sub] == 0) best = sub;
        }
    }
    printf("%d", best == INF ? -1 : best);
    return 0;
}