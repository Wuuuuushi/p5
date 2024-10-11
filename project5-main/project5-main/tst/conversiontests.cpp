#include <catch2/catch_amalgamated.hpp>
#include <convert.hpp>
#include <fstream>
#include <istream>
#include <string>
#include <unordered_set>
#include <vector>

namespace {

bool isValidChange(const std::string &start, const std::string &end) {
    if (start.length() != end.length()) {
        return false;
    }

    bool foundChange = false;
    for (size_t i{0}; i < start.length(); i++) {
        if (start[i] != end[i] && !foundChange) {
            foundChange = true;
        } else if (start[i] != end[i]) {
            return false;
        }
    }

    return true;
}

bool validConversion(const std::vector<std::string> &path,
                     const std::string &start, const std::string &end,
                     std::istream &istream) {
    std::unordered_set<std::string> words;
    std::string word;

    if (path.empty()) {
        return false;
    }
    if (start == end && path.size() == 1 && path[0] == start) {
        return true;
    }
    if (path[0] != start || path[path.size() - 1] != end) {
        return false;
    }

    while (istream >> word) {
        words.insert(word);
    }

    for (size_t i{0}; i < path.size() - 1; i++) {
        if (!words.contains(path[i]) || !isValidChange(path[i], path[i + 1])) {
            return false;
        }
    }

    return words.contains(path[path.size() - 1]);
}

namespace proj5 = shindler::ics46::project5;

// As always, this is a STARTING POINT of TEST_CASE( cases
// and is not an exhaustive set of TEST_CASE( cases.
// You should be sure to TEST_CASE( EVERY function of
// your priority queue as well as the Lewis Carroll puzzle.
TEST_CASE("Convert:AntToEat:ExpectValidPathLength5", "[Required][Conversion]") {
    const std::string WORD_ONE = "ant";
    const std::string WORD_TWO = "eat";
    const size_t CORRECT_LENGTH = 5;

    std::unordered_set<std::string> words;
    std::ifstream istream("words.txt");
    proj5::loadWordsIntoTable(words, istream);

    std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

    REQUIRE(path.size() == CORRECT_LENGTH);
    istream.clear();
    istream.seekg(0);
    REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
}

// Additional sample tests for conversion
// these ARE NOT required in the sense
// 	  that your project will be graded even
//    if one or more of these do not pass.
// However, failing to pass these might indicate
// 		you might not be happy with your grade,
// 		so I encourage you to pass them anyway :)

TEST_CASE("Convert:PuttersToHampers:ExpectValidPathLength14", "[Conversion]") {
    const std::string WORD_ONE = "putters";
    const std::string WORD_TWO = "hampers";
    const size_t CORRECT_LENGTH = 14;

    std::unordered_set<std::string> words;
    std::ifstream istream("words.txt");
    proj5::loadWordsIntoTable(words, istream);

    std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

    REQUIRE(path.size() == CORRECT_LENGTH);
    istream.clear();
    istream.seekg(0);
    REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
}

TEST_CASE("Convert::BankingToBrewing::ExpectValidPathLength15",
          "[Conversion]") {
    const std::string WORD_ONE = "banking";
    const std::string WORD_TWO = "brewing";
    const size_t CORRECT_LENGTH = 15;

    std::unordered_set<std::string> words;
    std::ifstream istream("words.txt");
    proj5::loadWordsIntoTable(words, istream);

    std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

    REQUIRE(path.size() == CORRECT_LENGTH);
    istream.clear();
    istream.seekg(0);
    REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
}

TEST_CASE("Convert:ChangesToGlasses:ExpectValidPathLength48", "[Conversion]") {
    const std::string WORD_ONE = "changes";
    const std::string WORD_TWO = "glasses";
    const size_t CORRECT_LENGTH = 48;

    std::unordered_set<std::string> words;
    std::ifstream istream("words.txt");
    proj5::loadWordsIntoTable(words, istream);

    std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

    REQUIRE(path.size() == CORRECT_LENGTH);
    istream.clear();
    istream.seekg(0);
    REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
}

TEST_CASE("Convert:ChangesToSmashed:ExpectValidPathLength48", "[Conversion]") {
    const std::string WORD_ONE = "changes";
    const std::string WORD_TWO = "smashed";
    const size_t CORRECT_LENGTH = 48;

    std::unordered_set<std::string> words;
    std::ifstream istream("words.txt");
    proj5::loadWordsIntoTable(words, istream);

    std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

    REQUIRE(path.size() == CORRECT_LENGTH);
    istream.clear();
    istream.seekg(0);
    REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
}

// TEST_CASE("BoostedToClasses", "[SampleConversionTests]") {
//     const std::string WORD_ONE = "boosted";
//     const std::string WORD_TWO = "classes";
//     const size_t CORRECT_LENGTH = 44;

//     std::unordered_set<std::string> words;
//     std::ifstream istream("words.txt");
//     proj5::loadWordsIntoTable(words, istream);

//     std::vector<std::string> path = proj5::convert(WORD_ONE, WORD_TWO, words);

//     REQUIRE(path.size() == CORRECT_LENGTH);
//     istream.clear();
//     istream.seekg(0);
//     REQUIRE(validConversion(path, WORD_ONE, WORD_TWO, istream));
// }

}  // namespace
