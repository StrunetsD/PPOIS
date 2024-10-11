#include <gtest/gtest.h>
#include "../cmake-build-debug/ArtGallery.h"
#include "../cmake-build-debug/Artist.h"
#include "../cmake-build-debug/Painting.h"
#include "../cmake-build-debug/Client.h"
#include "../cmake-build-debug/Review.h"
#include "../cmake-build-debug/Event.h"


class ArtGalleryTest : public ::testing::Test {
protected:
    ArtGallery gallery{"My Gallery"};
    Artist* artist = new Artist("Vincent van Gogh", "loves art");
    Category* category =  new Category("post-impressionism");
    Painting* painting = new Painting("Starry Night", artist, "post-impressionism", 10000, category);
    Client* client = new Client("Maksim", "@example.com", "1111");
    Review* review = new Review(client, "I love art", 5);
    Event* event = new Event("event", "12.10.2025");

};

TEST_F(ArtGalleryTest, AddArtist) {
    gallery.addArtist(artist);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Artists:") != std::string::npos);
    EXPECT_TRUE(output.find(artist->getName()) != std::string::npos);
}


TEST_F(ArtGalleryTest, AddPainting) {
    gallery.addPainting(painting);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Paintings:") != std::string::npos);
    EXPECT_TRUE(output.find(painting->getTitle()) != std::string::npos);
}


TEST_F(ArtGalleryTest, AddClient) {
    gallery.addClient(client);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Clients:") != std::string::npos);
    EXPECT_TRUE(output.find(client->getName()) != std::string::npos);
}


TEST_F(ArtGalleryTest, AddReview) {
    gallery.addReview(review);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Reviews:") != std::string::npos);
    EXPECT_TRUE(output.find(review->getContent()) != std::string::npos);
}


TEST_F(ArtGalleryTest, AddEvent) {
    gallery.addEvent(event);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Events:") != std::string::npos);
    EXPECT_TRUE(output.find(event->getName()) != std::string::npos);
}


TEST_F(ArtGalleryTest, AddDuplicateArtist) {
    gallery.addArtist(artist);
    gallery.addArtist(artist);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Artists:") != std::string::npos, true);
    EXPECT_EQ(output.find("Vincent van Gogh") != std::string::npos, true);
}


TEST_F(ArtGalleryTest, AddDuplicatePainting) {
    gallery.addPainting(painting);
    gallery.addPainting(painting);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output.find("Paintings:") != std::string::npos, true);
    EXPECT_EQ(output.find("Starry Night") != std::string::npos, true);
}


TEST_F(ArtGalleryTest, AddReviewToPainting) {
    gallery.addPainting(painting);
    gallery.addReview(review);
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Reviews:") != std::string::npos);
    EXPECT_TRUE(output.find(review->getContent()) != std::string::npos);
}


TEST_F(ArtGalleryTest, ShowInfoWithoutArtists) {
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Artists:") != std::string::npos);
    EXPECT_TRUE(output.find("None.") != std::string::npos);
}


TEST_F(ArtGalleryTest, ShowInfoWithoutPaintings) {
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Paintings:") != std::string::npos);
    EXPECT_TRUE(output.find("None.") != std::string::npos);
}


TEST_F(ArtGalleryTest, ShowInfoWithoutClients) {
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Clients:") != std::string::npos);
    EXPECT_TRUE(output.find("None.") != std::string::npos);
}


TEST_F(ArtGalleryTest, ShowInfoWithoutReviews) {
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Reviews:") != std::string::npos);
    EXPECT_TRUE(output.find("None.") != std::string::npos);
}


TEST_F(ArtGalleryTest, ShowInfoWithoutEvents) {
    testing::internal::CaptureStdout();
    gallery.showInfo();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("Events:") != std::string::npos);
    EXPECT_TRUE(output.find("None.") != std::string::npos);
}