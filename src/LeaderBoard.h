#include "GameUtil.h"

// idea inspired by https://leetcode.com/problems/design-a-leaderboard/, code is originated.
class LeaderBoard {
    public:
        LeaderBoard(ScoreMap loadedScores, SortedScoreMap loadedSortedScores) {
            this->scores_ = loadedScores;
            this->sortedScores_ = loadedSortedScores;
        }
        void addScore(const size_t playerID, const size_t score);
        const size_t top(const size_t k);
        void reset(const size_t playerID);
        void displayBoard();
        ScoreMap getCurScores();
        SortedScoreMap getSortedScores();

    private:
        SortedScoreMap sortedScores_;
        ScoreMap scores_;
};