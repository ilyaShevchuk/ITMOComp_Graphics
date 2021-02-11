#pragma once
#include <string>
#include <vector>
enum ColorSpace {
    YCbCr601,
    RGB
};
enum Conversion {
    RGB_SET = 0,
    YCb_SET = 1,
    RGB_EASY_AUTO = 2,
    YCB_EASY_AUTO = 3,
    RGB_HARD_AUTO = 4,
    YCb_HARD_AUTO = 5
};
struct Pixel {
    unsigned char A;
    unsigned char B;
    unsigned char C;
};
class Picture {
public:
    Picture();
    ~Picture();
    void OpenFile(std::string);
    void SaveFile(std::string);
    void SetCS(ColorSpace);
    void changeBrightness(double difference, double multiple);
    std::pair<int, int> BrightestAndDarkest();
    void autoBrightness();
private:
    int height;
    int width;
    Pixel* image;
    ColorSpace CurrentCS;
    bool color;
};