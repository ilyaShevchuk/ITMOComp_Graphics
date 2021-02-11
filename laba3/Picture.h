#pragma once
#include <string>
#include <vector>
enum Result {
    OK,
    FILE_ERROR,
    OUT_OF_MEMORY,
    WRONG_FORMAT
};
enum DitheringType {
    NO_DITHERING ,
    ORDERED_8x8,
    RANDOM ,
    FLOYD_STEIN ,
    JJN ,
    SIERRA3,
    ATKINSON,
    HALFTONE_4x4
};
class Picture {
public:
    Picture(float correction_);
    ~Picture();
    Result OpenFile(std::string);
    Result SaveToFile(std::string);
    void Dither(DitheringType, unsigned int bits);
    void Fill();
private:
    int height;
    int width;
    unsigned char* image;
    float correction;
    double correct(double value);
    double back_correct(double value);
};
int FileMemoryErrors(Result error);