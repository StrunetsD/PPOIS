#include <gtest/gtest.h>
#include "../cmake-build-debug/Painting.h"
#include "../cmake-build-debug/Artist.h"
#include "../cmake-build-debug/Category.h"


class PaintingTest : public ::testing::Test {
protected:
        Artist* artist_ = new Artist("Vincent van Gogh","loves art");
        Category*  category_ = new Category("Post-Impressionism");
        Painting*   painting_ = new Painting("Starry Night", artist_, "Oil on canvass", 1000000.0, category_);
};


TEST_F(PaintingTest, GetTitle) {
    EXPECT_EQ(painting_->getTitle(), "Starry Night");
}


TEST_F(PaintingTest, GetArtist) {
    EXPECT_EQ(painting_->getArtist()->getName(), "Vincent van Gogh");
}


TEST_F(PaintingTest, GetStyle) {
    EXPECT_EQ(painting_->getStyle(), "Oil on canvass");
}


TEST_F(PaintingTest, GetPrice) {
    EXPECT_DOUBLE_EQ(painting_->getPrice(), 1000000.0);
}


TEST_F(PaintingTest, GetCategory) {
    EXPECT_EQ(painting_->getCategory(), "Post-Impressionism");
}


TEST_F(PaintingTest, ShowInfo) {
    EXPECT_NO_THROW(painting_->showInfo());
}






