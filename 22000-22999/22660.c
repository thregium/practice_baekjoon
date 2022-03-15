#include <stdio.h>
#include <string.h>
#define INF 103000

/*
���� : N(N <= 10)���� ���� 10 ���� �빮�ڷ� �̷���� ���ڿ����� �־��� ��,
��� ���ڿ����� �κ� ���ڿ��� ���� ���ڿ� ��� ���� ª�� ���� ���Ѵ�. �׷��� ���� ���� �����
���������� ���� ���� ���� ���Ѵ�.

�ذ� ��� : �켱 �� ���ڿ��� �ٸ� ���ڿ��� �κ� ���ڿ��� ��� ���踦 ������ ��� ���ĵд�.
�׷��� �� �ܾ�� �ٸ� �ܾ ��ġ�� �κ��� �ִ� 2��(��, ��) ���̹Ƿ� Ư�� �ܾ ���̰�
����� �ܾ�鿡 ���� ������ �ܾ ���·� �Ͽ� ��Ʈ����ŷ DP�� �ϸ� �ȴ�.
�� �������� �ð��� �����ϱ� ���� �� �ܾ�� ���� �ܾ�� �߰��ؾ� �ϴ� ������ ������ ��ó���ϴ� ���� ����.
���� ��� ���ڿ��� ����� ��� ��� ���� ª��, ���������� ���� ���� ���̴�.

�ֿ� �˰��� : DP, ��ƮDP, ���ڿ�

��ó : JAG 2008D E��
*/

char city[16][32], temp[256], mem[1024][16][256];
int dist[16][16];

int small(int a, int b) {
    return a < b ? a : b;
}

int strcmpl(char* a, char* b) {
    if (strlen(a) > strlen(b)) return 1;
    else if (strlen(a) < strlen(b)) return -1;
    else return strcmp(a, b);
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
                        dist[i][j] = strlen(city[i]) - k;
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                memset(mem[i][j], '#', 120);
                mem[i][j][120] = '\0';
            }
        }
        for (int i = 0; i < n; i++) {
            strcpy(mem[1 << i][i], city[i]);
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) continue;
                for (int k = 0; k < n; k++) {
                    if (j == k) continue;
                    if (!((i ^ (1 << j)) & (1 << k))) continue;
                    strcpy(temp, mem[i ^ (1 << j)][k]);
                    strcat(temp, &city[j][dist[k][j]]);
                    if (strcmpl(mem[i][j], temp) > 0) strcpy(mem[i][j], temp);
                }
            }
        }
        for (int i = 0; i < 120; i++) temp[i] = '#';
        temp[120] = '\0';
        for (int i = 0; i < n; i++) {
            if (strcmpl(temp, mem[(1 << n) - 1][i]) > 0) strcpy(temp, mem[(1 << n) - 1][i]);
        }
        printf("%s\n", temp);
    }
    return 0;
}