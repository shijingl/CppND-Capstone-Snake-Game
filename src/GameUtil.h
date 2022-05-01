#include <unordered_map>
#include <map>
#include <random>

using ScoreMap = std::unordered_map<size_t, size_t>;
using SortedScoreMap = std::map<size_t, size_t, std::greater<size_t>>;

class GameUtil {
    public:
        static size_t get_uuid() {
            std::random_device dev;
            std::mt19937 rng(dev());
            std::uniform_int_distribution<size_t> dist(0, 100000);
            size_t number = dist(rng);
            return number;
        }
};