// function loop(n: int, i: int, pi: float):
//     if i == n:
//         return pi
//     elif i is even:
//         pi = pi - 4 / (2 * i * (2 * i + 1))
//     else:
//         pi = pi + 4 / (2 * i * (2 * i + 1))

#include <stdio.h>

float loop(int n, int i, float pi) {
    if (i == n) {
        return pi;
    } else if (i % 2 == 0) {
        pi -= 4.0 / (2 * i * (2 * i + 1));
    } else {
        pi += 4.0 / (2 * i * (2 * i + 1));
    }
    return loop(n, i + 1, pi);
}

int main() {
    int n;
    printf("How many loops: ");
    scanf("%d", & n);
    printf("Pi ~= %.10f", loop(n, 1, 3.0));
}