#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Studentas.cpp"


TEST_CASE("Students comparison") {
    Studentas s1("A", "B", 6, 5.84, 6.5),
              s2("C", "D", 7, 6.24, 7),
              s3("E", "F", 5, 4.24, 4.5);
    SECTION("Names comparison by names")
    {
        REQUIRE( compare_by_name(s1, s2) == true );
        REQUIRE( compare_by_name(s3, s2) == false );
        REQUIRE( compare_by_name(s1, s3) == true );
        REQUIRE( compare_by_name(s3, s1) == false );
    }
    SECTION("Names comparison by names")
    {
        REQUIRE( compare_by_word(s1, s2) == true );
        REQUIRE( compare_by_word(s3, s2) == false );
        REQUIRE( compare_by_word(s1, s3) == true );
        REQUIRE( compare_by_word(s3, s1) == false );
    }
}
TEST_CASE("Is student a kietekas or a vargsiukas?")
{
    Studentas s1("A", "B", 6, 5.84, 6.5),
              s2("C", "D", 7, 6.24, 7),
              s3("E", "F", 5, 4.24, 4.5);
    SECTION("Is kietekas or not by vidurkis (if false == is vargsiukas")
    {
        REQUIRE (compare_by_grades(s1) == true);
        REQUIRE (compare_by_grades(s2)== true);
        REQUIRE (compare_by_grades(s3)== false);
    }
    SECTION("Is kietekas or not by mediana (if false == is vargsiukas")
    {
        REQUIRE (compare_by_mediana(s1) == true);
        REQUIRE (compare_by_mediana(s2)== true);
        REQUIRE (compare_by_mediana(s3)== false);
    }
}
