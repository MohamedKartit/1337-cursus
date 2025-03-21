#include "main.hpp"

bool checkArguments(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return false;
    }
    if (argv[1][0] == '\0') {
        std::cerr << "Error: Empty filename" << std::endl;
        return false;
    }
    if (argv[2][0] == '\0') {
        std::cerr << "Error: Empty s1" << std::endl;
        return false;
    }
    if (argv[3][0] == '\0') {
        std::cerr << "Error: Empty s2" << std::endl;
        return false;
    }
    return true;
}

bool openFiles(const std::string& filename, std::ifstream& inFile, const std::string& outFilename, std::ofstream& outFile) {
    inFile.open(filename.c_str());
    if (!inFile.is_open()) {
        std::cerr << "Error: Cannot open input file: " << filename << std::endl;
        return false;
    }

    outFile.open(outFilename.c_str());
    if (!outFile.is_open()) {
        std::cerr << "Error: Cannot create output file: " << outFilename << std::endl;
        inFile.close();
        return false;
    }

    return true;
}


std::string replaceAll(const std::string& str, const std::string& from, const std::string& to) {
    if (from.empty()) {
        return str;
    }
    std::string result;
    size_t start = 0;
    size_t pos;

    while ((pos = str.find(from, start)) != std::string::npos) {
        result.append(str, start, pos - start);
        result.append(to);
        start = pos + from.length();
    }
    result.append(str, start, str.length() - start);
    return result;
}

int main(int argc, char* argv[]) {
    if (!checkArguments(argc, argv)) {
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string outFilename = filename + ".replace";
    std::ifstream inFile;
    std::ofstream outFile;
    if (!openFiles(filename, inFile, outFilename, outFile)) {
        return 1;
    }
    std::string line;
    while (std::getline(inFile, line)) {
        outFile << replaceAll(line, s1, s2) << std::endl;
    }
    inFile.close();
    outFile.close();
    std::cout << "Replacement complete. Output written to: " << outFilename << std::endl;
    return 0;
}