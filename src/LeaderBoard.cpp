#include <iostream>
#include "LeaderBoard.h"

template <typename KEY, typename VAL>
VAL GetOrDefault(const std::map<KEY, VAL, std::greater<KEY>> &map, const KEY & key, const VAL & defaultVAL) {
    typename std::map<KEY, VAL, std::greater<KEY>>::const_iterator it = map.find(key);
    if (it == map.end()) {
        return defaultVAL;
    }
    else {
        return it->second;
    }
}

void
LeaderBoard::addScore(const size_t playerID, const size_t score) {
    auto scoreRes = scores_.find(playerID);
    if (scoreRes == scores_.end()) {
        scores_[playerID] = score;
        sortedScores_[score] = GetOrDefault<size_t, size_t>(sortedScores_, score, 0) + 1;
    } 
    else {
        const size_t preScore = (scoreRes->second);
        const size_t playerCount = sortedScores_[preScore];

        if (playerCount == 1) {
            sortedScores_.erase(preScore);
        }
        else {
            sortedScores_[preScore] = playerCount - 1;
        }

        const size_t curScore = preScore + score;
        scores_[playerID] = curScore;
        sortedScores_[curScore] = GetOrDefault<size_t, size_t>(sortedScores_, curScore, 0) + 1;
    }
}

const size_t
LeaderBoard::top(const size_t k) {
    size_t count = 0;
    size_t sum = 0;
    std::map<size_t, size_t>::iterator it;
    for (it = sortedScores_.begin(); it != sortedScores_.end(); it++) {
        const size_t score = it->first;
        const size_t times = it->second;

        for (size_t i = 0; i < times; i++) {
            sum += score;
            count++;  

            if (count == k) {
                break;
            }         
        }

        if (count == k) {
            break;
        }
    }
    return sum;    
}

void
LeaderBoard::reset(const size_t playerID) {
    const int preScore = scores_[playerID];
    sortedScores_[preScore]--;
    if (sortedScores_[preScore] == 0) {
        sortedScores_.erase(preScore);
    }
    scores_.erase(playerID);
}

ScoreMap
LeaderBoard::getCurScores() {
    return scores_;
}

SortedScoreMap
LeaderBoard::getSortedScores() {
    return sortedScores_;
}

void
LeaderBoard::displayBoard(){
    std::cout<<"Top 10 players total scores: "<<top(10)<<std::endl;
    std::cout<<"Current LeaderBoard"<<std::endl;
    std::cout<<"PlayerID"<<", "<<"Scores"<<std::endl;
    std::unordered_map<size_t, size_t>::iterator it;

    for (it = scores_.begin(); it != scores_.end(); it++)
    {
        std::cout << it->first<<", "<<it->second<< std::endl;
    }
}