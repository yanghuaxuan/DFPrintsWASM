/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "rlgl.h"
#include "screens.h"
#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static Vector2 ballPosition = { 0 };
static Camera2D camera = { 0 };

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
    ballPosition = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.target = (Vector2){ ballPosition.x, ballPosition.y };
    camera.offset = (Vector2){ GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
    camera.zoom = 1.0f;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    camera.target = (Vector2){ ballPosition.x, ballPosition.y };

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }

    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 10.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 10.0f;
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 10.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 10.0f;
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{

    // TODO: Draw GAMEPLAY screen here!
    BeginMode2D(camera);

    rlPushMatrix();
        rlTranslatef(48, 25*20, 0);
        rlRotatef(90, 1, 0, 0);
        DrawGrid(96, 20);
    rlPopMatrix();

    DrawCircleV(ballPosition, 20, MAROON);

    EndMode2D();
    
    Vector2 pos = { 20, 10 };
    DrawTextEx(font, "GAMEPLAY SCREEN", pos, font.baseSize*3.0f, 4, MAROON);
    DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}