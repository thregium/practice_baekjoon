#include <stdio.h>
#include <queue>
using namespace std;

char sieve[5242880][2];
priority_queue<int> dw, gs;

int main(void) {
    sieve[0][0] = 1;
    sieve[1][0] = 1;
    for (int i = 2; i <= 5000000; i++) {
        if (sieve[i][0]) continue;
        for (int j = i * 2; j <= 5000000; j += i) {
            sieve[j][0] = 1;
        }
    }
    int n, dn, gn, a, b;
    long long d = 0, g = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &dn, &gn);
        if (!sieve[dn][0]) {
            if (sieve[dn][1]) d -= 1000;
            else {
                dw.push(dn);
                sieve[dn][1] = 1;
            }
        }
        else {
            if (gs.size() < 3) g += 1000;
            else {
                a = gs.top();
                gs.pop();
                b = gs.top();
                gs.pop();
                g += gs.top();
                gs.push(a);
                gs.push(b);
            }
        }
        if (!sieve[gn][0]) {
            if (sieve[gn][1]) g -= 1000;
            else {
                gs.push(gn);
                sieve[gn][1] = 1;
            }
        }
        else {
            if (dw.size() < 3) d += 1000;
            else {
                a = dw.top();
                dw.pop();
                b = dw.top();
                dw.pop();
                d += dw.top();
                dw.push(a);
                dw.push(b);
            }
        }
    }
    if (d > g) printf("�Ҽ��� �� �����");
    else if (d == g) printf("�쿭�� ���� �� ����");
    else printf("�Ҽ� ������ ���Լ�");
    return 0;
}