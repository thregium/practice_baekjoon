#include <stdio.h>
#include <string>
#include <unordered_map>
using namespace std;

/*
문제 : 10자 이하의 숫자로 이루어진 다이얼 잠금장치가 있다. 이 장치에서 연속한 숫자들을 같이 돌리는 것이
가능하다면, 다이얼 잠금장치를 맞추기 위해 돌려야 하는 최소 횟수를 구한다.

해결 방법 : 매번 돌릴 때 마다 가장 왼쪽 또는 오른쪽 칸을 맞춰야 장치를 맞추는 최단 횟수가 된다.
따라서, 그러한 각 방법들을 백트래킹을 통해 하나씩 해 나가면 된다. 단, 이 과정에서 이미 나왔던 경우는
메모이제이션을 통해 빠르게 해결해야 시간 내에 돌아가는 것이 가능하다.

주요 알고리즘 : DP, 백트래킹

출처 : JAG 2009S2 C번
*/

char locka[16], lockb[16];
unordered_map<string, int> mem;

int track(string a, string b, int st, int ed) {
    if (a == b) return 0;
    if (mem.find(a) != mem.end()) return mem[a];
    while (a[st] == b[st]) st++;
    while (a[ed] == b[ed]) ed--;
    int res = 103000, inner, diff;
    string orig = a;
    diff = (b[st] - orig[st] + 10) % 10;
    for (int i = st; i <= ed; i++) {
        a[i] = (a[i] - '0' + diff) % 10 + '0';
        inner = track(a, b, st + 1, ed);
        if (inner + 1 < res) res = inner + 1;
        if (res == 1) {
            mem.insert({ orig, res });
            return res;
        }
    }
    a = orig;
    diff = (b[ed] - orig[ed] + 10) % 10;
    for (int i = ed; i >= st; i--) {
        a[i] = (a[i] - '0' + diff) % 10 + '0';
        inner = track(a, b, st, ed - 1);
        if (inner + 1 < res) res = inner + 1;
        if (res == 1) {
            mem.insert({ orig, res });
            return res;
        }
    }
    mem.insert({ orig, res });
    return res;
}

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%s %s", locka, lockb);
        printf("%d\n", track(locka, lockb, 0, n - 1));
        mem.clear();
    }
    return 0;
}