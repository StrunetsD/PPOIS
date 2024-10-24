#include "Artist.h"


void Artist::createGameAssets() const {
    cout << getName() << " is creating game assets (models, textures)." << '\n';
}

void Artist::developConceptArt() const {
    cout << getName() << " is developing concept art for the game." <<'\n';
}

void Artist::optimizeGraphics() const {
    cout << getName() << " is optimizing the graphics for better performance." << '\n';
}