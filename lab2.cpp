#include "point.h"

#include "point.h"

int main() {
    Triangle triangle;
    std::cout << "Введіть координати точки A: ";
    std::cin >> triangle.A.x >> triangle.A.y;

    std::cout << "Введіть координати точки B: ";
    std::cin >> triangle.B.x >> triangle.B.y;

    std::cout << "Введіть координати точки C: ";
    std::cin >> triangle.C.x >> triangle.C.y;

    if (isDegenerate(triangle)) {
        std::cout << "Трикутник вироджений!\n";
    }

    int methodChoice;
    std::cout << "\nОберіть метод перевірки приналежності точки:\n";
    std::cout << "1 - Векторний добуток\n";
    std::cout << "2 - Формула Герона\n";
    std::cout << "Ваш вибір: ";
    std::cin >> methodChoice;

    int n;
    std::cout << "Введіть к-сть точок для перевірки: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        Point P;
        std::cout << "Введіть координати точки " << i + 1 << ": ";
        std::cin >> P.x >> P.y;

        if (isPointOnTriangleEdge(triangle, P)) {
            std::cout << "Точка лежить на межі\n";
        } else {
            bool inside = false;
            if (methodChoice == 1)
                inside = isPointInTriangle(triangle, P);
            else if (methodChoice == 2)
                inside = isPointInTriangleHeron(triangle, P);
            else {
                std::cout << "Невірний вибір методу.\n";
                return 1;
            }

            if (inside)
                std::cout << "Точка лежить всередині трикутника\n";
            else
                std::cout << "Точка не належить трикутнику\n";
        }
    }

    return 0;
}

