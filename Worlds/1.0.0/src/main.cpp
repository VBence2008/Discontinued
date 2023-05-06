#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#include "C:\Dev\JsonCpp\json.h"
#elif __linux__
#endif

#include "Object/Model.hpp"
#include "Object/Train/Locomotive.hpp"

#include <iomanip>

#define WORLDS_MAJOR 0
#define WORLDS_MINOR 0
#define WORLDS_FIX 0

std::string ConvertSeconds(uint32_t seconds)
{
    uint32_t hours = seconds / 3600;
    seconds %= 3600;
    uint32_t minutes = seconds / 60;
    seconds %= 60;
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hours << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds;
    return oss.str();
}

int main(int argc, const char *argv[])
{
    std::string Title = "";
    std::string TitleDate = __DATE__;
    ex::StringSplit(TitleDate, " ", 0);
    ex::StringSplit(TitleDate, " ", 0);
    if (WORLDS_MAJOR == 0)
    {
        std::string Date = __DATE__;
        ex::StringReplace(Date, "Jan ", "01");
        ex::StringReplace(Date, "Feb ", "02");
        ex::StringReplace(Date, "Mar ", "03");
        ex::StringReplace(Date, "Apr ", "04");
        ex::StringReplace(Date, "May ", "05");
        ex::StringReplace(Date, "Jun ", "06");
        ex::StringReplace(Date, "Jul ", "07");
        ex::StringReplace(Date, "Aug ", "08");
        ex::StringReplace(Date, "Sep ", "09");
        ex::StringReplace(Date, "Oct ", "10");
        ex::StringReplace(Date, "Nov ", "11");
        ex::StringReplace(Date, "Dec ", "12");
        ex::StringReplace(Date, " 20", "");
        std::string DateNew = "";
        DateNew += Date[4];
        DateNew += Date[5];
        DateNew += Date[0];
        DateNew += Date[1];
        DateNew += Date[2];
        DateNew += Date[3];
        Title = "Worlds 0." + DateNew + " by Veress Bence Gyula " + TitleDate;
    }
    else
    {
        Title = "Worlds " + std::to_string(WORLDS_MAJOR) + std::to_string(WORLDS_MINOR) + std::to_string(WORLDS_FIX) + " by Veress Bence Gyula " + TitleDate;
    }
    std::cout << Title << "\nLoading...\n";
    std::string ArgFile = "world.json";
    if (argc > 1)
    {
        ArgFile = argv[1];
    }

    Json::Reader Reader;
    if (!FileExists("settings.json"))
    {
        std::ofstream SettingsFile("settings.json");
        Json::Value Settings;
        Settings["Flags"]["MSAA4x"] = false;
        Settings["Flags"]["VSync"] = false;
        Settings["Font"] = "BAHNSCHRIFT.TTF";
        Settings["FPS"] = 60;
        Settings["MaxMessages"] = 20;
        Settings["RenderDistance"]["X"] = 500.0;
        Settings["RenderDistance"]["Y"] = 500.0;
        Settings["RenderDistance"]["Z"] = 500.0;
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
    uint32_t MaxMessages = Settings["MaxMessages"].asUInt();
    Vector3 RenderDistance = {Settings["RenderDistance"]["X"].asFloat(), Settings["RenderDistance"]["Y"].asFloat(), Settings["RenderDistance"]["Z"].asFloat()};
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
    SetWindowTitle(Title.c_str());
    SetWindowIcon(LoadImage("Worlds.png"));
    Font Font = LoadFont(Settings["Font"].asCString());

    std::ifstream WorldFile(ArgFile);
    Json::Value World;
    Reader.parse(WorldFile, World);
    WorldFile.close();

    float Gravity = World["Gravity"].asFloat();
    float Time = World["Time"].asFloat();
    std::vector<ObjectModel> ObjectModels;
    uint32_t NodeCount = 0;
    while (World["Object"]["Model"].isValidIndex(NodeCount))
    {
        ObjectModel ObjectModel;
        ObjectModel.load(ArgFile, NodeCount);
        ObjectModels.push_back(ObjectModel);
        NodeCount++;
    }
    std::vector<ObjectTrainLocomotive> ObjectTrainLocomotives;
    NodeCount = 0;
    while (World["Object"]["Train"]["Locomotive"].isValidIndex(NodeCount))
    {
        ObjectTrainLocomotive ObjectTrainLocomotive;
        ObjectTrainLocomotive.load(ArgFile, NodeCount);
        ObjectTrainLocomotives.push_back(ObjectTrainLocomotive);
        NodeCount++;
    }

    Camera Camera;
    Camera.position = {0.2f, 1.6f, 0.2f};
    Camera.target = {10.0f, 1.6f, 0.0f};
    Camera.up = {0, 1, 0};
    Camera.fovy = 45.0f;
    Camera.projection = CAMERA_PERSPECTIVE;

    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        UpdateCamera(&Camera, CAMERA_PERSPECTIVE);

        if (Time >= 86400.0f)
        {
            Time = 0.0f;
        }
        if (GetFPS() != 0)
        {
            Time += GetFrameTime();
        }

        BeginDrawing();
        ClearBackground(WHITE);

        DrawText(std::to_string(GetFPS()).c_str(), 5, 5, 20, DARKGREEN);
        DrawText(ConvertSeconds(Time).c_str(), 5, 25, 20, DARKGREEN);

        DrawText(("Reverser: " + std::to_string(ObjectTrainLocomotives.front().Reverser)).c_str(), 5, 45, 20, DARKBLUE);
        DrawText(("Power level: " + std::to_string(ObjectTrainLocomotives.front().CurrentPowerLevel)).c_str(), 5, 65, 20, DARKBLUE);
        DrawText(("Brake level: " + std::to_string(ObjectTrainLocomotives.front().CurrentBrakeLevel)).c_str(), 5, 85, 20, DARKBLUE);
        DrawText(("Speed: " + std::to_string(ObjectTrainLocomotives.front().Velocity * 3.6f) + " km/h").c_str(), 5, 105, 20, DARKBLUE);
        DrawText(("Distance: " + std::to_string(ObjectTrainLocomotives.front().Distance) + " meters").c_str(), 5, 125, 20, DARKBLUE);

        BeginMode3D(Camera);
        DrawGrid(400, 1.0f);

        for (auto &ObjectModel : ObjectModels)
        {
            ObjectModel.update();
            ObjectModel.draw(Camera.position, RenderDistance);
        }
        for (auto &ObjectTrainLocomotive : ObjectTrainLocomotives)
        {
            ObjectTrainLocomotive.update();
            Camera.position = {-200.0f + ObjectTrainLocomotive.Distance, 1.5f, 0.0f};
            Camera.target = {-200.0f + ObjectTrainLocomotive.Distance + 10.0f, 0.5f, 0.0f};
            ObjectTrainLocomotive.draw(Camera.position, RenderDistance, (const Vector3){-200.0f, 0.5f, 0.0f});
        }

        EndMode3D();
        EndDrawing();
    }

    SetWindowTitle(((std::string)Title + " - Unloading...").c_str());

    for (auto &ObjectTrainLocomotive : ObjectTrainLocomotives)
    {
        ObjectTrainLocomotive.unload();
    }
    for (auto &ObjectModel : ObjectModels)
    {
        ObjectModel.unload();
    }
    UnloadFont(Font);

    CloseWindow();
    return 0;
}
