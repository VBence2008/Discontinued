#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#include "C:\Dev\JsonCpp\json.h"
#elif __unix__
#endif

#include "Mario.hpp"

#include <iomanip>

int main()
{
    const std::string Title = "Amario Bros. by Veress Bence Gyula 2023";
    std::cout << Title << "\nLoading...\n";

    Json::Reader Reader;
    if (!FileExists("settings.json"))
    {
        std::ofstream SettingsFile("settings.json");
        Json::Value Settings;
        Settings["Flags"]["MSAA4x"] = false;
        Settings["Flags"]["VSync"] = false;
        Settings["FPS"] = 60;
        Settings["Window"]["Height"] = 600;
        Settings["Window"]["Width"] = 800;
        SettingsFile << Settings;
        SettingsFile.close();
    }
    std::ifstream SettingsFile("settings.json");
    Json::Value Settings;
    Reader.parse(SettingsFile, Settings);
    SettingsFile.close();

    int FPS = Settings["FPS"].asInt();
    int WindowHeight = Settings["Window"]["Height"].asInt();
    int WindowWidth = Settings["Window"]["Width"].asInt();
    if (Settings["Flags"]["VSync"].asBool())
    {
        SetConfigFlags(FLAG_VSYNC_HINT);
    }
    if (Settings["Flags"]["MSAA4x"].asBool())
    {
        SetConfigFlags(FLAG_MSAA_4X_HINT);
    }

    InitWindow(WindowWidth, WindowHeight, ((std::string)Title + " - Loading...").c_str());
    // SetWindowIcon(LoadImage("logo.png"));

    if (!FileExists("save.json"))
    {
        std::ofstream SaveFile("save.json");
        Json::Value Save;
        Save["Coins"] = 0;
        Save["Level"] = 0x01;
        Save["Lives"] = 3;
        Save["Score"] = 0;
        SaveFile << Save;
        SaveFile.close();
    }
    std::ifstream SaveFileIn("save.json");
    Json::Value SaveIn;
    Reader.parse(SaveFileIn, SaveIn);
    std::ofstream SaveFileOut("save.json");
    Json::Value SaveOut;

    uint8_t SaveCoins = SaveIn["Coins"].asUInt();
    uint8_t SaveLevel = SaveIn["Level"].asUInt();
    uint8_t SaveLives = SaveIn["Lives"].asUInt();
    uint32_t SaveScore = SaveIn["Score"].asUInt();

    std::stringstream hex_level;
    hex_level << std::hex << std::setfill('0') << std::setw(2) << (uint8_t)SaveLevel;
    std::ifstream LevelFile("Level" + hex_level.str() + ".json");
    Json::Value LevelIn;
    Reader.parse(LevelFile, LevelIn);

    Mario Mario({0.0f, 0.0f});

    Camera2D Camera;
    Camera.offset = {0.0f, 0.0f};
    Camera.rotation = 0.0f;
    Camera.target = {10.0f, 10.0f};
    Camera.zoom = 1.0f;

    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        std::stringstream ss;
        ss << (std::string)Title << " - FPS: " << GetFPS();
        SetWindowTitle(ss.str().c_str());

        Mario.Update();

        BeginDrawing();
        ClearBackground(BLACK);

        Mario.Draw();

        EndDrawing();
    }

    SaveFileIn.close();
    SaveFileOut.close();

    CloseWindow();
    return 0;
}