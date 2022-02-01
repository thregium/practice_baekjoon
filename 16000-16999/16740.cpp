#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 5000)개의 서로 다른 음이 아닌 정수(<= 10^9)가 주어질 때, 이 정수의 목록 가운데
가장 긴 등차수열의 길이를 구한다.

해결 방법 : 우선 모든 수를 정렬한 다음, 작은 수부터 차례로 확인해 나간다.
각 수마다 다음 수를 각각 선택하면서 나올 수 있는 가장 긴 등차수열을 확인한다.
각 수마다 확인한 공차를 해시셋을 이용해 기록하고, 이미 확인한 수가 나오면 다음 공차를 찾는다.
이를 반복하여 중간에 나오는 가장 긴 등차수열의 길이를 구하면 된다.
시간을 줄이기 위해 reserve()를 미리 해 주는 것이 좋다.

주요 알고리즘 : 자료 구조, 해시셋, 해시맵, 정렬

출처 : Yokohama 2018 B번
*/

int v[5120];
unordered_set<int> vis[5120];
unordered_map<int, int> rv;

int cmp1(const void* a, const void* b) {
    int ai = *(int*)a;
    int bi = *(int*)b;
    return ai > bi ? 1 : ai == bi ? 0 : -1;
}

int main(void) {
    long long n, c, r = 1, x, y, p;
    //freopen("E:\\PS\\ICPC\\Asia Pacific\\Japan Regional\\2018\\icpc2018data\\B\\59.in", "r", stdin);
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    qsort(v, n, sizeof(int), cmp1);
    for (long long i = 0; i < n; i++) {
        rv.insert(pair<int, int>(v[i], i));
        vis[i].reserve(5120);
    }
    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            p = v[j] - v[i];
            if (vis[i].find(p) != vis[i].end()) continue;
            c = 1;
            y = i;
            while (1) {
                x = y;
                if (rv.find(v[i] + p * c) == rv.end() || vis[x].find(p) != vis[x].end()) break;
                else {
                    y = rv[v[i] + p * c++];
                    vis[x].insert(p);
                }
            }
            if (c > r) r = c;
        }
        vis[i].clear();
    }
    printf("%lld\n", r);
    return 0;
}