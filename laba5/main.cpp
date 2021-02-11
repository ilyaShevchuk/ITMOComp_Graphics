#include <iostream>
#include "Pnm.h"

int main(int argc, char* argv[])
{
    std::string input, output;
    Conversion CurrentConversion;
    double difference, multiple;
    if (argc < 4)
    {
        std::cerr << "Incorrect count of arguments\n";
        return 1;
    }
    input = argv[1];
    output = argv[2];
    if ((atoi(argv[3]) < 0)|| (atoi(argv[3]) > 6))
    {
        std::cerr << "Incorrect input\n";
        return 1;
    }
    CurrentConversion = static_cast<Conversion>(atoi(argv[3]));
    if ((CurrentConversion == RGB_SET) || (CurrentConversion == YCb_SET))
    {
        if (argc != 6)
        {
            std::cerr << "Incorrect count of arguments\n";
            return 1;
        }
        difference = atoi(argv[4]);
        multiple = atof(argv[5]);
    }
    Picture NewPic;
    if ((CurrentConversion == YCb_SET) || (CurrentConversion == YCb_HARD_AUTO) || (CurrentConversion == YCB_EASY_AUTO))
        NewPic.SetCS(YCbCr601);
    try
    {
        NewPic.OpenFile(input);
        if ((CurrentConversion == RGB_SET) || (CurrentConversion == YCb_SET))
            NewPic.changeBrightness(difference, multiple);
        else
            NewPic.autoBrightness();
        NewPic.SaveFile(output);
    }
    catch (const std::runtime_error error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
    return 0;
}