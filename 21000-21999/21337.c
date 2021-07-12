#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
���� : N(N <= 100)���� ���� �־��� ��, N ������ ���� ��� Ai(Ai <= 10^9), N���� ū ��쿡�� �ش� �� ������
�� �ڿ����� ������ ��������� �ּڰ��� ã�� ������ �ִ�. �� ������ K(K <= 10^9)��° ���� Q(Q <= 100000)ȸ ã�´�.

�ذ� ��� : DP�� ���� ������ ������ ä��� ���� ������ �ֱ�� �������� �ݺ��ȴٴ� ���� �� �� �ִ�.
�� �������� �ִ� N^2���� �����ϹǷ� ��� N^2 ������ �ֱ⿡ ���� �ش��ϴ� �ݺ��� �ִ��� Ȯ���ؼ� �ֱ⸦ ���Ѵ�.
�� ���� �ֱⰡ ������, �ֱ⸶�� �����ϴ� ���� ���ϰ�, ���� ������ �Է¿� ���ؼ��� ���ߴ� ������
���� �ֱ��� ����ŭ�� �̿��� ���ϸ� �ȴ�.

�ֿ� �˰��� : DP, �׸��� �˰���

��ó : NWERC 2020 A��
*/

int a[128];
long long mem[20480], diff[20480];

int main(void) {
    int n, q, k, t, rep = 0, reps;
    long long repn = 0;
    scanf("%d %d", &n, &q);
    srand(time(NULL));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        //a[i] = rand();
    }
    for (int i = 1; i <= 20000; i++) {
        if (i <= n) mem[i] = a[i];
        else {
            mem[i] = mem[i - 1] + mem[1];
            for (int j = 1; j <= i - j; j++) {
                if (mem[j] + mem[i - j] < mem[i]) mem[i] = mem[j] + mem[i - j];
            }
        }
        diff[i] = mem[i] - mem[i - 1];
    }
    for (int i = 5000; i > 0; i--) {
        t = 1;
        for (int j = 1; j <= i; j++) {
            if (diff[10000 + j] != diff[10000 + i + j]) t = 0;
        }
        if (t) {
            rep = i;
            for (int j = 1; j <= i; j++) {
                repn += diff[10000 + j];
            }
            break;
        }
    }
    if (!rep) return 1;
    for (int i = 0; i < q; i++) {
        scanf("%d", &k);
        if (k > 20000) {
            reps = (k - 14000) / rep;
            printf("%lld\n", reps * repn + mem[k - reps * rep]);
        }
        else printf("%lld\n", mem[k]);
    }
    return 0;
}