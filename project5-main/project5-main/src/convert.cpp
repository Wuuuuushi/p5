#include "convert.hpp"
#include "PriorityQueue.hpp"

#include <istream>
#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <iostream>
#include <unordered_map>

namespace shindler::ics46::project5 {

// You should not need to change this function.
void loadWordsIntoTable(std::unordered_set<std::string>& words,
                        std::istream& istream) {
    std::string word;

    while (istream >> word) {
        words.insert(word);
    }
}

size_t endDiff(std::string word, std::string end)
{
    size_t diff{0};
    for (size_t index{0}; index < word.length(); index++)
    {
        if (word[index] != end[index])
        {
            diff++;
        }
    }
    return diff;
}

// You probably want to change this function.
std::vector<std::string> convert(const std::string& start,
                                 const std::string& end,
                                 const std::unordered_set<std::string>& words) {
    char alphabets[] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    };
    std::unordered_map<std::string, std::string> wordMap;
    std::unordered_map<std::string, int> distances;
    project5::PriorityQueue<data> priorityQueue{};
    data startData = data(0, start, endDiff(start, end), "");
    priorityQueue.push(startData);
    wordMap[start] = "";
    distances[start] = 0;

    while(!priorityQueue.empty()) 
    {
        data Data{priorityQueue.min()};
        priorityQueue.popMin();
        if (Data.val == end) 
        {
            break; // Reached the end word
        }
        for (size_t index{0}; index < Data.val.length(); index++) 
        {
            for (char c: alphabets) 
            {
                std::string tmpVal = Data.val;
                tmpVal[index] = c;
                if (words.count(tmpVal) != 0) 
                {
                    int newDist = distances[Data.val] + 1;
                    if (!distances.count(tmpVal) or newDist < distances[tmpVal]) 
                    {
                        distances[tmpVal] = newDist;
                        data pushData = data(newDist, tmpVal, endDiff(tmpVal, end), Data.val);
                        priorityQueue.push(pushData);
                        wordMap[tmpVal] = Data.val;
                    }
                }
            }
        }
    }

    std::vector<std::string> returnVector;
    if (wordMap.count(end) == 1) {
        std::string strVal{end};
        while (strVal != start) {
            returnVector.push_back(strVal);
            strVal = wordMap[strVal];
        }
        returnVector.push_back(start);
        std::reverse(returnVector.begin(), returnVector.end());
    }

    for (const auto& elem : returnVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    return returnVector;
}

};  // namespace shindler::ics46::project5
