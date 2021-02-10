#include <stdio.h>
#include <malloc.h>

/*
���� : 2 ^ k * 2 - 1 (k <= 10) ���� ���� �̷���� ������ ���� ��, �� ������ 2 ^ k �� ������ �������� ����� 2 ^ k ���� �κм����� �� ���� ����Ѵ�.

�ذ� ��� : k�� 1�̶�� �������� �� Ȧ�� �Ǵ� �� ¦���� �����ϸ� �ȴ�. k�� n + 1�� �ȴٸ� ���� ������ 2 ^ n * 2 - 1 ���� ���� �̷���� �� ������ ������,
(������ �� ���� �ϴ� �����Ѵ�), k�� n�� ���� ����� �����´�. �� ������ ��ü ���� 2 ^ n * 2�� ������ �������� �� ���� �ᱣ������ ��ȯ�ϸ� �ǰ�,
������ �������� �ʴ´ٸ� k�� n�� ���� ����� ���õ��� ���� ������ ���� 2 ^ n * 2 - 1 ���̹Ƿ� �� ���������� k�� n�� ���� ����� ������ �� �ִ�.
����, k�� n�� ���� ����� 3���̰�, �̵� ������ ���� ��� 2 ^ n ���� ������ �������Ƿ� �̵� ��� ���� �����Ͽ� 2 ^ n * 2 �� ������ �������� ���� �ݵ�� �����Ѵ�.
�̵� ��� 2 ^ n * 2�� ������ �������� ������ ã�� ��ȯ�ϸ� �ȴ�.

�ֿ� �˰��� : ����, ���� ����
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
