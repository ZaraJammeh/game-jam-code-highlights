# Game Jam Code Highlights

In August 2024, I entered the annual GMTK Game Jam alongside an artist friend, with the goal of kickstarting my game dev skills. Using SDL2 and C++ taught me a lot about building game functionality from the ground up in just 4 days. This repo showcases some of my favourite parts of the code I wrote in that time.
(The Vector2Structs and TextureRect files are included here as dependencies for the other files)

## Tilemaps, Tilesets and Looping Textures
The jam's time limit meant that it was important to have ways of reusing art assets, prompting the use of looping background textures and tilemaps. Using Lazy Foo' Productions' tutorials as a starting point, I had fun figuring out how to implement these features to fit with our game idea. Creating the tileset code gave me a reason to use nested classes in C++ for the first time - it was very rewarding to get that system working as intended.

## Tilemap Helper Script
Without the visual editor provided by most game engines, a quick Python script became our solution for typing out the text files that the tileset class needed to read from. It worked well enough for what we needed!
