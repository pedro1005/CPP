#include "replace.hpp"

void replaceStr(const std::string &filename, const std::string &s1, const std::string &s2)
{
    // Open the input file
    std::ifstream inputFile(filename.c_str());  // c_str() to convert std::string to const char*
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }
    // Read the content of the file into a string (fileContent)
    std::string fileContent;
    std::string line;
    while (std::getline(inputFile, line))
        fileContent += line + '\n';
    inputFile.close();
    
    // Perform the replacement of all occurrences of s1 with s2 manually
    std::string result;
    size_t pos = 0;
    size_t findPos;
    while ((findPos = fileContent.find(s1, pos)) != std::string::npos)
    {
        // Append the part before the found substring and then the replacement
        result.append(fileContent.substr(pos, findPos - pos));
        result.append(s2);
        // Move the position forward, skipping the matched string
        pos = findPos + s1.length();
    }
    // Append the rest of the file content after the last occurrence of s1
    result.append(fileContent.substr(pos));
    // Create the output filename
    std::string outputFilename = filename + ".replace";
    // Open the output file for writing
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Could not create file " << outputFilename << std::endl;
        return;
    }
    // Write the modified content to the output file
    outputFile << result;
    outputFile.close();
    std::cout << "Replacement complete. Output saved to " << outputFilename << std::endl;
}