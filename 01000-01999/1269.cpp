#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : 두 자연수의 집합이 주어질 때, 두 집합의 대칭차집합에 속하는 원소의 수를 구한다.

해결 방법 : 셋에 첫 번째 집합의 모든 원소를 넣은 다음, 두 번째 집합에서 해당 원소가 있다면 결괏값에서 1만큼 빼고
없다면 1만큼 더한다. 나온 결괏값에서 첫 번째 집합의 원소의 수를 구하면 답이 된다.

주요 알고리즘 : 자료구조, 셋
*/

set<int> s;

int main(void) {
    int a, b, x, r;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", &x);
        s.insert(x);
    }
    r = a;
    for (int i = 0; i < b; i++) {
        scanf("%d", &x);
        if (s.find(x) != s.end()) r--;
        else r++;
    }
    printf("%d", r);
    return 0;
}