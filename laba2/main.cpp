#include <iostream>
#include "Image.h"
using namespace std;
int main(int argc, char** argv) {
    Input input;
    PNM image;
    bool flag;
    if (argc < 9 || argc > 10)
        cout<<"Bad count arguments";
    input.fileInput = argv[1];
    input.fileOutput = argv[2];
    input.brightness = atoi(argv[3]);
    input.thickness = atof(argv[4]);
    input.first.x = atof(argv[5]);
    input.first.y = atof(argv[6]);
    input.second.x = atof(argv[7]);
    input.second.y = atof(argv[8]);
    input.gamma = atof(argv[9]);
    Line DataForLine(input.first, input.second, input.thickness, input.brightness, input.gamma);
    flag = image.Read(input.fileInput);
    if (!flag)
        return 0;
    flag = image.DrawLine(DataForLine);
    if (!flag)
        return 0;

    flag = image.Write(input.fileOutput);
    if (!flag)
        return 0;

    return 0;
}