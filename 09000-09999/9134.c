#include <stdio.h>
#include <stdlib.h>

/*
문제 : V층의 S * R(V, S, R <= 63) 크기인 건물이 있다. 인터넷이 연결되어야 하는 칸과,
이미 연결된 인터넷 선들의 상태가 주어질 때, 모든 인터넷이 연결되어야 하는 칸에 인터넷을 연결시키기 위해
필요한 최소 비용을 구한다. 인터넷은 각 방의 상하, 또는 전후좌우로 연쇄적으로 연결되며,
상하로는 2000, 전후좌우로는 1000의 비용이 든다.

해결 방법 : 이미 인터넷이 연결된 칸들은 그대로 두고 나머지로 연결할 수 있는 만큼 연결하여 MST를 만들면
만들며 새로 추가한 간선의 비용 합이 답이 된다.
각 연결 가능한 인터넷 선마다 배열에 추가한 후, 양쪽 중 하나라도 인터넷이 연결되어야 하는 칸인 경우
선을 연결시켜나간다. 모든 칸이 연결되었다면 그때까지의 비용을 출력하면 된다.

주요 알고리즘 : 그래프 이론, MST, 구현

출처 : CTU 2001 A번
*/

char buff[256];
int g[262144], cell[262144], ed[786432][3];

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int find(int x) {
    if (g[x] < 0) return x;
    else return g[x] = find(g[x]);
}

void uni(int x, int y) {
    if (find(x) == find(y)) return;
    g[find(y)] = find(x);
}

int main(void) {
    int v, r, s, esz;
    long long res;
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\a.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Europe\\CTU\\2001\\a_t.out", "w", stdout);
    while (1) {
        scanf("%d %d %d", &v, &r, &s);
        if (v == 0) break;
        for (int i = 0; i < 262144; i++) {
            g[i] = -1;
            cell[i] = 0;
        }
        esz = 0;
        for (int i = 0; i < v * 2 - 1; i++) {
            for (int j = 0; j < r * 2 - 1; j++) {
                scanf("%s", buff);
                for (int k = 0; k < s * 2 - 1; k++) {
                    if (buff[k] == '*') {
                        cell[(i >> 1) * r * s + (j >> 1) * s + (k >> 1)] = 1;
                    }
                    else if ((i & 1) + (j & 1) + (k & 1) == 1) {
                        if (buff[k] == '.') {
                            if (i & 1) ed[esz][0] = 2000;
                            else ed[esz][0] = 1000;
                            ed[esz][1] = (i >> 1) * r * s + (j >> 1) * s + (k >> 1);
                            ed[esz++][2] = ((i + 1) >> 1) * r * s + ((j + 1) >> 1) * s + ((k + 1) >> 1);
                        }
                        else {
                            uni((i >> 1) * r * s + (j >> 1) * s + (k >> 1),
                                ((i + 1) >> 1) * r * s + ((j + 1) >> 1) * s + ((k + 1) >> 1));
                        }
                    }
                }
            }
        }
        qsort(ed, esz, sizeof(int) * 3, cmp1);
        res = 0;
        for (int i = 0; i < esz; i++) {
            if (cell[ed[i][1]] && cell[ed[i][2]]) {
                if (find(ed[i][1]) != find(ed[i][2])) {
                    res += ed[i][0];
                    uni(ed[i][1], ed[i][2]);
                }
            }
        }
        if (res == 0) printf("Budova je jiz dostatecne propojena.\n");
        else if (res < 1000) printf("Ocekavana cena: %d Kc\n", res);
        else if (res < 1000000) printf("Ocekavana cena: %d,%03d Kc\n", res / 1000, res % 1000);
        else if (res < 1000000000) printf("Ocekavana cena: %d,%03d,%03d Kc\n",
            res / 1000000, res / 1000 % 1000, res % 1000);
        else printf("Ocekavana cena: %d,%03d,%03d,%03d Kc\n",
            res / 1000000000, res / 1000000 % 1000, res / 1000 % 1000, res % 1000);
    }
    return 0;
}