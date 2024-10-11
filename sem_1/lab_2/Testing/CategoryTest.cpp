#include "../cmake-build-debug/Category.h"
#include "gtest/gtest.h"


class CategoryTest : public ::testing::Test {
protected:
    Category* category;

    void SetUp() override {
        category = new Category("Art");
    }

    void TearDown() override {
        delete category;
    }
};


TEST_F(CategoryTest, GetCategoryName) {
    EXPECT_EQ(category->getCategoryName(), "Art");
}

TEST_F(CategoryTest, EmptyCategoryName) {
    Category emptyCategory("");
    EXPECT_EQ(emptyCategory.getCategoryName(), "");
}


