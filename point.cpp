#include "point.h"

// Обчислення векторного добутку
double Vdob(double x1, double y1, double x2, double y2) {
    return x1 * y2 - y1 * x2;
}


// Геронова формула для площі трикутника за трьома сторонами
double heronArea(double a, double b, double c) {
    double s = (a + b + c) / 2.0; // півпериметр
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

// Обчислення відстані між двома точками
double distance(Point& p1, Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y));
}

// Перевірка належності точки трикутнику за допомогою Герона
bool isPointInTriangleHeron(Triangle& tri, Point& P) {
    // Перевірка, чи трикутник вироджений
    if (isDegenerate(tri)) {
        // Якщо трикутник вироджений, перевірка на межі з використанням векторного добутку
        return isPointOnTriangleEdge(tri, P); // Перевіряємо, чи точка на межі трикутника
    }

    double AB = distance(tri.A, tri.B);
    double BC = distance(tri.B, tri.C);
    double CA = distance(tri.C, tri.A);

    double AP = distance(tri.A, P);
    double BP = distance(tri.B, P);
    double CP = distance(tri.C, P);

    double S_main = heronArea(AB, BC, CA);
    double S1 = heronArea(AP, BP, AB);
    double S2 = heronArea(BP, CP, BC);
    double S3 = heronArea(CP, AP, CA);

    double S_sum = S1 + S2 + S3;

    if (std::fabs(S_main - S_sum) < 1e-3) {
        return true;  // Точка належить трикутнику
    }

    if (std::fabs(S_main - S_sum) < 1e-1) {
       
        return true;
    }

    return false;
}




// Перевірка, чи трикутник вироджений (площа = 0)
bool isDegenerate(Triangle& tri) {
    double cross = Vdob(tri.B.x - tri.A.x, tri.B.y - tri.A.y,
        tri.C.x - tri.A.x, tri.C.y - tri.A.y);
    return (std::fabs(cross) < 1e-3);
}

// Перевірка, чи точка P лежить на відрізку AB

bool isPointOnEdge(Point& A, Point& B, Point& P) {
    double dAP = distance(A, P);
    double dPB = distance(P, B);
    double dAB = distance(A, B);

    // Перевірка, чи A+P+B = AB
    return std::fabs((dAP + dPB) - dAB) < 1e-3;
}

// Перевірка, чи точка P лежить на межі трикутника

bool isPointOnTriangleEdge(Triangle& tri,Point& P) {
    return isPointOnEdge(tri.A, tri.B, P) || isPointOnEdge(tri.B, tri.C, P) || isPointOnEdge(tri.C, tri.A, P);
}

// Перевірка, чи точка P лежить всередині трикутника (виключаючи межі)

bool isPointInTriangle(Triangle& tri, Point& P) {
    double dobABP = Vdob(tri.B.x - tri.A.x, tri.B.y - tri.A.y, P.x - tri.A.x, P.y - tri.A.y);
    double dobBCP = Vdob(tri.C.x - tri.B.x, tri.C.y - tri.B.y, P.x - tri.B.x, P.y - tri.B.y);
    double dobCAP = Vdob(tri.A.x - tri.C.x, tri.A.y - tri.C.y, P.x - tri.C.x, P.y - tri.C.y);

    bool allPositive = (dobABP > 0 && dobBCP > 0 && dobCAP > 0);
    bool allNegative = (dobABP < 0 && dobBCP < 0 && dobCAP < 0);
    return (allPositive || allNegative);
}
