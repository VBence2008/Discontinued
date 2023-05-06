#pragma once

#include "Camera.hpp"
#include "Misc.hpp"

#define LEFT -1
#define RIGHT 1

class Mario
{
private:
    PlayerCamera Camera;
    Texture2D TextureIdleRight;
    Texture2D TextureIdleLeft;
    Vector2 Position;
    float Speed;
    char Direction;
    enum State
    {
        StateIdle,
        StateMove,
        StateSprint
    } State;

public:
    Mario(Vector2 SpawnPosition)
    {
        
        TextureIdleRight = LoadTexture("mario_idle.png");
        TextureIdleLeft = TextureFlip(TextureIdleRight);
        Position = SpawnPosition;
        Direction = RIGHT;
    }

    ~Mario()
    {
        UnloadTexture(TextureIdleRight);
        UnloadTexture(TextureIdleLeft);
    }

    void Draw()
    {
        switch (State)
        {
        case StateIdle:
            DrawTextureEx(Direction == RIGHT ? TextureIdleRight : TextureIdleLeft, Position, 0.0f, 3.0f, WHITE);
            break;
        case StateMove:
            DrawTextureEx(Direction == RIGHT ? TextureIdleRight : TextureIdleLeft, Position, 0.0f, 3.0f, WHITE);
            break;
        case StateSprint:
            DrawTextureEx(Direction == RIGHT ? TextureIdleRight : TextureIdleLeft, Position, 0.0f, 3.0f, WHITE);
            break;
        }
    }

    void Move()
    {
        Position.x += Speed * Direction;
    }

    void Update()
    {
        Speed = 5.0f;
        State = StateIdle;

        if (IsKeyDown(KEY_LEFT_SHIFT))
        {
            Speed = 10.0f;
        }

        if (IsKeyDown(KEY_LEFT))
        {
            Move();
            Direction = LEFT;
            State = StateMove;
        }

        if (IsKeyDown(KEY_RIGHT))
        {
            Move();
            Direction = RIGHT;
            State = StateMove;
        }

        Position.y += 25.0f;
    }
};