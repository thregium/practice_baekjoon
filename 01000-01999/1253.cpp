#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

/*
문제 : N(N <= 2000)개의 정수(|| <= 10^9)가 주어질 때, 이 정수들 가운데 해당 정수와 다른 두 정수의 합인 정수의
개수를 구한다. 같은 값이더라도 다른 위치에 있다면 다른 정수이다.

해결 방법 : 모든 정수의 합을 키값으로 하여 해시맵에 저장한다. 그리고, 맵의 다른 값에는 합이 해당 값인 모든 조합에 들어가는
정수들의 번호를 저장한다. 이미 있는 값을 확인한다면 원래 있던 벡터의 값에서 새로운 조합에 들어가지 않는
정수들의 번호들을 빼 나간다.
이를 반복한 후, 각 정수에 대해 해시맵에서 값을 찾는다. 해시맵에 있다면 벡터에 있는 번호인지 확인하고
그것도 아닌 경우 조건을 만족하므로 결괏값을 1 올린다. 이를 반복해 모든 값을 찾으면 된다.

주요 알고리즘 : 자료 구조, 해시맵
*/

int a[2048];
unordered_map<int, vector<int>> mp;

int main(void) {
    int n, r = 0, t;
    std::unordered_map<int, vector<int>>::iterator it;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mp.find(a[i] + a[j]) == mp.end()) {
                mp.insert(pair<int, vector<int>>(a[i] + a[j], { i, j }));
            }
            else {
                it = mp.find(a[i] + a[j]);
                vector<int> v;
                for (int x : it->second) {
                    if (x == i || x == j) v.push_back(x);
                }
                it->second = v;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) != mp.end()) {
            it = mp.find(a[i]);
            t = 1;
            for (auto j : it->second) {
                if (j == i) t = 0;
            }
            r += t;
        }
    }
    printf("%d", r);
    return 0;
}