#include <fstream>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include "Pnm.h"
using namespace std;

Picture::Picture() : height(0), width(0), image(nullptr), CurrentCS(RGB)
{}

Picture::~Picture()
{
    delete[] image;
}

void Picture::OpenFile(string filename)
{
    ifstream input;
    input.open(filename, ios_base::in | ios_base::binary);
    if (!input.is_open())
        throw std::runtime_error("File error");
    string header;
    input >> header;
    if (header == "P5")
        color = false;
    else if (header == "P6")
        color = true;
    else
    {
        throw std::runtime_error("File has wrong format");
    }
    input >> width >> height;
    int maxvalue;
    input >> maxvalue;
    if (!input.good())
        throw std::runtime_error("Invalid metadata");
    if (maxvalue != 255)
        throw std::runtime_error("Unacceptable format");
    char partPixel;
    char* image_char = &partPixel;
    image = new Pixel[width * height];
    if (image == NULL)
        throw std::runtime_error("Out of memory");
    input.read(image_char, 1);
    for (int i = 0; i < width * height; i++)
    {
        if (color) {
            input.read(image_char, 1);
            image[i].A = *image_char;
            input.read(image_char, 1);
            image[i].B = *image_char;
            input.read(image_char, 1);
            image[i].C = *image_char;
        }
        else
        {
            input.read(image_char, 1);
            image[i].A = *image_char;
            image[i].B = *image_char;
            image[i].C = *image_char;
        }
    }
    if (!input.good())
        throw std::runtime_error("Reading error");
    input.close();
}

void Picture::SaveFile(std::string filename)
{
    ofstream output;
    output.open(filename, ios_base::out | ios_base::binary);
    if (!output.is_open())
        throw std::runtime_error("File writing error");
    if (color)
        output << "P6" << '\n';
    else
        output << "P5" << '\n';
    output << width << ' ' << height << '\n' << 255 << '\n';
    char* image_char = (char*)image;
    if (color)
        output.write(image_char, width * height * 3);
    else
    {
        for (int i = 0; i < width * height; i++)
            output.write(&image_char[i * 3], 1);
    }
    if (output.fail())
        throw std::runtime_error("File writing error");
    output.close();
}

void Picture::SetCS(ColorSpace newCS)
{
    CurrentCS = newCS;
}

void Picture::changeBrightness(double difference, double multiple)
{
    if (color)
    {
        if (CurrentCS == RGB)
        {
            for (int i = 0; i < width * height; i++) {
                int result = ((double)image[i].A - difference) * multiple;
                if (result > 255)
                    result = 255;
                if (result < 0)
                    result = 0;
                image[i].A = result;
                result = ((double)image[i].B - difference) * multiple;
                if (result > 255)
                    result = 255;
                if (result < 0)
                    result = 0;
                image[i].B = result;
                result = ((double)image[i].C - difference) * multiple;
                if (result > 255)
                    result = 255;
                if (result < 0)
                    result = 0;
                image[i].C = result;
            }
        }
        else
        {
            for (int i = 0; i < width * height; i++)
            {
                int result = ((double)image[i].A - difference) * multiple;
                if (result > 255)
                    result = 255;
                if (result < 0)
                    result = 0;
                image[i].A = result;
            }
        }
    }
    else
    {
        for (int i = 0; i < width * height; i++)
        {
            int result = ((double)image[i].A - difference) * multiple;
            if (result > 255)
                result = 255;
            if (result < 0)
                result = 0;
            image[i].A = result;
            image[i].B = result;
            image[i].C = result;
        }
    }
}

void Picture::autoBrightness()
{
    pair<int, int> max_min;
    max_min = BrightestAndDarkest();
    double difference = max_min.second, multiple = 255.0/((double)max_min.first - max_min.second);
    std::cout << "Difference: " << difference << ".\nMultiple: " << multiple << ".\n";
    changeBrightness(difference, multiple);
}

pair<int, int> Picture::BrightestAndDarkest()
{
    vector<int> pix;
    for (int i = 0; i < width * height; i++)
    {
        if ((color)&&(CurrentCS != YCbCr601))
        {
            pix.push_back(image[i].A);
            pix.push_back(image[i].B);
            pix.push_back(image[i].C);
        }
        else
        {
            pix.push_back(image[i].A);
        }

    }
    auto minmax = std::minmax_element(pix.begin(), pix.end());
    return {*minmax.second, *minmax.first};
}
