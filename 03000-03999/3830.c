#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
���� : N(N <= 100000)���� ������ �ִ�. �̶�, M(M <= 100000)���� ���� ������ �����Ѵ�.
1. �� ������ ������� ���� ���̰� �־�����. �� ���� �׻� �ϰ��ȴ�.
2. �� ������ ���� ���̸� ���� �� �ִ��� Ȯ���ϰ� �����ϴٸ� �� ���� ����ϰ� �Ұ����ϴٸ� UNKNOWN�� ����Ѵ�.
������ ��� �� ���� ������ 10^6 �����̴�.

�ذ� ��� : ���Ͽ� ���ε带 ���� �� ������ ���� ���տ� �ִ����� �� ���� ���̵� ���� �� �ִ�.
�� ���հ� ���� ������ ��ǩ���� ���Ը� ���ÿ� �����Ѵ�. ��� ���� �������� ���Ե� ���� �����ϵ��� �����ؾ� �Ѵ�.
�� ������ ���� �ٸ� �����̶�� ���Ͽ��ϸ� ���� �迭�� �� ���̸� �����Ѵ�.
�� ������ ���� ���̸� ���� ������ ���� �� ������ ���� �������� Ȯ���� �� �ƴ϶�� UNKNOWN�� ����ϰ�
�´ٸ� ���ϰ��� �ϴ� ������ ��ǩ������ ���̿��� ���ϰ��� �ϴ� ������ ���̸� �� ���� ���� ���� �� �ִ�.

�ֿ� �˰��� : �ڷᱸ��, ���Ͽ� ���ε�

��ó : Tokyo 2012 F��
*/

char buff[1024];
int g[103000], diff[103000], iscorrupt[103000];

long long find(long long x) {
    if (g[x] == 0) return x;
    long long r = find(g[x]);
    diff[x] += diff[g[x]];
    return g[x] = r;
}

long long getdiff(long long a, long long b) {
    long long r = 0;
    while (g[a]) {
        r -= diff[a];
        a = g[a];
    }
    while (g[b]) {
        r += diff[b];
        b = g[b];
    }
    return r;
}

void uni(long long a, long long b, long long w) {
    long long f, t, f2, t2;
    f = find(b);
    t = getdiff(f, b);
    f2 = find(a);
    t2 = getdiff(f2, a);
    if (f == f2) {

    }
    else {
        g[f] = f2;
        diff[f] = w - t + t2;
    }
}

int main(void) {
    long long n, m, a, b, w;
    char c;
    char* s;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\F.in", "r", stdin);
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2012\\InputsAndOutputs12\\F_t.out", "w", stdout);
    while (1) {
        fgets(buff, 1000, stdin);
        s = strtok(buff, " ");
        n = strtoll(s, NULL, 10);
        s = strtok(NULL, " ");
        m = strtoll(s, NULL, 10);
        if (n == 0) break;
        for (int i = 0; i < m; i++) {
            fgets(buff, 1000, stdin);
            s = strtok(buff, " ");
            if (buff[0] == '!') {
                s = strtok(NULL, " ");
                a = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                b = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                w = strtoll(s, NULL, 10);
                uni(a, b, w);
            }
            else if (buff[0] == '?') {
                s = strtok(NULL, " ");
                a = strtoll(s, NULL, 10);
                s = strtok(NULL, " ");
                b = strtoll(s, NULL, 10);
                if (find(a) != find(b)) {
                    printf("UNKNOWN\n");
                    continue;
                }
                printf("%lld\n", getdiff(a, b));
            }
        }
        for (int i = 1; i <= n; i++) {
            g[i] = 0;
            diff[i] = 0;
        }
    }
    return 0;
}