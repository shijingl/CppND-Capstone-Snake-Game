#include <fstream>
#include <sstream>
#include <iostream>
#include "SimpleData.h"

CoreData
SimpleData::ReadFile(const std::string& fileName) {
    std::string line, playerIDStr, scoreStr;
    std::ifstream filestream(fileName);
    ScoreMap scoreMap;
    SortedScoreMap sortedScoreMap;
    bool prevEnd = false;
    if (filestream.is_open()) {
        while (std::getline(filestream, line)) {
            std::istringstream linestream(line);
            linestream >> playerIDStr >> scoreStr;
            if (playerIDStr == "|") {
                prevEnd = true;
                continue;
            }
            size_t playerID{0}, score{0};
            try {
                playerID = std::stoi(playerIDStr);
                score = std::stoi(scoreStr);
            } catch (std::exception &err) {
                std::cerr<<"Conversion failure: "<< err.what() <<std::endl; 
            }
            if (not prevEnd) {
                scoreMap[playerID] = score;
            } else {
                sortedScoreMap[playerID] = score;
            }
        }
    }
    return CoreData(scoreMap, sortedScoreMap);
}

void 
SimpleData::WriteFile(const ScoreMap& score, 
                      const SortedScoreMap& sortedScore,
                      const std::string& fileName) {
    FILE* fw = fopen(fileName.c_str(), "wb");
    std::string totalString = ConvertDataToString<ScoreMap>(score).append("|").append(
        "\n").append(ConvertDataToString<SortedScoreMap>(sortedScore));
    fwrite(reinterpret_cast<u_char*>(&totalString[0]), totalString.size(), 1, fw);
    fclose(fw);
}