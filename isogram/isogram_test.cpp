#include "catch.hpp"
#include "isogram.hpp"

TEST_CASE("Empty String") {
  REQUIRE(is_isogram("") == true);
}
TEST_CASE("isogram_with_only_lower_case_characters") {
  REQUIRE(is_isogram("isogram") == true);
}
TEST_CASE("word_with_one_duplicated_character") {
  REQUIRE(is_isogram("eleven") == false);
}
TEST_CASE("word_with_one_duplicated_character_from_the_end_of_the_alphabet") {
  REQUIRE(is_isogram("zzyzx") == false);
}
TEST_CASE("longest_reported_english_isogram") {
  REQUIRE(is_isogram("subdermatoglyphic") == true);
}
TEST_CASE("word_with_duplicated_character_in_mixed_case") {
  REQUIRE(is_isogram("Alphabet") == false);
}
TEST_CASE("word_with_duplicated_character_in_mixed_case_lowercase_first") {
  REQUIRE(is_isogram("alphAbet") == false);
}
TEST_CASE("hypothetical_isogrammic_word_with_hyphen") {
  REQUIRE(is_isogram("thumbscrew-japingly") == true);
}
TEST_CASE("hypothetical_word_with_duplicated_character_following_hyphen") {
  REQUIRE(is_isogram("thumbscrew-jappingly") == false);
}
TEST_CASE("isogram_with_duplicated_hyphen") {
  REQUIRE(is_isogram("six-year-old") == true);
}
TEST_CASE("made_up_name_that_is_an_isogram") {
  REQUIRE(is_isogram("Emily Jung Schwartzkopf") == true);
}
TEST_CASE("duplicated_character_in_the_middle") {
  REQUIRE(is_isogram("accentor") == false);
}
TEST_CASE("same_first_and_last_characters") {
  REQUIRE(is_isogram("angola") == false);
}