#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N * M(N, M <= 300) 크기의 배열을 R(R <= 1000)번 반시계방향으로 돌린 결과를 출력한다.

해결 방법 : 바깥쪽부터 같이 돌아가는 껍질을 각각 분해한다. 그 다음, R % (해당 껍질의 길이)칸만큼 민 다음,
결과를 다시 배열에 넣어 출력하면 된다.

주요 알고리즘 : 구현, 수학
*/

int arr[384][384];
vector<int> lin[384];

int small(int a, int b) {
    return a < b ? a : b;
}

int main(void) {
    int n, m, r, x, y, c, d;
    scanf("%d %d %d", &n, &m, &r);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < (small(n, m) >> 1); i++) {
        x = i, y = i, d = 0;
        while (d < 4) {
            lin[i].push_back(arr[x][y]);
            switch (d) {
            case 0:
                x++;
                if (x == n - i - 1) d++;
                break;
            case 1:
                y++;
                if (y == m - i - 1) d++;
                break;
            case 2:
                x--;
                if (x == i) d++;
                break;
            case 3:
                y--;
                if (y == i) d++;
                break;
            }
        }
        x = i, y = i, d = 0, c = 0;
        while (d < 4) {
            arr[x][y] = lin[i][(c + (long long)lin[i].size() * r - r) % lin[i].size()];
            switch (d) {
            case 0:
                x++;
                if (x == n - i - 1) d++;
                break;
            case 1:
                y++;
                if (y == m - i - 1) d++;
                break;
            case 2:
                x--;
                if (x == i) d++;
                break;
            case 3:
                y--;
                if (y == i) d++;
                break;
            }
            c++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}