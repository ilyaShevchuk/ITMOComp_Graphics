#include <iostream>
#include <string>
#include "Picture.h"
using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 7)
    {
        cerr << "Wrong count of arguments\n";
        return 1;
    }
    string input_name = argv[1], output_name = argv[2];
    bool gradient;
    int argv3_int = atoi(argv[3]);
    if (argv3_int == 1)
        gradient = true;
    else if (argv3_int == 0)
        gradient = false;
    else
    {
        cerr << "Invalid arguments\n";
        return 1;
    }
    DitheringType NewDither = (DitheringType)atoi(argv[4]);
    Picture NewPicture(atof(argv[6]));
    int bits = atoi(argv[5]);
    Result current_result;
    current_result = NewPicture.OpenFile(input_name);
    if (FileMemoryErrors(current_result) == -1)
        return 1;
    if (gradient)
        NewPicture.Fill();
    NewPicture.Dither(NewDither, bits);
    current_result = NewPicture.SaveToFile(output_name);
    if (FileMemoryErrors(current_result) == -1)
        return 1;
    return 0;
}