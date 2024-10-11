#ifndef __PROJECT5_HPP
#define __PROJECT5_HPP

#include <string>
#include <unordered_set>
#include <vector>
#include <unordered_map>

namespace shindler::ics46::project5 {

struct data
{
    data(size_t distance, std::string value, size_t diff, std::string parent)
    :dist{distance}, val{value}, diff{diff}, sum{} , parent{parent}
    {
        sum = dist + diff;
    }
    size_t dist;
    std::string val;
    size_t diff;
    size_t sum;
    std::string parent;
    
    bool operator< (const data& rhs) const
    {       
        return (sum < rhs.sum);
    }

    bool operator== (const data& rhs) const
    {
        return (sum == rhs.sum);
    }

};

size_t endDiff(std::string word, std::string end);



void loadWordsIntoTable(std::unordered_set<std::string>& words,
                        std::istream& istream);

std::vector<std::string> convert(const std::string& start,
                                 const std::string& end,
                                 const std::unordered_set<std::string>& words);
}  // namespace shindler::ics46::project5
#endif
