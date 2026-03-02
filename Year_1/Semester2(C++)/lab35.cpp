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

    // Equality check (optional, useful later)
    bool operator==(const Point& p) {
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

    Point getStart() { return point1; }
    Point getEnd() { return point2; }
};

// -------- Class Shape (abstract) --------
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
        for (int i = 0; i < count - 1; i++) {
            if (!(segments[i].getEnd() == segments[i + 1].getStart()))
                throw invalid_argument("Segments are not connected properly.");
        }

        for (int i = 0; i < count; i++)
            seg[i] = segments[i];
    }

    virtual float getArea() = 0;

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

// -------- Class Rectangle --------
class Rectangle : public Shape {
public:
    Rectangle(Segment* segments) : Shape(segments, 4) {
        // Additional validation if you want, e.g. check right angles
    }

    float getArea() override {
        // For rectangle, adjacent sides multiplied
        float side1 = getSeg(0).getLength();
        float side2 = getSeg(1).getLength();
        return side1 * side2;
    }
};

// -------- Main Function --------
int main() {
    Point A(0, 0), B(4, 0), C(4, 3), D(0, 3);

    Segment segments[4] = {
        Segment(A, B),
        Segment(B, C),
        Segment(C, D),
        Segment(D, A)
    };

    try {
        Rectangle rect(segments);

        cout << "Perimeter of rectangle: " << rect.getPerimeter() << endl;
        cout << "Area of rectangle: " << rect.getArea() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid argument: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
