#include "vector.h"
#include <iostream>
#include <stdexcept>
#include <locale.h>

void printMenu() {
    std::cout << "\n1. Ввести вектор 1\n";
    std::cout << "2. Ввести вектор 2\n";
    std::cout << "3. Показать векторы\n";
    std::cout << "4. Длина вектора 1\n";
    std::cout << "5. Длина вектора 2\n";
    std::cout << "6. Сложение\n";
    std::cout << "7. Вычитание\n";
    std::cout << "8. Векторное произведение\n";
    std::cout << "9. Умножение на число\n";
    std::cout << "10. Деление на число\n";
    std::cout << "11. Деление векторов\n";
    std::cout << "12. Косинус угла\n";
    std::cout << "13. Сравнение длин\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
}

int main() {
    Vector v1, v2;
    int choice = -1;
    setlocale(LC_ALL, "Russian");

    while (choice != 0) {
        printMenu();
        std::cin >> choice;

        try {
            if (choice == 1) {
                std::cout << "Введите x1 y1 z1 x2 y2 z2: ";
                std::cin >> v1;
            }
            else if (choice == 2) {
                std::cout << "Введите x1 y1 z1 x2 y2 z2: ";
                std::cin >> v2;
            }
            else if (choice == 3) {
                std::cout << "v1 = " << v1 << "\n";
                std::cout << "v2 = " << v2 << "\n";
            }
            else if (choice == 4) std::cout << "|v1| = " << v1.length() << "\n";
            else if (choice == 5) std::cout << "|v2| = " << v2.length() << "\n";
            else if (choice == 6) std::cout << "v1 + v2 = " << (v1 + v2) << "\n";
            else if (choice == 7) std::cout << "v1 - v2 = " << (v1 - v2) << "\n";
            else if (choice == 8) std::cout << "v1 x v2 = " << (v1 * v2) << "\n";
            else if (choice == 9) {
                double k; std::cout << "Введите число: "; std::cin >> k;
                std::cout << "v1 * k = " << (v1 * k) << "\n";
                std::cout << "v2 * k = " << (v2 * k) << "\n";
            }
            else if (choice == 10) {
                double k; std::cout << "Введите число: "; std::cin >> k;
                std::cout << "v1 / k = " << (v1 / k) << "\n";
                std::cout << "v2 / k = " << (v2 / k) << "\n";
            }
            else if (choice == 11) std::cout << "v1 / v2 = " << (v1 / v2) << "\n";
            else if (choice == 12) std::cout << "cos(v1, v2) = " << (v1 ^ v2) << "\n";
            else if (choice == 13) {
                if (v1 > v2)      std::cout << "|v1| > |v2|\n";
                else if (v1 < v2) std::cout << "|v1| < |v2|\n";
                else              std::cout << "|v1| == |v2|\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;
}