#include "LeaderBoard.h"


struct CoreData {
    CoreData (const ScoreMap& sm,  const SortedScoreMap& ssm)
    {
        scoreMap = sm;
        sortedScoreMap = ssm;
    }
    ScoreMap scoreMap;
    SortedScoreMap sortedScoreMap;
};


template <typename MAP>
std::string ConvertDataToString(const MAP& m) {
    typename MAP::const_iterator it;
    std::string totalString;
    for (it = m.begin(); it != m.end(); it++) {
        totalString.append(std::to_string(it->first)).append(" ").append(
            std::to_string(it->second)).append("\n");
    }
    return totalString;
}


namespace SimpleData {
    void WriteFile(const ScoreMap& score,
                   const SortedScoreMap& sortedScore, 
                   const std::string& fileName);
    CoreData ReadFile(const std::string& fileName);
};