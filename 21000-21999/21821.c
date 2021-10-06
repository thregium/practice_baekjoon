#include <stdio.h>
#include <string.h>

/*
문제 : N(N <= 100)명의 이름(소문자, 10자 이내)이 주어진다. 이후 K(K <= 100)개의 저작물에 적힌 이름의 순서가 주어질 때,
모든 사람의 쌍에 대한 선후배 관계를 구한다. 선배인 경우 '1', 후배인 경우 '0', 알 수 없는 경우 '?', 자기 자신인 경우 'B'이다.
저작물에 적힌 이름의 순서는 기여도 -> 사전순이다. 모든 저작물에서 후배는 선배의 기여도 이상을 기여했다.

해결 방법 : 각 저작물의 이름이 사전순으로 되어있다면 기여도가 같은 것인지 알 수 없다. 그런데, 사전순이 아닌 경우에는
반드시 뒤쪽에 있는 사람이 기여도가 더 낮은 것이고, 이를 이용해 선후배 관계를 알 수 있다.
각 저작물에 대해 기여도를 그룹으로 나누고, 서로 기여도가 다른 그룸끼리 선후배 관계를 적용한다.
전부 적용한 다음에는 플로이드-워셜 알고리즘을 이용해 간접적으로 이어지는 선후배 관계도 추가해 주면
알 수 있는 모든 경우의 선후배 관계를 알 수 있다.

주요 알고리즘 : 문자열, 그래프 이론, 플로이드-워셜

출처 : USACO 2021O B2번
*/

char meb[128][16], paper[128][16], res[128][128];
int group[128], pmb[128];

int main(void) {
    int k, n;
    scanf("%d %d", &k, &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", meb[i]);
        for (int j = 0; j < n; j++) {
            if (i == j) res[i][j] = 'B';
            else res[i][j] = '?';
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%s", paper[j]);
            if (j == 0) group[j] = 1;
            else if (strcmp(paper[j], paper[j - 1]) < 0) group[j] = group[j - 1] + 1;
            else group[j] = group[j - 1];
            for (int kk = 0; kk < n; kk++) {
                if (!strcmp(paper[j], meb[kk])) pmb[j] = kk;
            }
        }
        for (int j = 0; j < n; j++) {
            for (int kk = j + 1; kk < n; kk++) {
                if (group[j] == group[kk]) continue;
                res[pmb[j]][pmb[kk]] = '0';
                res[pmb[kk]][pmb[j]] = '1';
            }
        }
    }
    
    for (int kk = 0; kk < n; kk++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (res[i][kk] == '1' && res[kk][j] == '1') res[i][j] = '1';
                if (res[i][kk] == '0' && res[kk][j] == '0') res[i][j] = '0';
            }
        }
    }
    

    for (int i = 0; i < n; i++) {
        printf("%s\n", res[i]);
    }
    return 0;
}