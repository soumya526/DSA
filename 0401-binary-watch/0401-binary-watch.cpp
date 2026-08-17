#include <vector>
#include <string>

class Solution {
private:
    // LED values: first 4 for hours, last 6 for minutes
    const std::vector<int> leds = {1, 2, 4, 8, 1, 2, 4, 8, 16, 32};

    void backtrack(int turnedOn, int startIdx, int hour, int minute, std::vector<std::string>& result) {
        // Pruning invalid time constraints
        if (hour >= 12 || minute >= 60) {
            return;
        }

        // Base case: successfully selected the required number of LEDs
        if (turnedOn == 0) {
            result.push_back(std::to_string(hour) + (minute < 10 ? ":0" : ":") + std::to_string(minute));
            return;
        }

        // Try picking each remaining LED starting from startIdx
        for (int i = startIdx; i < 10; ++i) {
            if (i < 4) {
                // Hour LEDs
                backtrack(turnedOn - 1, i + 1, hour + leds[i], minute, result);
            } else {
                // Minute LEDs
                backtrack(turnedOn - 1, i + 1, hour, minute + leds[i], result);
            }
        }
    }

public:
    std::vector<std::string> readBinaryWatch(int turnedOn) {
        // Optimization: Max LEDs available are 3 (for hours max 11) + 5 (for minutes max 59) = 8
        if (turnedOn > 8) return {};

        std::vector<std::string> result;
        backtrack(turnedOn, 0, 0, 0, result);
        return result;
    }
};