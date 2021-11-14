#include <stdio.h>

/*
���� : ������ ��ǥ�� ���� ��ǥ(0 <=, <= 10^6)�� �־��� ��, �� �� ĭ������ ���Ѵ�.

�ذ� ��� : ��ǥ�� ������ O(N)�� ������ �����̹Ƿ� X��ǥ�� Y��ǥ�� �Űܴٴϸ� ĭ�� Ȯ���ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���̽� ��ũ
*/

int main(void) {
    int ex, ey, x = 0, y = 0;
    long long p = 1, r = 1;
    scanf("%d %d", &ex, &ey);
    while (x < ex + ey) {
        r += p * 6;
        x++;
        p++;
    }
    if (ex == x && ey == y) {
        printf("%lld", r);
        return 0;
    }
    while (ex != x && ey != y) {
        r++;
        x--;
        y++;
    }
    printf("%lld", r - (p - 1) * 6);
    return 0;
}
