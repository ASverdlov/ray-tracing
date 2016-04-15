#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include <array>
#include <vector>

namespace geom {

struct Point {
    Point operator+(const Point&) const;
    Point operator-(const Point&) const;
    float operator*(const Point&) const;

    float len() const;
    void printLog() const;

    float x, y, z;
};

class Transform {
public:
    Transform();
    Transform(const std::array<std::array<float, 3>, 3>&);

    Point operator*(const Point&) const;

    //Transform operator*(const Transform&) const;
    Transform T() const;

    void printLog() const;

    //Transform getXRotation(float angle) const;
    //Transform getYRotation(float angle) const;
    Transform getZRotation(float angle) const;

private:
    std::array<std::array<float, 3>, 3> matrix;
};

class Line {
public:
    Line() = default;
    Line(const Point&, const Point&);

    Point getStart() const;
    Point getDirection() const;

private:
    Point start;
    Point direction;
};

class IPrimitive {
public:
    virtual bool intersects(const Line& line) const = 0;
    virtual void printLog() const = 0;
};


class Sphere : public IPrimitive {
public:
    Sphere() = default;
    Sphere(const Point&, float);

    Point getCenter() const;
    float getRadius() const;

    bool intersects(const Line&) const;
    void printLog() const;

private:
    Point center;
    float radius;
};

/*
class Triangle : public IPrimitive {
private:
    array<Point, 3> points;
};

class Parallelogram : public IPrimitive {
};

class Quadrangle : public Primitive {
}; */

} // namespace geom

#endif
