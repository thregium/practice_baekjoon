#include <stdio.h>

/*
���� : ����� HELLO + WORLD�� ���� N�� �Ǵ� �� ���ڵ��� �ִ��� ã��, �ִٸ� �׷��� ���� �ϳ� ����Ѵ�.
��, H�� W�� ���� 0�� �� �� ����, ��� ���ڵ��� ���� �޶�� �Ѵ�. ���� ��쿡�� No Solution�� ����Ѵ�.

�ذ� ��� : �� ���ڵ��� ���� �ٸ��� �ϴ� �������� ���� ã�� ��, H�� W�� 0�� �ƴϰ� HELLO + WORLD�� N�� ���ٸ�
�׷��� ���� ����ϰ� ���α׷��� �����Ѵ�. ã�� ���� ��쿣 ���� ���̹Ƿ� No Solution�� ����ϸ� �ȴ�.

�ֿ� �˰��� : ����, ��Ʈ��ŷ

��ó : FunctionCup 2016 H��
*/

int digits[8], chk[16];
int n, fin = 0;

void check(void) {
    if (digits[0] == 0 || digits[4] == 0) return;
    if (digits[0] * 10000 + digits[1] * 1000 + digits[2] * 120 + digits[3] * 1001 + digits[4] * 10000 + digits[5] * 100 + digits[6] == n) {
        fin = 1;
        printf("  %d%d%d%d%d\n", digits[0], digits[1], digits[2], digits[2], digits[3]);
        printf("+ %d%d%d%d%d\n", digits[4], digits[3], digits[5], digits[2], digits[6]);
        printf("-------\n");
        if (n < 100000) printf("  %d", n);
        else printf(" %d", n);
    }
}

void track(int x) {
    if (x == 7) {
        check();
        return;
    }
    for (int i = 0; i < 10; i++) {
        if (chk[i]) continue;
        chk[i] = 1;
        digits[x] = i;
        track(x + 1);
        chk[i] = 0;
        if (fin) return;
    }
}

int main(void) {
    scanf("%d", &n);
    track(0);
    if (!fin) printf("No Answer");
    return 0;
}