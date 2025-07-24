#include <raylib.h> // Include the raylib header

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib CMake Vcpkg Example");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your game logic here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE); // Clear the background with a white color

            DrawText("Congrats! raylib is working with CMake and vcpkg in manifest mode!", 10, 10, 20, DARKGRAY);
            DrawCircle(screenWidth / 2, screenHeight / 2, 50, GOLD);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and unload OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
