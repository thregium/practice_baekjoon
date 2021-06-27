#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

/*
문제 : 모자를 C(C <= 100000)개 갖고 있고, 모자 걸이는 C - 1개 갖고 있다. i번째 모자걸이는 왕복하는데 im가 걸린다. 
이때 모자를 N(N <= 100000)번 갈아써야 할 때, 주어진 순서로 모자를 갈아쓰기 위해 필요한 최소 움직임 횟수와
그때의 초기 상태의 모자걸이를 구한다. 단, 첫 번째로 주어지는 모자는 이미 쓰고 있다고 가정한다.

해결 방법 : 각 모자걸이에 모자를 갈아끼우더라도 모자를 갈아쓰는데 필요한 모자걸이는 처음 상태의 모자걸이에서
걸려있던 모자와 1대1 대응이 가능하다. 따라서, 처음 모자에 대응하는 모자걸이를 각각 몇 회 사용하는지 센 후
많이 사용하는 순으로 정렬하면 된다. 이때, 첫 모자는 이미 쓰고 있기 때문에 미리 빼놓아야 한다.

주요 알고리즘 : 그리디 알고리즘, 정렬

출처 : UKIEPC 2019 H번
*/

int cnt[103000][2];
map<int, int> mp;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai < bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    int c, n, p, fp = 0, x, q;
    long long r = 0;
    //freopen("E:\\PS\\ICPC\\Europe\\UKIEPC\\2019\\hatstand\\data\\secret\\07.in", "r", stdin);
    scanf("%d %d", &c, &n);
    scanf("%d", &fp);
    for (int i = 1; i <= c; i++) {
        cnt[i][1] = i;
        if (i == fp) continue;
        mp.insert(pair<int, int>(i, i));
    }
    p = fp;
    for (int i = 2; i <= n; i++) {
        scanf("%d", &x);
        q = mp.find(x)->second;
        cnt[q][0]++;
        mp.erase(x);
        mp.insert(pair<int, int>(p, q));
        p = x;
    }
    qsort(cnt + 1, c, sizeof(int) * 2, cmp1);
    q = 0;
    for (long long i = 1; i <= c; i++) {
        r += (i - q) * cnt[i][0];
    }
    printf("%lld\n", r);
    for (int i = 1; i <= c; i++) {
        if (cnt[i][1] == fp) continue;
        printf("%d ", cnt[i][1]);
    }
    return 0;
}