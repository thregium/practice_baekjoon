#include <stdio.h>
#include <stdlib.h>

/*
���� : ��ȭ���� (������ * x + ������ * y(0 <= x, y <= 100)) mod 100�� ���� �ִ�. ù �� ���� �־��� ��, N��° ���� ���Ѵ�.

�ذ� ��� : �� ��°�� ���°� �ִ� 100������� ���� �̿��� ���� ���°� �ִ� 10000�����̹Ƿ� ���� �ֱ⸦ ã���� �ȴ�.
����, �ǻ�� �ֱ��� ������ ���ϸ� �������� �ִ� N�� �ȿ� ���ƿ´ٴ� ���� ���� �ð� ���⵵�� ���� �����ϴ�.

�ֿ� �˰��� : DP, ����, �ǻ�� �ֱ�
*/

int a[10240], a2[1048576];

int main(void) {
    int x, y, n, md = 0, st = 0, res = 0;
    //while (1) {
        scanf("%d %d %d %d %d", &x, &y, &a[0], &a[1], &n);
        /*
        x = rand() % 100;
        y = rand() % 100;
        a[0] = rand() % 100;
        a[1] = rand() % 100;
        n = ((rand() << 8) + rand()) % 1000000;
        */
        md = 0;
        for (int i = 2;; i++) {
            a[i] = (x * a[i - 1] + y * a[i - 2]) % 100;
            for (int j = 1; j <= i - 2; j++) {
                if (a[i] == a[j] && a[i - 1] == a[j - 1]) {
                    md = i - j;
                    st = j + 1;
                    break;
                }
            }
            if (md != 0) break;
        }

        /*
        a2[0] = a[0], a2[1] = a[1];
        for (int i = 2; i <= n; i++) {
            a2[i] = (x * a2[i - 1] + y * a2[i - 2]) % 100;
        }
        printf("%02d : %02d\n", a[n % md], a2[n]);
        */
        if (n < st) res = a[n];
        else res = a[(n - st) % md + st];
        /*
        if (res != a2[n]) {
            printf("%02d : %02d\n%d %d %d %d %d\n", a[n % md], a2[n], x, y, a[0], a[1], n);
        }
        */
    //}
    
    printf("%02d", res);
    return 0;
}