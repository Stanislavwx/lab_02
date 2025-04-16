#ifndef POINT_H
#define POINT_H

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

struct Point {
    double x;
    double y;
};

double distance(Point& p1, Point& p2);

struct Triangle {
    Point A, B, C;
};

double Vdob(double x1, double y1, double x2, double y2);

bool isDegenerate(Triangle& tri);

bool isPointOnEdge(Point& A, Point& B, Point& P);


bool isPointOnTriangleEdge(Triangle& tri,Point& P);


bool isPointInTriangle(Triangle& tri, Point& P);

#endif
