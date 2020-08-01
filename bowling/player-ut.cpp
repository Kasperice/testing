#include <gtest/gtest.h>

#include <vector>

#include "player.hpp"

struct TestPlayer : public ::testing::Test {
    Player player;
    std::vector<std::pair<int, int>> score{};
};

TEST_F(TestPlayer, checkScoreGameOfAllMisses) {
    for (auto it = 0; it < 10; it++) {
        score.emplace_back(0, 0);
    }
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 0);
}

TEST_F(TestPlayer, checkScoreGameOfAllOnes) {
    for (auto it = 0; it < 10; it++) {
        score.emplace_back(1, 1);
    }
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 20);
}

TEST_F(TestPlayer, checkScoreGameWithoutSpareAndStrike) {
    score = {{1, 5}, {2, 5}, {4, 5}, {1, 3}, {9, 0}, {5, 4}, {4, 4}, {1, 5}, {0, 5}, {0, 9}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 72);
}

TEST_F(TestPlayer, checkScoreGameWithStrikeInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {10, 0}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 30);
}

TEST_F(TestPlayer, checkScoreGameWithSpareInTheMiddle) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 29);
}

TEST_F(TestPlayer, checkScoreGameWithStrikeAtTheEnd) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {10, 0}, {1, 1}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 30);
}

TEST_F(TestPlayer, checkScoreGameWithSpareAtTheEnd) {
    score = {{1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1}, {5, 5}, {1, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 29);
}

TEST_F(TestPlayer, checkScoreGameWithAllStrikes) {
    score = {{10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0},
             {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}, {10, 0}};
    player.countScore(score);
    ASSERT_EQ(player.getScore(), 300);
}
