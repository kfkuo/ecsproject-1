#include <gtest/gtest.h>
#include "StringUtils.h"
#include <gmock/gmock.h>

using namespace StringUtils;

void EXPECT_VECTOR_EQ(const std::vector<std::string>& a, const std::vector<std::string>& b) {
    ASSERT_EQ(a.size(), b.size());
    for (size_t i = 0; i < a.size(); ++i) {
        EXPECT_EQ(a[i], b[i]);
    }
}

TEST(StringUtilsTest, SliceTest) {
    EXPECT_EQ(Slice("tangerine", 0, 2), "ta");
    EXPECT_EQ(Slice("tangerine", 3, 6), "ger");
    EXPECT_EQ(Slice("tangerine", -4, 0), "rine");
    EXPECT_EQ(Slice("tangerine", 0, 0), "tangerine");
}

TEST(StringUtilsTest, Capitalize) {
    EXPECT_EQ(Capitalize("tangerine"), "Tangerine");
    EXPECT_EQ(Capitalize("TANGERINE"), "Tangerine");
    EXPECT_EQ(Capitalize(""), "");
}

TEST(StringUtilsTest, Upper) {
    EXPECT_EQ(Upper("tangerine"), "TANGERINE");
    EXPECT_EQ(Upper("Tangerine123"), "TANGERINE123");
    EXPECT_EQ(Upper(""), "");
}

TEST(StringUtilsTest, Lower) {
    EXPECT_EQ(Lower("TANGERINE"), "tangerine");
    EXPECT_EQ(Lower("Tangerine123"), "tangerine123");
    EXPECT_EQ(Lower(""), "");
}

TEST(StringUtilsTest, LStrip) {
    EXPECT_EQ(LStrip("   tangerine"), "tangerine");
    EXPECT_EQ(LStrip("tangerine  "), "tangerine  ");
    EXPECT_EQ(LStrip(""), "");
}

TEST(StringUtilsTest, RStrip) {
    EXPECT_EQ(RStrip("   tangerine"), "   tangerine");
    EXPECT_EQ(RStrip("tangerine  "), "tangerine");
    EXPECT_EQ(RStrip(""), "");
}

TEST(StringUtilsTest, Strip) {
    EXPECT_EQ(Strip("   tangerine  "), "tangerine");
    EXPECT_EQ(Strip("tangerine"), "tangerine");
    EXPECT_EQ(Strip(""), "");
}

TEST(StringUtilsTest, Center) {
    EXPECT_EQ(Center("tangerine", 12, '*'), "*tangerine*");
    EXPECT_EQ(Center("tangerine", 10), "tangerine ");
    EXPECT_EQ(Center("tangerine", 5), "tangerine");
}

TEST(StringUtilsTest, LJust) {
    EXPECT_EQ(LJust("tangerine", 12, '*'), "tangerine**");
    EXPECT_EQ(LJust("tangerine", 5), "tangerine");
}

TEST(StringUtilsTest, RJust) {
    EXPECT_EQ(RJust("tangerine", 12, '*'), "**tangerine");
    EXPECT_EQ(RJust("tangerine", 5), "tangerine");
}

TEST(StringUtilsTest, Replace) {
    EXPECT_EQ(Replace("tangerine tangerine", "t", "T"), "Tangerine Tangerine");
    EXPECT_EQ(Replace("tangerine", "z", "x"), "tangerine");
}

TEST(StringUtilsTest, Split) {
    std::vector<std::string> v1 = {"tangerine", "fruit"};
    EXPECT_VECTOR_EQ(Split("tangerine fruit", " "), v1);

    std::vector<std::string> v2 = {"tangerine", "fruit", "juice"};
    EXPECT_VECTOR_EQ(Split("tangerine,fruit,juice", ","), v2);

    std::vector<std::string> v3 = {"tangerine", "fruit", "juice"};
    EXPECT_VECTOR_EQ(Split("tangerine fruit juice", ""), v3);
}

TEST(StringUtilsTest, Join) {
    std::vector<std::string> v = {"tangerine", "fruit"};
    EXPECT_EQ(Join(" ", v), "tangerine fruit");
    EXPECT_EQ(Join("-", v), "tangerine-fruit");
    EXPECT_EQ(Join("", v), "tangerinefruit");
}

TEST(StringUtilsTest, ExpandTabs) {
    EXPECT_EQ(ExpandTabs("tang\tfruit", 4), "tang   fruit");
    EXPECT_EQ(ExpandTabs("\ttangerine", 4), "    tangerine");
}

TEST(StringUtilsTest, EditDistance) {
    EXPECT_EQ(EditDistance("tangerine", "tangerines"), 1);
    EXPECT_EQ(EditDistance("tangerine", "mangerine"), 1);
    EXPECT_EQ(EditDistance("Tangerine", "tangerine", true), 0);
    EXPECT_EQ(EditDistance("Tangerine", "tangerine", false), 1);
}
