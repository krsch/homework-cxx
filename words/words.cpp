#include "words.hpp"
#include <map>
#include <set>
std::map<std::string, int> count_words(std::string const& input) {
  std::set<char> punctuation_mark {'-', '.', ' ', '!', '?'};
  std::map<std::string, int> result;
  std::string word = "";
  for (int i = 0; i<input.length(); i++)
  { 
    char symbol = tolower(input[i]);

    auto it1 = punctuation_mark.find(symbol);
    if (it1 == punctuation_mark.end())
      word+=symbol;
    else
    {
      if (word != "")
      {
        auto it2 = result.find(word);
        if (it2 == result.end())
        {
          result[word] = 1;
        }
        else 
          ++result[word];

      }
      word = "";
    }
     
    
  }
  return result;
}
