#include <stdio.h>

/*
문제 : N * N(2 <= N <= 100) 크기의 각 칸에 1부터 N^2까지의 자연수가 한 번씩 적혀있는 지도가 있다.
이 지도에서 상하좌우로 인접한 칸들의 모든 목록이 주어질 때, 원래 지도를 출력한다.

해결 방법 : 우선 맨 윗줄과 왼쪽 줄의 모든 수들을 알 수 있다면 이후로는 두 수에 인접하고 아직 확인하지
않은 수는 하나 뿐이므로 이를 반복하여 나머지 수들을 채울 수 있다는 사실을 알 수 있다.
맨 윗줄은 왼쪽 위 꼭짓점부터 시작한다. 이는 차수가 2인 아무 정점을 시작점으로 잡으면 된다.
이후로는 차수가 4가 아니며 아직 방문하지 않은 정점을 차례로 다음 정점으로 채워나가는 것을 반복한다.
이는 2번째 칸을 제외하면 항상 1개뿐임을 알 수 있으므로 원래 지도를 채워나갈 수 있다.
왼쪽과 위쪽 줄을 채웠으면 나머지 칸은 위에서 설명한 방법대로 채우면 된다.

주요 알고리즘 : 그래프 이론, 구성적

출처 : JAG 2017S3 C번
*/

int cnt[10240], vis[10240], adj[10240][4], res[128][128];

int main(void) {
    int n, x, y;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n * (n - 1); i++) {
        scanf("%d %d", &x, &y);
        adj[x][cnt[x]++] = y;
        adj[y][cnt[y]++] = x;
    }
    for (int i = 1; i <= n * n; i++) {
        if (cnt[i] == 2) {
            res[0][0] = i;
            vis[i]++;
            break;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cnt[res[0][i - 1]]; j++) {
            if (!vis[adj[res[0][i - 1]][j]] && cnt[adj[res[0][i - 1]][j]] < 4) {
                vis[adj[res[0][i - 1]][j]]++;
                res[0][i] = adj[res[0][i - 1]][j];
                break;
            }
        }
        for (int j = 0; j < cnt[res[i - 1][0]]; j++) {
            if (!vis[adj[res[i - 1][0]][j]] && cnt[adj[res[i - 1][0]][j]] < 4) {
                vis[adj[res[i - 1][0]][j]]++;
                res[i][0] = adj[res[i - 1][0]][j];
                break;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int a = 0; a < cnt[res[i - 1][j]]; a++) {
                for (int b = 0; b < cnt[res[i][j - 1]]; b++) {
                    if (!vis[adj[res[i - 1][j]][a]] && adj[res[i - 1][j]][a] == adj[res[i][j - 1]][b]) {
                        vis[adj[res[i - 1][j]][a]]++;
                        res[i][j] = adj[res[i - 1][j]][a];
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", res[i][j], j == n - 1 ? '\n' : ' ');
            while (res[i][j] <= 0 || vis[res[i][j]] != 1);
        }
    }
    return 0;
}
