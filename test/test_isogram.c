#include "vendor/unity.h"
#include "../src/isogram.h"
#include <stdlib.h>

//this is a unit test
void test_empty_string(void)
{
   TEST_ASSERT_TRUE(is_isogram(""));
}

void test_aa_is_no_isogram() {
    bool result = is_isogram("Aa");
    TEST_ASSERT_FALSE(result);
}

void test_abc_is_an_isogram() {
    bool result = is_isogram("abc");
    TEST_ASSERT_TRUE(result);
}

void test_long_isograms() {
   TEST_ASSERT_TRUE(is_isogram("abcdefghijklmnopqrstuvwxyz"));
   TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt"));
   TEST_ASSERT_TRUE(is_isogram("Pokalbeschriftung"));
}

void test_long_non_isograms() {
    TEST_ASSERT_FALSE(is_isogram("abcdezfghijklmnopqrstuvwxyz"));
    TEST_ASSERT_FALSE(is_isogram("Pokalbescchriftung"));
}

void test_upperLowerCase_should_not_matter(){
    TEST_ASSERT_FALSE(is_isogram("Dialogschdwerpunkt"));
}

void test_spaces_should_not_be_counted(){
    TEST_ASSERT_TRUE(is_isogram("abc def ghi"));
}



void test_long_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("Dialogschwerpunkt"));

    //negative tests    
    TEST_ASSERT_FALSE(is_isogram("Dialogschwerpunkte")); 
}

void test_short_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("a"));
    TEST_ASSERT_TRUE(is_isogram("b"));
    TEST_ASSERT_TRUE(is_isogram("c"));

    TEST_ASSERT_TRUE(is_isogram("xyz"));
    TEST_ASSERT_TRUE(is_isogram("abc"));
    TEST_ASSERT_TRUE(is_isogram("def"));

    //negative tests

    TEST_ASSERT_FALSE(is_isogram("aa"));
    TEST_ASSERT_FALSE(is_isogram("bb"));
    TEST_ASSERT_FALSE(is_isogram("cc"));
}

void test_upper_case_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("DIALOGSCHWERPUNKT"));
    TEST_ASSERT_TRUE(is_isogram("ABC"));

    //negative tests
    TEST_ASSERT_FALSE(is_isogram("DIALOGSCHWERPUNKTE"));
    TEST_ASSERT_FALSE(is_isogram("DEE"));
}

void test_lower_case_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("dialogschwerpunkte"));

    //negative tests
    TEST_ASSERT_FALSE(is_isogram("dialogschwerpunkte"));
}

void test_mixed_case_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("DIaLOFScHWERpUNkT"));
    TEST_ASSERT_TRUE(is_isogram("AbC"));

    //negative tests
    TEST_ASSERT_FALSE(is_isogram("DIALoGSCWerPUNKTE"));
    TEST_ASSERT_FALSE(is_isogram("DEe"));
}

void test_special_characters_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("!?%"));

    //negative tests
    TEST_ASSERT_FALSE(is_isogram("!??$"));
}

void test_digit_strings(){
    //positive tests
    TEST_ASSERT_TRUE(is_isogram("12345"));

    //negative tests
    TEST_ASSERT_FALSE(is_isogram("123451"));
}

//TODO#1 special characters are ignored is_isogramm(abc!!)  ==> TRUE

//TODO#2 extend definition of isIsogramm to extended definition
//          any nomber of occurences is fine, as long as its the same number
//          e.g.: is_isogramm("aaabbbccc") ==> TRUE (weil a=3 b=3 und c=3)
//                is_isogramm("aaabbbcccc") ==> FALSE (weil a=3 b=3 und c=4)


int main(void)
{
   UnityBegin("isIsogram");

   RUN_TEST(test_empty_string);
   RUN_TEST(test_aa_is_no_isogram);
   RUN_TEST(test_abc_is_an_isogram);
   RUN_TEST(test_long_isograms);
   RUN_TEST(test_long_non_isograms);
   RUN_TEST(test_upperLowerCase_should_not_matter);
   RUN_TEST(test_spaces_should_not_be_counted);

   RUN_TEST(test_empty_string);
   RUN_TEST(test_short_strings);
   RUN_TEST(test_long_strings);
   RUN_TEST(test_upper_case_strings);
   RUN_TEST(test_lower_case_strings);
   RUN_TEST(test_mixed_case_strings);
   RUN_TEST(test_special_characters_strings);
   RUN_TEST(test_digit_strings);



   UnityEnd();
   return 0;
}
