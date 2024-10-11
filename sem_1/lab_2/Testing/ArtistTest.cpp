#include "../cmake-build-debug/Artist.h"
#include "gtest/gtest.h"


class ArtistTest : public ::testing::Test {
protected:
        Artist* artist_ = new Artist("Vincent van Gogh", "A Dutch Post-Impressionist painter"
                                                         " who is among the most famous and influential figures"
                                                         " in the history of Western art.");

};


TEST_F(ArtistTest, GetName) {
    EXPECT_EQ(artist_->getName(), "Vincent van Gogh");
}


TEST_F(ArtistTest, GetBiography) {
    EXPECT_EQ(artist_->getBiography(), "A Dutch Post-Impressionist painter who is among the most famous and influential figures in the history of Western art.");
}


TEST_F(ArtistTest, ConstructorWithEmptyStrings) {
    const auto* emptyArtist = new Artist("", "");
    EXPECT_EQ(emptyArtist->getName(), "");
    EXPECT_EQ(emptyArtist->getBiography(), "");
    delete emptyArtist;
}