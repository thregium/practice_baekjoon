#include <stdio.h>
#include <math.h>

/*
���� : N * M(N, M <= 9) ũ���� ǥ�� ���ڵ��� ���� �ִ�. �� ǥ���� ���ڵ��� �ƹ� ������ �� �������� �̾���� ���� ���
���� ū �������� ���Ѵ�. ���ٸ� -1�� ����Ѵ�.

�ذ� ��� : ��� ������ ��� ���⿡ ���� �̾�ٿ� ���� �� �ִ� ������ ���� ���� ����, ������ ���� ���������� Ȯ���Ѵ�.
������������ sqrt�Լ��� ��� �Ǵ� �� ���� ������ ������ ���ؼ� ���ٸ� ���������� Ȯ�� �����ϴ�.
�̵� �� ���� ū �������� ã���� �ȴ�.

�ֿ� �˰��� : ���Ʈ ����
*/

char nums[16][16];

int main(void) {
    int n, m;
    long long p, rt, best = -1;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", nums[i]);
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < m; y++) {
            for (int dx = -9; dx <= 9; dx++) {
                for (int dy = -9; dy <= 9; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    p = 0;
                    for (int i = 0;; i++) {
                        if (x + dx * i < 0 || y + dy * i < 0 || x + dx * i >= n || y + dy * i >= m) break;
                        p *= 10;
                        p += nums[x + dx * i][y + dy * i] - '0';
                        if (p <= best) continue;
                        rt = sqrt(p);
                        for (int i = rt - 10; i <= rt + 10; i++) {
                            if ((long long)i * i == p) best = p;
                        }
                    }
                }
            }
        }
    }
    printf("%lld", best);
    return 0;
}