#include <stdio.h>
#include <malloc.h>

/*
문제 : 2 ^ k * 2 - 1 (k <= 10) 개의 수로 이루어진 수열이 있을 때, 이 수열을 2 ^ k 로 나누어 떨어지게 만드는 2 ^ k 개의 부분수열을 한 가지 출력한다.

해결 방법 : k가 1이라면 수열에서 두 홀수 또는 두 짝수를 선택하면 된다. k가 n + 1이 된다면 먼저 수열을 2 ^ n * 2 - 1 개의 수로 이루어진 두 수열로 나누고,
(나머지 한 수는 일단 무시한다), k가 n일 때의 결과를 가져온다. 이 수열의 전체 합이 2 ^ n * 2로 나누어 떨어지면 이 수를 결괏값으로 반환하면 되고,
나누어 떨어지지 않는다면 k가 n일 때의 결과로 선택되지 않은 나머지 수도 2 ^ n * 2 - 1 개이므로 이 수열에서도 k가 n일 때의 결과를 가져올 수 있다.
따라서, k가 n일 때의 결과가 3개이고, 이들 각각의 합은 모두 2 ^ n 으로 나누어 떨어지므로 이들 가운데 둘을 선택하여 2 ^ n * 2 로 나누어 떨어지는 수는 반드시 존재한다.
이들 가운데 2 ^ n * 2로 나누어 떨어지는 수열을 찾아 반환하면 된다.

주요 알고리즘 : 수학, 분할 정복
*/

int arr[2048];
int rp = 0;

int* solve(int k, int* a) {
    /*
    for (int i = 0; i < (1 << k) * 2 - 1; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    */

    if (k == 1) {
        int* xt = malloc(sizeof(int) * 2);
        if ((a[0] + a[1]) % 2 == 0) {
            xt[0] = a[0];
            xt[1] = a[1];
        }
        else if ((a[0] + a[2]) % 2 == 0) {
            xt[0] = a[0];
            xt[1] = a[2];
        }
        else {
            xt[0] = a[1];
            xt[1] = a[2];
        }
        free(a);
        return xt;
    }
    int* x = malloc(sizeof(int) * (1 << k)), *y = malloc(sizeof(int) * (1 << k));
    for (int i = 0; i < (1 << k) - 1; i++) {
        x[i] = a[i];
        y[i] = a[i + (1 << k) - 1];
    }
    x = solve(k - 1, x);
    y = solve(k - 1, y);

    int* z = malloc(sizeof(int) * ((1 << k) - 1));
    int* xc = calloc(1, sizeof(int) * (1 << k)), * yc = calloc(1, sizeof(int) * (1 << k));

    int xyr = 0, zp = 0;
    int xs = 0, ys = 0, zs = 0;
    for (int i = 0; i < (1 << k) * 2 - 1; i++) {
        xyr = 0;
        for (int j = 0; j < (1 << (k - 1)); j++) {
            if (a[i] == x[j] && !xc[j]) {
                xyr = 1;
                xc[j] = 1;
                break;
            }
            else if (a[i] == y[j] && !yc[j]) {
                xyr = 1;
                yc[j] = 1;
                break;
            }
        }
        if(!xyr) z[zp++] = a[i];
    }
    free(xc), free(yc);
    z = solve(k - 1, z);
    for (int i = 0; i < (1 << (k - 1)); i++) {
        xs += x[i];
        ys += y[i];
        zs += z[i];
    }

    int* r = malloc(sizeof(int) * (1 << k));
    if ((xs + ys) % (1 << k) == 0) {
        for (int i = 0; i < (1 << (k - 1)); i++) {
            r[i * 2] = x[i];
            r[i * 2 + 1] = y[i];
        }
    }
    else if ((xs + zs) % (1 << k) == 0) {
        for (int i = 0; i < (1 << (k - 1)); i++) {
            r[i * 2] = x[i];
            r[i * 2 + 1] = z[i];
        }
    }
    else {
        for (int i = 0; i < (1 << (k - 1)); i++) {
            r[i * 2] = y[i];
            r[i * 2 + 1] = z[i];
        }
    }
    free(x);
    free(y);
    free(z);
    return r;
}

int main(void) {
    int n, k = 0;
    int* r;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; i++) {
        scanf("%d", &arr[i]);
        //arr[i] = i / 2 + 1;
    }
    r = malloc(sizeof(int) * n);
    for (int i = n; i > 0; i >>= 1) {
       k++;
    }
    r = solve(k - 1, arr);
    int rs = 0;
    /*
    for (int j = 0; j < n; j++) {
        printf("%d ", r[j]);
    }
    printf("\n");
    */
    for (int i = 0; i < n * 2 - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == r[j]) {
                printf("%d ", r[j]);
                rs += r[j];
                r[j] = -1;
                break;
            }
        }
    }
    free(r);
    //printf("\n%d", rs);
    return 0;
}
