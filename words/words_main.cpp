#include "words.hpp"
#include <iostream>
#include <string>

int main() {
  std::string s;
  std::getline(std::cin, s);
  auto freq = count_words(s);
  for (auto const &[word, count] : freq)
    std::cout << "'" << word << "' occured " << count << " times\n";
  return 0;
}