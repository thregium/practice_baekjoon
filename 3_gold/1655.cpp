#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> pql;
priority_queue<int, vector<int>, greater<int>> pqh;

int main(void) {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (pql.size() == 0 || x <= pql.top()) {
            pql.push(x);
        }
        else {
            pqh.push(x);
        }
        while (pqh.size() > pql.size()) {
            pql.push(pqh.top());
            pqh.pop();
        }
        while (pql.size() > pqh.size() + 1) {
            pqh.push(pql.top());
            pql.pop();
        }
        printf("%d\n", pql.top());
    }
    return 0;
}