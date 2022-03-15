#include <stdio.h>
#include <string.h>
#define INF 103000

/*
문제 : N(N <= 10)개의 길이 10 이하 대문자로 이루어진 문자열들이 주어질 때,
모든 문자열들을 부분 문자열로 갖는 문자열 가운데 가장 짧은 것을 구한다. 그러한 것이 여러 개라면
사전순으로 가장 빠른 것을 구한다.

해결 방법 : 우선 한 문자열이 다른 문자열의 부분 문자열인 경우 관계를 정리해 모두 합쳐둔다.
그러면 한 단어와 다른 단어가 겹치는 부분은 최대 2개(앞, 뒤) 뿐이므로 특정 단어가 끝이고
사용한 단어들에 따른 최적의 단어를 상태로 하여 비트마스킹 DP를 하면 된다.
이 과정에서 시간을 절약하기 위해 각 단어와 다음 단어마다 추가해야 하는 문자의 개수를 전처리하는 것이 좋다.
답은 모든 문자열을 사용한 경우 가운데 가장 짧은, 사전순으로 가장 빠른 것이다.

주요 알고리즘 : DP, 비트DP, 문자열

출처 : JAG 2008D E번
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