#include <stdio.h>
#include <stdlib.h>

/*
문제 : 점화식이 (이전항 * x + 전전항 * y(0 <= x, y <= 100)) mod 100인 식이 있다. 첫 두 항이 주어질 때, N번째 항을 구한다.

해결 방법 : 각 번째의 상태가 최대 100가지라는 점을 이용해 이전 상태가 최대 10000가지이므로 식의 주기를 찾으면 된다.
또한, 피사노 주기의 성질에 의하면 나머지는 최대 N번 안에 돌아온다는 것을 통해 시간 복잡도도 보장 가능하다.

주요 알고리즘 : DP, 수학, 피사노 주기
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