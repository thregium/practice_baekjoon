#include <stdio.h>
#include <string.h>
#define INF 103000

/*
문제 : N(N <= 14)개의 단어가 주어진다. 각 단어는 20자 이하의 소문자로 이루어져 있다.
이때, 모든 단어를 부분 문자열로 가지는 가장 짧은 단어의 길이를 구한다.

해결 방법 : 우선 한 문자열이 다른 문자열의 부분 문자열인 경우 관계를 정리해 모두 합쳐둔다.
그러면 한 단어와 다른 단어가 겹치는 부분은 최대 2개(앞, 뒤) 뿐이므로 특정 단어가 끝이고
사용한 단어들에 따른 최단 길이를 상태로 하여 비트마스킹 DP를 하면 된다.
이 과정에서 시간을 절약하기 위해 각 단어와 다음 단어마다 추가해야 하는 문자의 개수를 전처리하는 것이 좋다.
답은 끝나는 단어가 무엇이든 모든 단어를 사용했을 때의 최단 길이가 된다.

주요 알고리즘 : 문자열, DP, 비트DP

출처 : Fukuoka 2011 F번
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