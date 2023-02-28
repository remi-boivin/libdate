#include <dateTest.hpp>

TEST_GROUP(getActualDateTestGroup){
    void teardown(){
        // parser.reset();
    }};

TEST(getActualDateTestGroup, ReturnsValidDate)
{
    std::string actualDate = getActualDate();

    CHECK(actualDate.size() > 0);
    CHECK(actualDate.find("-") != std::string::npos);
    CHECK(actualDate.find(":") != std::string::npos);
}