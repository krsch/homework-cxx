#include "words.hpp"
#include <initializer_list>
#include <string>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <random>
#include <sstream>
#include <type_traits>

using result_t = decltype(count_words(""));

void check_word(std::map<std::string, int> const &counts,
                std::initializer_list<std::string> words, int count) {
  bool found = false;
  for (auto const &word : words) {
    if (auto iter = counts.find(word); iter != counts.end()) {
      INFO("checking " << word);
      CHECK(!found);
      CHECK(iter->second == count);
      found = true;
    }
  }
  CHECK(found);
}

TEST_CASE("Finds separate words") {
  auto const result = count_words("abc cba aaa");
  REQUIRE(result.at("abc") == 1);
  REQUIRE(result.at("cba") == 1);
  REQUIRE(result.at("aaa") == 1);
  REQUIRE(result.size() == 3);
}

TEST_CASE("Only shows the right case") {
  auto const result = count_words("AaA");
  REQUIRE(result.at("AaA") == 1);
  REQUIRE(result.find("aaa") == result.end());
  REQUIRE(result.find("AAA") == result.end());
  REQUIRE(result.size() == 1);
}

TEST_CASE("Finds repeating word") {
  auto const result = count_words("aaa aaa aaa");
  REQUIRE(result.at("aaa") == 3);
  REQUIRE(result.size() == 1);
}

TEST_CASE("Finds repeating word in different case") {
  auto const result = count_words("aaa AAA aAa");
  check_word(result, {"aaa", "AAA", "aAa"}, 3);
  REQUIRE(result.size() == 1);
}

TEST_CASE("Finds repeating word with punctuation") {
  auto const result = count_words("aaa, aaa. Aaa");
  check_word(result, {"aaa", "Aaa"}, 3);
  REQUIRE(result.size() == 1);
}

TEST_CASE("Finds repeating word with dashes") {
  auto const result = count_words("aaa-aAa aaa");
  check_word(result, {"aaa", "aAa"}, 3);
  REQUIRE(result.size() == 1);
}

TEST_CASE("Finds many word copies") {
  std::ostringstream str;
  constexpr int N = 100000;
  for (int i = 0; i < N; ++i)
    str << "aaa, AAA, AaA. abc! BCA? AAa-aBC... ";
  auto const result = count_words(str.str());
  check_word(result, {"aaa", "AAA", "AaA", "AAa"}, 4 * N);
  check_word(result, {"abc", "aBC"}, 2 * N);
  CHECK(result.at("BCA") == N);
  REQUIRE(result.size() == 3);
}

TEST_CASE("Finds many different words") {
  std::ostringstream str;
  constexpr int N = 100000;
  for (int i = 0; i < N; ++i) {
    std::string s = std::to_string(i);
    for (char &c : s)
      c = c - '0' + 'A';
    str << s << ", ";
  }
  auto const result = count_words(str.str());
  for (auto const &[word, count] : result) {
    INFO("checking " << word);
    CHECK(count == 1);
  }
  REQUIRE(result.size() == N);
}
