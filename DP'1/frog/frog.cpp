#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    std::cin >> N;

    // Vector para almacenar las alturas de las piedras
    std::vector<int> h(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> h[i];
    }

    // Si solo hay una piedra, el costo es 0 (no se mueve)
    if (N == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // dp[i] = el costo mínimo para llegar a la piedra i (usando 0-indexing)
    std::vector<int> dp(N);

    // --- Casos Base ---
    // El costo para llegar a la primera piedra es 0
    dp[0] = 0;
    // El costo para llegar a la segunda piedra solo puede ser desde la primera
    dp[1] = std::abs(h[1] - h[0]);

    for (int i = 2; i < N; ++i) {
        int cost_from_prev = dp[i - 1] + std::abs(h[i] - h[i - 1]);
        
        int cost_from_prev_prev = dp[i - 2] + std::abs(h[i] - h[i - 2]);
        
        dp[i] = std::min(cost_from_prev, cost_from_prev_prev);
    }

    std::cout << dp[N - 1] << std::endl;

    return 0;
}