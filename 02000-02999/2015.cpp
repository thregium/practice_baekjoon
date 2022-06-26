#include <stdio.h>
#include <unordered_map>
using namespace std;

/*
���� : ���� N(N <= 200000)�� �迭�� ���� 10000 ������ �������� �ִ�.
�� �迭�� �������� K(|K| <= 2 * 10^9)�� ������ ������ ���Ѵ�.

�ذ� ��� : ���ʰ� �����ʺ����� ���� �� �迭�� ���� ���� ��, �����ʺ��� �������� ���鼭
�װ��� �����ʿ��� ������ ������ ���� �� �迭�� ������ �ϳ��� �ؽøʿ� �־� ������ �����Ѵ�.
���� ��ġ���� �����ʰ� ������ ���� �� K�� �Ǵ� ���� ������ �ᱣ���� ���س����� ���� �ȴ�.

�ֿ� �˰��� : �ڷ� ����, �ؽø�, ������
*/

int a[204800], lsum[204800], rsum[204800];
unordered_map<int, int> mp;

int main(void) {
    int n, k, s = 0;
    long long res = 0;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        lsum[i] = lsum[i - 1] + a[i];
        s += a[i];
    }
    mp.insert({ 0, 1 });
    for (int i = n; i >= 1; i--) {
        rsum[i] = rsum[i + 1] + a[i];
        if (mp.find(s - lsum[i - 1] - k) != mp.end()) res += mp[s - lsum[i - 1] - k];
        
        if (mp.find(rsum[i]) == mp.end()) mp.insert({ rsum[i], 1 });
        else mp[rsum[i]]++;
    }
    printf("%lld", res);

    return 0;
}