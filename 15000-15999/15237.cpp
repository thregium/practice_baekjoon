#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <map>
using namespace std;

/*
문제 : N(N <= 1000)개의 수로 이루어진 배열(Ai <= 10^9)이 있을 때, 이 수을 등장 횟수와 처음 등장한 순서로 정렬한다.

해결 방법 : 등장 횟수는 multiset을 통해 관리하고, 처음 등장한 경우 map에 등장 위치를 저장해 놓는다.
그리고, 정렬시에 두 수를 multiset과 map에서 가져와서 비교하면 된다.

주요 알고리즘 : 정렬, 자료구조

출처 : AIPO 2017P 6번
*/

int a[1024];
multiset<int> s;
map<int, int> mp;

int cmp1(const void* a, const void* b) {
    int ac = s.count(*(int*)a); //a의 등장 횟수
    int bc = s.count(*(int*)b); //b의 등장 횟수
    if (ac != bc) return ac < bc ? 1 : -1;
    int ai = mp.find(*(int*)a)->second; //a의 첫 등장 시점
    int bi = mp.find(*(int*)b)->second; //b의 첫 등장 시점
    return ai > bi ? 1 : ai == bi ? 0 : -1;
    return 0;
}

int main(void) {
    int n, c;
    scanf("%d %d", &n, &c);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!s.count(a[i])) {
            mp.insert(pair<int, int>(a[i], i)); //a[i]가 처음 등장한 경우 숫자와 등장 위치를 매치시켜 놓는다.
        }
        s.insert(a[i]);
    }
    qsort(a, n, sizeof(int), cmp1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}