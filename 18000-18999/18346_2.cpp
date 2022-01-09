#include <stdio.h>
#include <vector>
#define MOD 1000000007
using namespace std;

/*
문제 : N(N <= 100000)개의 정점과 M(M <= 200000)개의 간선으로 이루어진 그래프가 있다.
이 그래프의 각 정점은 흰색 또는 검은색으로 칠해져 있다. 이때, 대륙 서부 기준으로는 서로 같은 색인 정점이 연결된 간선을 골라
그 간선에 연결된 정점의 색을 동시에 바꿀 수 있고, 동부 기준으로는 둘 중 하나의 색을 바꿀 수 있다.
이때, 현재 그래프에서 대륙 서부 기준으로 만들 수 있는 그래프와 동부 기준으로 만들 수 있는 그래프의 개수를 구한다.

해결 방법 : 그래프를 이분 그래프 형태로 바꾼 후(이분 그래프가 되지 않는 간선은 그대로 둠),
이분 그래프의 한쪽 정점의 색을 바꾸면 서로 다른 색인 간선의 색을 바꾸는 문제가 된다.
이를 잘 이용하면 대륙 서부에서는 이분 그래프인 경우 N_C_K(K는 색을 바꾼 후 흰색의 개수)가지로 바꿀 수 있음을 알 수 있고,
그 외의 경우에는 2^(N - 1)가지로 바꿀 수 있다.
대륙 동부 기준으로는 차수가 3 이상인 정점이 있는 경우와 없는 경우가 나뉘게 된다.
각 경우에서 이분 그래프 여부와 사이클 여부등을 따져가며 풀이를 하면 된다.
연결 요소가 여러 개인 경우 전부 곱해야 함에 유의한다.

주요 알고리즘 : 그래프 이론, 케이스 워크, 이분 그래프, 조합론

출처 : 제1 전시관 5번
*/

int vis[103000], fact[103000];
char color[103000];
vector<int> ed[103000];

long long mult(long long x, long long y) {
    //X^Y을 반환한다.
    if (y == 0) return 1;
    else if (y == 1) return x;
    else {
        long long z = mult(x, y >> 1);
        if (y & 1) return (((z * z) % MOD) * x) % MOD;
        else return (z * z) % MOD;
    }
}

void unvis(int x) {
    //X의 연결요소에 대한 방문을 초기화한다.
    vis[x] = 0;
    for (int i : ed[x]) {
        if (vis[i]) unvis(i);
    }
}

int bip(int x, int c) {
    //X의 연결요소가 이분 그래프인지 여부(부호)와 연결 요소의 크기(값)를 반환한다.
    int r = 1, t;
    vis[x] = c;
    for (int i : ed[x]) {
        if (vis[i] == c && r > 0) r *= -1;
        else if (!vis[i]) {
            t = bip(i, (!(c - 1)) + 1);
            if ((t > 0 && r > 0) || (t < 0 && r < 0)) r += t;
            else if (r > 0) {
                r *= -1;
                r += t;
            }
            else r -= t;
        }
    }
    return r;
}

int getcntw(int x) {
    //색을 바꾼 후 흰색 정점의 개수를 반환한다.
    int r = 0;
    if ((vis[x] == 1 && color[x - 1] == '0') || (vis[x] == 2 && color[x - 1] == '1')) r++;
    vis[x] = 3;
    for (int i : ed[x]) {
        if (vis[i] < 3) r += getcntw(i);
    }
    return r;
}

int getcntt(int x) {
    //차수가 3 이상인 정점의 개수를 반환한다.
    int r = (ed[x].size() >= 3);
    vis[x] = 1;
    for (int i : ed[x]) {
        if (!vis[i]) r += getcntt(i);
    }
    return r;
}

int isbi(int x) {
    //모든 정점의 색이 같은 지 여부를 반환한다.
    int r = 3;
    if (color[x - 1] == '0') r ^= 1;
    else r ^= 2;
    vis[x] = 3;
    for (int i : ed[x]) {
        if (vis[i] < 3) r &= isbi(i);
    }
    return r;
}

int iscycle(int x, int l) {
    //사이클인지 여부를 반환한다.
    int r = 0;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (i == l) continue;
        if (vis[i]) r = 1;
        else r != iscycle(i, x);
    }
    return r;
}

int samecount(int x, int l) {
    //색이 같은 간선의 개수 * 2를 반환한다.
    int r = 0;
    vis[x] = 1;
    for (int i : ed[x]) {
        if (color[x - 1] == color[i - 1]) r++;
        if (i == l) continue;
        if (!vis[i]) r += samecount(i, x);
    }
    return r;
}

long long comb(long long n, long long k) {
    //N_C_K의 값을 반환한다.
    return ((long long)fact[n] * mult(((long long)fact[k] * fact[n - k]) % MOD, MOD - 2)) % MOD;
}

int main(void) {
    int n, m, a, b, c, d, wo = 0, eo = 0, w = 1, e = 1;
    fact[0] = 1;
    for (long long i = 1; i <= 100000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    scanf("%d %d", &n, &m);
    //if (n > 21) return 1;
    scanf("%s", color);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            a = getcntt(i);
            unvis(i);
            b = bip(i, 1);
            //대륙 서부식
            if (b < 0) {
                //이분 그래프가 아닌 경우
                b *= -1;
                c = 1;
                for (int j = 1; j < b; j++) c = (c * 2) % MOD;
                w = ((long long)w * c) % MOD;
            }
            else {
                //이분 그래프인 경우
                c = getcntw(i);
                w = ((long long)w * comb(b, c)) % MOD;
            }

            unvis(i);
            b = bip(i, 1);
            //동부식
            if (a) {
                //3차 이상의 정점이 있는 경우
                if (b > 0 && (c == b || c == 0)) continue; //더이상 움직일 수 없을 때
                else {
                    if (b < 0) b *= -1;
                    c = 1; //그 외의 경우 계산
                    for (int j = 0; j < b; j++) c = (c * 2) % MOD;
                    if (isbi(i)) e = ((long long)e * (c + MOD - 1)) % MOD;
                    else e = ((long long)e * (c + MOD - 2)) % MOD;
                }
            }
            else {
                //3차 이상의 정점이 없는 경우
                unvis(i);
                a = iscycle(i, -1);
                unvis(i);
                c = samecount(i, -1);
                if (b < 0) b *= -1;
                c >>= 1;
                if (a) {
                    //사이클
                    d = 0;
                    if (b & 1) {
                        //길이가 홀수
                        for (int i = 0; i * 2 + 1 <= c; i++) {
                            d = (d + 2LL * comb(b, i * 2 + 1)) % MOD;
                        }
                    }
                    else {
                        //길이가 짝수
                        for (int i = 0; i * 2 <= c; i++) {
                            d = (d + 2LL * comb(b, i * 2)) % MOD;
                        }
                    }
                    if (c == 0 || c == b) d = (d + MOD - 1) % MOD;
                }
                else {
                    //단순 경로
                    c++;
                    d = comb(b - 1, c - 1);
                    for (int i = 0; i < c - 1; i++) {
                        d = (d + 2LL * comb(b - 1, i)) % MOD;
                    }
                }
                e = ((long long)e * d) % MOD;
            }
        }
    }

    printf("%d %d\n", w, e);
    return 0;
}