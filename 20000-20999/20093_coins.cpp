#include "20093_coins.h"

/*
문제 : 0과 1이 쓰여진 64개의 칸들 중 한 칸의 상태를 반전시켜 특정한 칸 C를 찾는다.

해결 방법 : 모든 칸들 중 비트 상태가 1인 칸의 값들을 전부 XOR한다. 그 다음으로 C를 XOR하고 나온 결과의 칸을 뒤집는다.
그러면 비트 상태가 1인 값들을 XOR한 결과가 C가 된다.

주요 알고리즘 : 수학, 비트마스킹

출처 : IOI 2017 P3번
*/

std::vector<int> coin_flips(std::vector<int> b, int c) {
    std::vector<int> flips(1);
    int xors = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) xors ^= i;
    }
    xors ^= c;
    flips[0] = xors;
    return flips;
}

int find_coin(std::vector<int> b) {
    int xors = 0;
    for (int i = 0; i < b.size(); i++) {
        if (b[i]) xors ^= i;
    }
    return xors;
}
