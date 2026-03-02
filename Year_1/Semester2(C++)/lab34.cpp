#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// -------- Class Point --------
class Point {
private:
    float x, y;

public:
    Point() : x(0), y(0) {}
    Point(float a, float b) : x(a), y(b) {}

    void printPoint() { cout << "(" << x << ", " << y << ")"; }

    float getX() { return x; }
    float setX(float c) { x = c; return x; }

    float getY() { return y; }
    float setY(float d) { y = d; return y; }

    float getDistance(Point e) {
        float dx = x - e.x;
        float dy = y - e.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool operator==(const Point& p) const {
        return fabs(x - p.x) < 1e-6 && fabs(y - p.y) < 1e-6;
    }
};

// -------- Class Segment --------
class Segment {
private:
    Point point1;
    Point point2;

public:
    Segment() : point1(Point()), point2(Point()) {}
    Segment(Point p1, Point p2) : point1(p1), point2(p2) {}

    float getLength() {
        return point1.getDistance(point2);
    }

    Point getStart() 
    { return point1; }
    Point getEnd() 
    { return point2; }
};

// -------- Abstract Class Shape --------
class Shape {
private:
    Segment seg[10];
    int edgeCount;

public:
    Shape() : edgeCount(0) {}

    Shape(Segment* segments, int count) : edgeCount(count) {
        if (count < 3 || count > 10)
            throw invalid_argument("Shape must have 3 to 10 edges.");

        // Check closed path: last segment end == first segment start
        if (!(segments[0].getStart() == segments[count - 1].getEnd()))
            throw invalid_argument("Segments do not form a closed path.");

        // Check continuity between segments
        for (int i = 0; i < count - 1; ++i) {
            if (!(segments[i].getEnd() == segments[i + 1].getStart()))
                throw invalid_argument("Segments are not connected properly.");
        }

        for (int i = 0; i < count; i++)
            seg[i] = segments[i];
    }

    virtual float getArea() = 0; // Pure virtual: must be implemented by derived classes

    float getPerimeter() {
        float perimeter = 0;
        for (int i = 0; i < edgeCount; i++) {
            perimeter += seg[i].getLength();
        }
        return perimeter;
    }

    Segment& getSeg(int index) {
        if (index < 0 || index >= edgeCount)
            throw out_of_range("Index out of range");
        return seg[index];
    }

    int getEdgeCount() { return edgeCount; }
};
