#include <iostream>

[[nodiscard]] constexpr double calculateTotal(double unitPrice, int quantity) noexcept {
    constexpr double discountThreshold = 1000.0;
    constexpr double discountRate = 0.10;

    const double subtotal = unitPrice * static_cast<double>(quantity);
    
    if (subtotal > discountThreshold) {
        return subtotal * (1.0 - discountRate);
    }
    
    return subtotal;
}

int main() {
    std::cout << calculateTotal(250.0, 5) << '\n';
    std::cout << calculateTotal(100.0, 2) << '\n';
    std::cout << calculateTotal(200.0, 5) << '\n';

    return 0;
}