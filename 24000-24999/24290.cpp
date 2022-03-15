#include <stdio.h>
#include <unordered_set>
using namespace std;

/*
���� : N(N <= 1000)���� ���� ��ǥ���� �־��� ��, ������ �̾� ���� �� �ִ� ���簢���� ������ ���Ѵ�.
��� ������ �ʿ�� ����. �� ���� ��ǥ ������ 10000 ������ �ڿ����̴�.

�ذ� ��� : �� ������ ��ġ�� �ؽü¿� ������ ����, ��� �� 3���� �ֿ� ���� �������� ���θ� Ȯ���Ѵ�.
�����̶�� �ٸ� 1���� ���� �ؽü¿��� ã�� �ִٸ� ���� 1�� �÷�������.
�� �� ���� ���� ���� ����� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽü�, ������

��ó : IATI 2021C 3��
*/

long long point[1024][2];
unordered_set<int> ps;

int isright(int a, int b, int c) {
    if ((point[b][0] - point[a][0]) * (point[c][0] - point[a][0]) +
        (point[b][1] - point[a][1]) * (point[c][1] - point[a][1]) == 0) return 1;
    else return 0;
}

int main(void) {
    int n, r = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        //point[i][0] = i + 1, point[i][1] = i + 1;
        scanf("%lld %lld", &point[i][0], &point[i][1]);
        ps.insert((point[i][0] << 14) + point[i][1]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (isright(i, j, k)) {
                    r += (ps.find(((point[j][0] + (point[k][0] - point[i][0])) << 14) +
                        (point[j][1] + (point[k][1] - point[i][1]))) != ps.end());
                }
                else if (isright(j, i, k)) {
                    r += (ps.find(((point[i][0] + (point[k][0] - point[j][0])) << 14) +
                        (point[i][1] + (point[k][1] - point[j][1]))) != ps.end());
                }
                else if (isright(k, i, j)) {
                    r += (ps.find(((point[j][0] + (point[i][0] - point[k][0])) << 14) +
                        (point[j][1] + (point[i][1] - point[k][1]))) != ps.end());
                }
            }
        }
    }
    if (r & 3) return 1;
    printf("%d", r >> 2);
    return 0;
}