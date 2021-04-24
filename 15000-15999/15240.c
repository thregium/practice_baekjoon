#include <stdio.h>

/*
문제 : 그림판에서 칸 별로 색이 칠해져 있을 때, 특정한 칸에서 페인트통 도구를 사용한 이후 그림판의 상태를 출력한다.

해결 방법 : 같은 색 덩이를 연결요소로 보고 그 위치에서 플러드필을 한다.

주요 알고리즘 : 그래프 이론, 플러드필

출처 : AIPO 2017F 3번
*/

char image[1024][1024], image2[1024][1024];
int r, c;

int isvalid(int x, int y, int d) {
    if (x < 0 || y < 0 || x >= r || y >= c) return 0;
    if (image[x][y] != d || image2[x][y]) return 0;
    return 1;
}

void dfs(int x, int y, int k1, int k2) {
    image2[x][y] = k2;
    if (isvalid(x, y + 1, k1)) dfs(x, y + 1, k1, k2);
    if (isvalid(x, y - 1, k1)) dfs(x, y - 1, k1, k2);
    if (isvalid(x + 1, y, k1)) dfs(x + 1, y, k1, k2);
    if (isvalid(x - 1, y, k1)) dfs(x - 1, y, k1, k2);
}

int main(void) {
    int x, y, k;
    scanf("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", image[i]);
    }
    scanf("%d %d %d", &x, &y, &k);
    dfs(x, y, image[x][y], k + '0');
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (image2[i][j]) printf("%c", image2[i][j]);
            else printf("%c", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}
