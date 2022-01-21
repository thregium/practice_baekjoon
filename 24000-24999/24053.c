#include <stdio.h>

/*
���� : N(N <= 10000)���� �ڿ����� �̷���� �� �迭 A, B�� �־��� ��, A�� ������ �־��� �����ڵ���
���� ���� �ϴ� �������� A�� B�� �������� ������ �ִ� �� ���Ѵ�.

�ذ� ��� : A�� B�� ���� �������� ���θ� �迭�� �����ϰ� ���� ������ ������ Ȯ���ϸ� �����Ѵ�.
���� �ٲ� �� ���� B�� ���� �������� ���θ� �����ϸ� ���� ������ ���� �ٲ� ������.
���� ������ ���� N�� �������� ������ �ִٸ� �װ��� A�� B�� �������� ������ ���̰�,
���ٸ� �׷��� ������ ���� ���̴�. �迭�� �� ó�� ���µ� Ȯ���ؾ� �Կ� �����Ѵ�.

�ֿ� �˰��� : ����, ����
*/

int same[10240], a[10240], b[10240];
int r = 0;

void inse(int n, int scnt) {
    int loc, ni;
    for (int i = 2; i <= n; i++) {
        loc = i - 1;
        ni = a[i];

        while (1 <= loc && ni < a[loc]) {
            if (a[loc + 1] == b[loc + 1]) {
                scnt--;
                same[loc + 1] = 0;
            }
            a[loc + 1] = a[loc];
            if (a[loc + 1] == b[loc + 1]) {
                scnt++;
                same[loc + 1] = 1;
            }
            if (scnt == n) r = 1;
            loc--;
        }

        if (loc + 1 != i) {
            if (a[loc + 1] == b[loc + 1]) {
                scnt--;
                same[loc + 1] = 0;
            }
            a[loc + 1] = ni;
            if (a[loc + 1] == b[loc + 1]) {
                scnt++;
                same[loc + 1] = 1;
            }
            if (scnt == n) r = 1;
        }
    }
}

int main(void) {
    int n, scnt = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (a[i] == b[i]) {
            same[i] = 1;
            scnt++;
        }
    }
    if (scnt == n) r = 1;
    inse(n, scnt);
    printf("%d", r);
    return 0;
}