#include <stdio.h>

/*
���� : �� �ڿ��� T�� N(T, N <= 10^6)�� �־��� ��, N�� �߶� ���� ���� T ������ ���� ū �ڿ�����
�Ǵ� ��츦 ����Ѵ�. �׷��� ��찡 ���ٸ� "error"��, ������ ������ ��� "rejected"�� ����Ѵ�.

�ذ� ��� : N�� �ڸ��� ��� ��츦 �õ��غ��� T ������ �ִ��� ���ŵɶ� ���� �׶����� �ڸ� �����
�迭�� �����ص� ������ �ڸ��� ����� �迭�� �����Ѵ�. ���� �ִ񰪰� ���� ���� �ٽ� ���´ٸ� ����صΰ�
�ִ��� ���ŵ� ���� ���ų� ���� ���� ������ Ȯ�εǸ� "error" �Ǵ� "rejected"��,
�Ѵ� �ƴ϶�� ������ �迭�� ����Ѵ�.
�� ��츦 �õ��� ������ ���ڿ��� �ٲ� ���� ������ �߶� ����س����� �ȴ�.

�ֿ� �˰��� : ����, ���Ʈ ����

��ó : Kanazawa 2002 F��
*/

int best, bcnt, blen, arr[16], barr[16];

void track(int t, int n, int p, int c, int r) {
    int x = 0, i;
    char dig[16] = { 0, };
    sprintf(dig, "%d", n);
    for (i = p + 1; dig[i]; i++) {
        x *= 10;
        x += dig[i - 1] - '0';
        arr[c] = x;
        if (r > t) return;
        track(t, n, i, c + 1, r + x);
    }
    x *= 10;
    x += dig[i - 1] - '0';
    r += x;
    arr[c++] = x;
    if (r > t) return;
    if (r > best) {
        best = r;
        bcnt = 1;
        blen = c;
        for (int i = 0; i < c; i++) {
            barr[i] = arr[i];
        }
    }
    else if (r == best) bcnt++;
    return;
}

int main(void) {
    int t, n;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2002\\JAG\\paper.txt", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2002\\JAG\\paper_t.out", "w", stdout);
    while (1) {
        scanf("%d %d", &t, &n);
        if (t == 0) break;
        best = -1, bcnt = 1;
        track(t, n, 0, 0, 0);
        if (best < 0) printf("error\n");
        else if (bcnt > 1) printf("rejected\n");
        else {
            printf("%d ", best);
            for (int i = 0; i < blen; i++) {
                printf("%d", barr[i]);
                if (i < blen - 1) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}