#include <stdio.h>
#include <string.h>
#define INF 103000

/*
문제 : N(N <= 500)개의 소문자로 이루어진 문자열이 주어질 때, 각 소문자의 사전 순서를 바꾸어
주어진 문자열들이 사전순이 되도록 할 수 있는 지 구한다.
각 문자열의 길이는 10 이하다.

해결 방법 : 우선 어떤 문자열이 그 앞 문자열과 다르고 접두사인 경우가 없는 지 확인한다.
그러한 경우가 있다면 사전순이 될 수 없다.
그 외에는 각 순서를 구분짓는 문자들 사이를 간선으로 이은 후 사이클이 생기지 않는 지 확인하면 된다.
이는 플로이드-워셜 알고리즘을 이용해 구할 수 있다.

주요 알고리즘 : 문자열, 그래프 이론, 플로이드-워셜

출처 : JAG 2012P A번
*/

char s[512][16];
int dist[26][26];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, r;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        r = 1;
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
            if (i > 0 && strstr(s[i - 1], s[i]) == s[i - 1] && strcmp(s[i - 1], s[i])) r = 0;
        }
        if (r == 0) {
            printf("no\n");
            continue;
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) dist[i][j] = INF;
        }
        
        for (int i = 1; i < n; i++) {
            if (!strcmp(s[i], s[i - 1])) continue;
            for (int j = 0; j < 10; j++) {
                if (s[i][j] == ' ' || s[i - 1][j] == ' ' || s[i][j] == '\0' || s[i - 1][j] == '\0') break;
                else if (s[i][j] != s[i - 1][j]) {
                    dist[s[i - 1][j] - 'a'][s[i][j] - 'a'] = 1;
                    break;
                }
            }
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    dist[i][j] = small(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (dist[i][i] != INF) r = 0;
        }
        printf("%s\n", r ? "yes" : "no");
    }
    return 0;
}