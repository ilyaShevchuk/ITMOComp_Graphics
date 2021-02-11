#include "Image.h"
#include <iostream>
#include <cmath>

using namespace std;

PNM::PNM()
{
    height = 0;
    width = 0;
    pixels;
}
PNM::~PNM()
{
    pixels.clear();
}
bool PNM::Read(char* file)
{
    FILE* f = fopen(file, "rb");
    if (f == nullptr){
        std::cout<<"Bad file with reading";
        return false;
    }
    fscanf(f, "%c%c\n%zu %zu\n%zu\n", &format[0], &format[1], &width, &height, &grade);
    if (format[1] - '0' != 5 || format[0] != 'P'){
        std::cout<<"Bad format";
        return false;
    }
    if (width < 0 || height < 0 || grade != 255){
        std::cout<<"Bad width/height/grade";
        return false;
    }
    size = width * height;
    uchar* old_pixels = new uchar[size];
    fread(old_pixels, sizeof(uchar), size, f);
    fclose(f);
    size = width * height;
    pixels.resize(size);
    for (size_t i = 0; i < size; i++)
        pixels[i] = old_pixels[i];
    delete[] old_pixels;
    return true;
}

bool PNM::DrawPoint(double x, double y, double clarity, double brightness) {
    clarity = max(min(clarity, 1.0), 0.0);
    if (y < 0 || y >= height || x < 0 || x >= width)
        return false;
    double lineColor = brightness / 255.0;
    double sRGBColor = pixels[y * width + x] / 255.0;
    double pixelsLineColor = sRGBColor <= 0.04045 ? sRGBColor / 12.92 : pow((sRGBColor + 0.055) / 1.055, 2.4);
    double c = (1 - clarity) * lineColor + clarity * pixelsLineColor;
    double sRGBc = c <= 0.0031308 ? 12.92 * c : 1.055 * pow(c, 1 / 2.4) - 0.055;
    pixels[width * y + x] = 255 * sRGBc;
    return true;
}
bool PNM::DrawPoint(double x, double y, double clarity, double brightness, double gamma) {
    clarity = max(min(clarity, 1.0), 0.0);
    if (y < 0 || y >= height || x < 0 || x >= width){
        return false;
    }
    int help_pix = width * y + x;
    double  help_float = (1.0 / gamma - 1.0) * (1.0 - clarity) + 1.0;
    pixels[help_pix] = 255 * pow((clarity * pixels[help_pix] + brightness * (1 - clarity)) / 255.0, help_float);
    return true;
}
bool PNM::DrawLine(Line line) {
    if (line.thickness <= 0){
        return false;
    }
    bool flag = true;
    bool xyFlag = abs(line.end.y - line.begin.y) > abs(line.end.x - line.begin.x);
    auto intPart = [](double value) -> int
    {
        return static_cast<int>(value);
    };
    auto plot = [&](double x, double y, double intensity) -> bool {
        if (line.gamma == 0) {
            if (xyFlag)
                flag = DrawPoint(y, x, 1.0 - intensity, line.brightness);
            else
                flag = DrawPoint(x, y, 1.0 - intensity, line.brightness);
        }
        else {
            if (xyFlag)
                flag = DrawPoint(y, x, 1.0 - intensity, line.brightness, line.gamma);
            else
                flag = DrawPoint(x, y, 1.0 - intensity, line.brightness, line.gamma);
        }
        return flag;
    };
    auto distance = [&](Point a, Point b) -> double {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    };
    if (xyFlag) {
        swap(line.begin.x, line.begin.y);
        swap(line.end.x, line.end.y);
    }
    if (line.begin.x > line.end.x) {
        swap(line.begin.x, line.end.x);
        swap(line.begin.y, line.end.y);
    }
    double dx = line.end.x - line.begin.x;
    double dy = line.end.y - line.begin.y;
    double gradient = dy / dx;
    double y = line.begin.y + gradient * (round(line.begin.x) - line.begin.x);
    bool big_flag;
    for (size_t x = round(line.begin.x); x <= round(line.end.x); x++) {
        int help_for = y - (line.thickness - 1) / 2;
        for (size_t plotY = help_for; plotY <= help_for + line.thickness; plotY++)
        {
            big_flag = plot(x, plotY, min(1.0, (line.thickness + 1.0) / 2.0 - fabs(y - plotY)));
            if (big_flag == false){
                cout<<"Bad coordinates";
                return false;
            }
        }
        y += gradient;
    }
    Point plotStart = { round(line.begin.x), round(line.begin.y) };
    Point plotEnd = { round(line.end.x), round(line.end.y) };
    for (size_t plotX = round(line.begin.x) - line.thickness / 2; plotX < round(line.begin.x); plotX++) {
        y = line.begin.y + gradient * (plotX - line.begin.x);
        int help_for2 =  static_cast<int>(y - (line.thickness - 1) / 2.0);
        for (int plotY = help_for2; plotY <= help_for2 + line.thickness; plotY++) {
            plot(plotX, plotY, min(1.0, (line.thickness + 0.5) / 2.0 -
                                        distance({static_cast<double>(plotX), static_cast<double>(plotY)},
                                                 {plotStart.x, plotStart.y})));
            cout<<big_flag;
            if (big_flag == false){
                cout<<"Bad coordinates";
                return false;
            }
        }

    }
    for (size_t plotX = round(line.end.x) + 1; plotX <= round(line.end.x) + line.thickness / 2; plotX++) {
        y = line.begin.y + gradient * (plotX - line.begin.x);
        for (int plotY = int(y - (line.thickness - 1) / 2.0); plotY <= int(y - (line.thickness - 1) / 2.0 + line.thickness); plotY++) {
            big_flag = plot(plotX, plotY, min(1.0, (line.thickness + 0.5) / 2.0 - distance({ static_cast<double>(plotX), static_cast<double>(plotY) }, { plotEnd.x, plotEnd.y })));
            if (big_flag == false) {
                cout << "Bad coordinates";
                return false;
            }
        }
    }
    return true;
}
bool PNM::Write(char* file)
{
    FILE* f = fopen(file, "wb");
    if (f == nullptr){
        std::cout<<"Bad file with writing";
        return false;
    }
    fprintf(f, "%c%c\n%zu %zu\n%d\n", format[0], format[1], width, height, grade);
    uchar* new_pixels = new uchar[size];
    for (size_t i = 0; i < size; i++)
        new_pixels[i] = pixels[i];
    fwrite(new_pixels, sizeof(uchar), size, f);
    delete[] new_pixels;
    fclose(f);
    return true;
}
Line::Line(Point _begin, Point _end, double _thickness, int _brightness, double _gamma)
{
    begin.x = _begin.x;
    end.x = _end.x;
    begin.y = _begin.y;
    end.y = _end.y;
    thickness = _thickness;
    brightness = _brightness;
    gamma = _gamma;
}