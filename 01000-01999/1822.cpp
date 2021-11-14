#include <stdio.h>
#include <set>
using namespace std;

/*
문제 : 크기 500000 이하의 두 집합 A, B가 주어질 때, A의 원소이면서 B의 원소가 아닌 것을 오름차순으로 출력한다.
각 집합의 원소는 2^31보다 작은 자연수이다. 한 집합에 같은 원소는 여러 번 주어지지 않는다.

해결 방법 : 셋에 집합 A의 원소들을 넣은 후, 집합 B를 입력받으며 집합 B의 원소 가운데 셋에 있는 원소들을 뺀다.
그 다음 셋을 순회하며 있는 원소들을 출력하면 된다.

주요 알고리즘 : 자료 구조, 셋
*/

set<int> amb;

int main(void) {
    int na, nb, x;
    scanf("%d %d", &na, &nb);
    for (int i = 0; i < na; i++) {
        scanf("%d", &x);
        amb.insert(x);
    }
    for (int i = 0; i < nb; i++) {
        scanf("%d", &x);
        if (amb.find(x) != amb.end()) amb.erase(x);
    }
    printf("%d\n", amb.size());
    for (int i : amb) {
        printf("%d ", i);
    }
    return 0;
}