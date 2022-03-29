#include <stdio.h>
#include <vector>
using namespace std;

/*
문제 : N(N <= 200000)개의 정점으로 이루어진 트리의 각 정점에 숫자들이 쓰여 있다.
이때, Q(Q <= 200000)개의 쿼리에 응답한다.
A에서 B로 가는 최단 경로에 쓰인 숫자들을 이어붙인 값을 M(M <= 10^9)으로 나눈 나머지를 구한다.

해결 방법 : LCA를 통해 답을 구할 수 있다. 숫자들을 위쪽으로 2^i개 이어붙인 것을 m으로 나눈 나머지와
아래쪽으로 이어붙인 것의 나머지, 자신의 2^i번째 부모 정점들을 저장한 다음,
LCA를 구하는 동시에 양쪽의 숫자들을 만들어 나간다. 그리고 최종적으로 LCA인 정점의 값을
붙이는 동시에 양쪽 값들을 이어두면 답이 된다. 자세한 내용은 코드를 참고한다.

주요 알고리즘 : 수학, 정수론, 트리, LCA

출처 : MidAtl 2021 K번 // NCNA 2021 B번
*/

int digit[204800], depth[204800], b10[1048576], par[20][204800], conup[20][204800], condn[20][204800];
vector<int> ed[204800];

void maketree(int x, int p, int d) {
    depth[x] = d;
    par[0][x] = p;
    for (int i : ed[x]) {
        if (i == p) continue;
        maketree(i, x, d + 1);
    }
}

int query(int a, int b, int m) {
    int up = 0, down = 0, da = 0, db = 0;
    for (int i = 19; i >= 0; i--) {
        if (depth[a] - depth[b] > 0 && (((depth[a] - depth[b]) >> i) & 1)) {
            up = ((long long)up * b10[1 << i] + conup[i][a]) % m;
            a = par[i][a];
            da += (1 << i);
        }
        else if (depth[b] - depth[a] > 0 && (((depth[b] - depth[a]) >> i) & 1)) {
            down = (down + (long long)b10[db] * condn[i][b]) % m;
            b = par[i][b];
            db += (1 << i);
        }
    }
    for (int i = 19; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            up = ((long long)up * b10[1 << i] + conup[i][a]) % m;
            a = par[i][a];
            da += (1 << i);
            down = (down + (long long)b10[db] * condn[i][b]) % m;
            b = par[i][b];
            db += (1 << i);
        }
    }
    if (a != b) {
        up = (up * 10LL + conup[0][a]) % m;
        a = par[0][a];
        da++;
        down = (down + (long long)b10[db] * condn[0][b]) % m;
        b = par[0][b];
        db++;
    }
    return ((long long)up * b10[db + 1] + (long long)digit[a] * b10[db] + down) % m;
}

int main(void) {
    int n, m, q, a, b;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    maketree(1, -1, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i - 1][j] < 0) par[i][j] = -1;
            else par[i][j] = par[i - 1][par[i - 1][j]];
        }
    }

    b10[0] = 1;
    for(int i = 1; i < 1048576; i++) b10[i] = (b10[i - 1] * 10LL) % m;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &digit[i]);
        conup[0][i] = digit[i];
        condn[0][i] = digit[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            if (par[i][j] < 0) continue;
            conup[i][j] = ((long long)conup[i - 1][j] * b10[1 << (i - 1)] +
                conup[i - 1][par[i - 1][j]]) % m;
            condn[i][j] = (condn[i - 1][j] + (long long)condn[i - 1][par[i - 1][j]] *
                b10[1 << (i - 1)]) % m;
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%d %d", &a, &b);
        printf("%d\n", query(a, b, m));
    }
    return 0;
}