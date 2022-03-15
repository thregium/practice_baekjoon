#include <stdio.h>
#include <string.h>
#define INF 103000

/*
���� : N(N <= 14)���� �ܾ �־�����. �� �ܾ�� 20�� ������ �ҹ��ڷ� �̷���� �ִ�.
�̶�, ��� �ܾ �κ� ���ڿ��� ������ ���� ª�� �ܾ��� ���̸� ���Ѵ�.

�ذ� ��� : �켱 �� ���ڿ��� �ٸ� ���ڿ��� �κ� ���ڿ��� ��� ���踦 ������ ��� ���ĵд�.
�׷��� �� �ܾ�� �ٸ� �ܾ ��ġ�� �κ��� �ִ� 2��(��, ��) ���̹Ƿ� Ư�� �ܾ ���̰�
����� �ܾ�鿡 ���� �ִ� ���̸� ���·� �Ͽ� ��Ʈ����ŷ DP�� �ϸ� �ȴ�.
�� �������� �ð��� �����ϱ� ���� �� �ܾ�� ���� �ܾ�� �߰��ؾ� �ϴ� ������ ������ ��ó���ϴ� ���� ����.
���� ������ �ܾ �����̵� ��� �ܾ ������� ���� �ִ� ���̰� �ȴ�.

�ֿ� �˰��� : ���ڿ�, DP, ��ƮDP

��ó : Fukuoka 2011 F��
*/

char city[16][32];
int mem[16384][16], dist[16][16];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, rmvd, res;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) {
            scanf("%s", city[i]);
        }
        rmvd = 0;
        while (rmvd >= 0) {
            rmvd = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (strstr(city[i], city[j])) {
                        rmvd = j;
                        break;
                    }
                }
            }
            if (rmvd >= 0) {
                n--;
                for (int i = rmvd; i < n; i++) {
                    strcpy(city[i], city[i + 1]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 0;
                for (int k = 0; city[i][k]; k++) {
                    if (strstr(city[j], city[i] + k) == city[j]) {
                        dist[i][j] = strlen(city[j]) - (strlen(city[i]) - k);
                        break;
                    }
                }
                if (dist[i][j] == 0) dist[i][j] = strlen(city[j]);
            }
        }

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                mem[i][j] = INF;
            }
        }
        for (int i = 0; i < n; i++) {
            mem[1 << i][i] = strlen(city[i]);
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                for (int k = 0; k < n; k++) {
                    if (j == k) continue;
                    if (!((i ^ (1 << j)) & (1 << k))) continue;
                    mem[i][j] = small(mem[i][j], mem[i ^ (1 << j)][k] + dist[k][j]);
                }
            }
        }
        res = INF;
        for (int i = 0; i < n; i++) {
            if (mem[(1 << n) - 1][i] < res) res = mem[(1 << n) - 1][i];
        }
        printf("%d\n", res);
    }
    return 0;
}