#include <stdio.h>

/*
���� : 4�ڸ� �ڿ����� ���� �߱��� �Ѵ�. ������ ���� �信�� ���� ��ġ�� ���� ���ڰ� �ִٸ� ��Ʈ����ũ�� �߰��ǰ�,
��Ʈ����ũ�� �ƴϸ鼭 �ٸ� ��ġ�� ���� ���ڰ� �ִٸ� ���� �߰��ȴ�. ���� �߱��� N(N <= 100)ȸ �ϴ� ����
������ ���� ��Ʈ����ũ/���� ������ �־����� ���� �� �� �ִ� 4�ڸ� �� ��� ���� ���� ���� ����Ѵ�.
��, ���ٸ� "NONE"�� ����Ѵ�.

�ذ� ��� : 1000���� 9999 ���� ������ ���� �ֱ� ������ 1000���� 9999������ ��� ���� �ѹ��� �غ��� �ȴ�.
���� N���� ����� ��� �־��� ���� ���ٸ� �� ���� ����ϰ� ���α׷��� �����ϸ� �ǰ�, �ϳ��� �ٸ��ٸ� ���� ���� �� ����.
������ ���� �� �� �ִ� ���� ���ٸ� "NONE"�� ����ϸ� �ȴ�.

�� ���� ���� �߱� ����� ���� ���� ������ ������ ����, ��Ʈ����ũ ���θ� ���� �����Ѵ�. ��Ʈ����ũ�� ���,
�� ���ڴ� �̹� �������� ǥ���صξ� ���� ���� ���� ������ �ʵ��� �����Ѵ�.
�� �������� �� ���θ� �����Ѵ�. ���� ��Ʈ����ũ�� ������ ���� �� ��� ���� ���� �ִ��� Ȯ���ϸ� �ȴ�.
���� �� ���� �̹� �������� ǥ���صд�.

�ֿ� �˰����� : ���Ʈ ����, ����

��ó : USACO 2010M B3��
*/

int guess[128][3];

int guessing(int x, int y) {
    int xs[4], ys[4];
    for (int i = 0; i < 4; i++) {
        xs[i] = x % 10;
        ys[i] = y % 10;
        x /= 10, y /= 10;
    }
    int r = 0;
    for (int i = 0; i < 4; i++) {
        //��Ʈ����ũ ����
        if (xs[i] == ys[i]) {
            xs[i] = -1;
            ys[i] = -1;
            r += 10;
        }
    }
    for (int i = 0; i < 4; i++) {
        //�� ����
        if (xs[i] < 0) continue;
        for (int j = 0; j < 4; j++) {
            if (j == i) continue;
            if (xs[i] == ys[j]) {
                r++;
                xs[i] = -1;
                ys[j] = -1;
                break;
            }
        }
    }
    return r;
}

int main(void) {
    int n, x, t;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &guess[i][0], &guess[i][1], &guess[i][2]);
    }
    for (int i = 1000; i <= 9999; i++) {
        //���Ʈ ����
        t = 1;
        for (int j = 0; j < n; j++) {
            x = guessing(i, guess[j][0]);
            if (guess[j][1] * 10 + guess[j][2] != x) {
                t = 0;
                break;
            }
        }
        if (t) {
            printf("%d", i);
            return 0;
        }
    }
    printf("NONE");
    return 0;
}