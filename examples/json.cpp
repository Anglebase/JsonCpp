#include "jsoncpp/json.h"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <json_file>" << std::endl;
        return 1;
    }
    std::ifstream ifs(argv[1]);
    if (!ifs)
    {
        std::cout << "Failed to open file: " << argv[1] << std::endl;
        return 1;
    }
    std::string json_str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    ifs.close();
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(json_str, root);
    if (!parsingSuccessful)
    {
        std::cout << "Failed to parse JSON: " << reader.getFormattedErrorMessages() << std::endl;
        return 1;
    }
    std::cout << root << std::endl;
    return 0;
}