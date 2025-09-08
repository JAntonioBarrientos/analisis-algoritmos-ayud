#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

// Usamos long long para evitar desbordamiento con las sumas, ya que los pesos pueden ser grandes.
using ll = long long;

// Variable global para almacenar la mínima diferencia encontrada.
// Se inicializa con un valor muy grande.
ll min_diff = -1;

/**
 * Función recursiva para explorar todas las combinaciones posibles.
 * @param index El índice de la manzana actual que estamos considerando.
 * @param sum1 La suma de los pesos del primer grupo.
 * @param sum2 La suma de los pesos del segundo grupo.
 * @param weights El vector con los pesos de todas las manzanas.
 */
void encontrarMinimo(int index, ll sum1, ll sum2, const std::vector<int>& weights) {
    // Caso base: si ya hemos considerado todas las manzanas.
    if (index == weights.size()) {
        ll current_diff = std::abs(sum1 - sum2);
        if (min_diff == -1 || current_diff < min_diff) {
            min_diff = current_diff;
        }
        return;
    }


    encontrarMinimo(index + 1, sum1 + weights[index], sum2, weights);

    // Opción 2: Añadir la manzana actual al segundo grupo.
    encontrarMinimo(index + 1, sum1, sum2 + weights[index], weights);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;

    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    // Iniciar la recursión desde la primera manzana (índice 0)
    encontrarMinimo(0, 0, 0, weights);

    std::cout << min_diff << std::endl;

    return 0;
}