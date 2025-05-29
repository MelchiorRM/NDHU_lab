#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:
    float x, y;

public:
    // Default constructor
    Point() : x(0), y(0) {}

    // Constructor with parameters
    Point(float x, float y) : x(x), y(y) {}

    // Accessors
    float getX() const { return x; }
    float getY() const { return y; }

    // Mutators
    void setX(float xVal) { x = xVal; }
    void setY(float yVal) { y = yVal; }

    // Print the point in format "(x, y)"
    void printPoint() const
    {
        cout << "(" << x << ", " << y << ")";
    }

    // Calculate distance to another point
    float getDistance(const Point &other) const
    {
        float dx = x - other.x;
        float dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class Segment
{
private:
    Point point1, point2;

public:
    // Default constructor
    Segment() : point1(), point2() {}

    // Constructor with two points
    Segment(const Point &p1, const Point &p2) : point1(p1), point2(p2) {}

    // Return the length of the segment
    float getLength() const
    {
        return point1.getDistance(point2);
    }
};
