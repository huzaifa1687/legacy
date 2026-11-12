#include <iostream>

constexpr double DISCOUNT_THRESHOLD = 1000.0;
constexpr double DISCOUNT_RATE = 0.10;

[[nodiscard]] constexpr double applyDiscount(double subtotal) noexcept {
    if (subtotal > DISCOUNT_THRESHOLD) {
        return subtotal * (1.0 - DISCOUNT_RATE);
    }
    return subtotal;
}

[[nodiscard]] constexpr double calculateOrderTotal(double unitPrice, int quantity) noexcept {
    const double subtotal = unitPrice * static_cast<double>(quantity);
    return applyDiscount(subtotal);
}

int main() {
    std::cout << calculateOrderTotal(250.0, 5) << '\n';
    std::cout << calculateOrderTotal(100.0, 2) << '\n';
    std::cout << calculateOrderTotal(200.0, 5) << '\n';

    return 0;
}