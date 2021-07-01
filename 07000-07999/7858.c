#include <stdio.h>
#include <ctype.h>

/*
문제 : 블록들이 쌓인 형태가 N(N <= 50) * 20 크기에 주어질 때, 블록이 쌓인 순서로 가능한 것 중 가장 사전순으로 빠른 것을 구한다.
블록은 알파벳 대문자로 주어진다.

해결 방법 : 각 블록들 중 위아래로 서로 다른 블록이 나오는 경우를 찾고, 아래 블록에서 위 블록으로 이동하는 간선으로 연결한다.
그 다음, 위상정렬을 하며 진입차수가 0인 방문하지 않은 정점 중 가장 사전순으로 빠른 정점을 차례로 방문하면 된다.

주요 알고리즘 : 그래프 이론, 위상 정렬

출처 : NEERC_FE 2002 B번
*/

char tetr[64][32];
int adj[32][32], ins[32], exist[32];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", tetr[i]);
        for (int j = 0; j < 20; j++) {
            if (isupper(tetr[i][j])) exist[tetr[i][j] - 'A'] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 20; j++) {
            if (isupper(tetr[i][j]) && isupper(tetr[i - 1][j])) {
                if (tetr[i][j] == tetr[i - 1][j]) continue;
                if (adj[tetr[i][j] - 'A'][tetr[i - 1][j] - 'A']) continue;
                adj[tetr[i][j] - 'A'][tetr[i - 1][j] - 'A'] = 1;
                ins[tetr[i - 1][j] - 'A']++;
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (ins[j] || !exist[j]) continue;
            printf("%c", 'A' + j);
            for (int k = 0; k < 26; k++) {
                if (adj[j][k]) ins[k]--;
            }
            exist[j] = 0;
            break;
        }
    }
    return 0;
}