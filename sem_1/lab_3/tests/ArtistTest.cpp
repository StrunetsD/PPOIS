// ArtistTest.cpp
#include "../src/Artist.h"
#include <gtest/gtest.h>
#include <string>

class ArtistTest : public ::testing::Test {
protected:
    Artist* artist;

    void SetUp() override {
        artist = new Artist("John Doe", 30, 50000.0);
    }

    void TearDown() override {
        delete artist;
    }
};

TEST_F(ArtistTest, CreateGameAssetsTest) {
    testing::internal::CaptureStdout();
    artist->createGameAssets();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "John Doe is creating game assets (models, textures).\n");
}

TEST_F(ArtistTest, DevelopConceptArtTest) {
    testing::internal::CaptureStdout();
    artist->developConceptArt();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "John Doe is developing concept art for the game.\n");
}

TEST_F(ArtistTest, OptimizeGraphicsTest) {
    testing::internal::CaptureStdout();
    artist->optimizeGraphics();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "John Doe is optimizing the graphics for better performance.\n");
}
