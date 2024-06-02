#include <raylib.h>
#include "Game.h"
#include "colors.h"
#include <iostream>

double lastUpdateTime = 0;

bool Eventttrigger(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    Color darkPink = {100, 0, 80, 255};
    InitWindow(500, 620, "tetris");
    SetTargetFPS(60);

    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    double inteval = 0.2;
    int sravnit = 100;

    while (WindowShouldClose() == false)
    {
        game.Klava();
        BeginDrawing();
        if (game.score - sravnit > 0 && game.score > 0)
        {
            inteval = inteval - 0.05;
            sravnit += 100;
        }
        if (Eventttrigger(inteval))
        {
            game.MoveVniz();
        }
        ClearBackground(darkPink);
        DrawTextEx(font, "Score", {355, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameover)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 30, 2, WHITE);
            DrawTextEx(font, "Press r to \n\n  restart", {323, 540}, 30, 2, WHITE);
            inteval = 0.2;
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightPink);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textsize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textsize.x) / 2, 65}, 38, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightPink);
        game.Risov();

        EndDrawing();
    }

    CloseWindow();
}