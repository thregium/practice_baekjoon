#include <stdio.h>
#include <vector>
using namespace std;

/*
���� : N * M(N, M <= 300) ũ���� �迭�� R(R <= 1000)�� �ݽð�������� ���� ����� ����Ѵ�.

�ذ� ��� : �ٱ��ʺ��� ���� ���ư��� ������ ���� �����Ѵ�. �� ����, R % (�ش� ������ ����)ĭ��ŭ �� ����,
����� �ٽ� �迭�� �־� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ����
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