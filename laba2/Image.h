#pragma once
#include <vector>

typedef unsigned char uchar;

class Point
{
public:
    Point() = default;
    double x;
    double y;
};
class Line
{
public:
    Line(Point _begin, Point _end, double _thickness, int _brightness, double _gamma);
    Point begin{};
    Point end{};
    double thickness;
    int brightness;
    double gamma;
};
class PNM
{
public:
    PNM();
    ~PNM();
    bool Read(char*);
    bool Write(char*);
    bool DrawPoint(double x, double y, double transparency, double brightness);
    bool DrawPoint(double x, double y, double transparency, double brightness, double gamma);
    bool DrawLine(Line line);
    char format[2];
    int width;
    int height;
    int grade;
    int size;
    std::vector<uchar> pixels;
};

struct Input {
    char* fileInput = nullptr;
    char* fileOutput = nullptr;
    int brightness = 0;
    double thickness = 0;
    Point first = { 0, 0 };
    Point second = { 0, 0 };
    double gamma = 0;
};
