#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#include "C:\Dev\JsonCpp\json.h"
#elif __linux__
#endif

#include <iomanip>

struct Object
{
    bool collision;
    std::pair<bool, Color> color;
    Model model;
    std::vector<Vector3> coords;
    Vector3 spacing;
    void load(std::string path, uint32_t NodeCount)
    {
        std::ifstream MapFile(path);
        Json::Reader Reader;
        Json::Value Map;
        Reader.parse(MapFile, Map);
        collision = Map["Object"][Json::ArrayIndex(NodeCount)]["Collision"].asBool();
        if (Map["Object"][Json::ArrayIndex(NodeCount)]["Color"].isValidIndex(3))
        {
            color.first = true;
            color.second = {(unsigned char)Map["Object"][Json::ArrayIndex(NodeCount)]["Color"][0].asUInt(), (unsigned char)Map["Object"][Json::ArrayIndex(NodeCount)]["Color"][1].asUInt(), (unsigned char)Map["Object"][Json::ArrayIndex(NodeCount)]["Color"][2].asUInt(), (unsigned char)Map["Object"][Json::ArrayIndex(NodeCount)]["Color"][3].asUInt()};
        }
        else
        {
            color.first = false;
        }
        model = LoadModel(Map["Object"][Json::ArrayIndex(NodeCount)]["Model"].asCString());
        model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(Map["Object"][Json::ArrayIndex(NodeCount)]["Texture"].asCString());
        model.transform = MatrixRotateXYZ(Vector3Scale({Map["Object"][Json::ArrayIndex(NodeCount)]["Rotation"][0].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Rotation"][1].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Rotation"][2].asFloat()}, DEG2RAD));
        model.transform = MatrixScale(Map["Object"][Json::ArrayIndex(NodeCount)]["Scale"][0].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Scale"][1].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Scale"][2].asFloat());
        spacing = {Map["Object"][Json::ArrayIndex(NodeCount)]["Spacing"][0].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Spacing"][1].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Spacing"][2].asFloat()};
        uint32_t CoordCount = 0;
        while (Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"].isValidIndex(CoordCount))
        {
            if (Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)].isValidIndex(1))
            {
                for (float x = Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][0].asFloat(); x <= Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][0].asFloat(); x += spacing.x)
                {
                    for (float y = Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][1].asFloat(); y <= Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][1].asFloat(); y += spacing.y)
                    {
                        for (float z = Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][2].asFloat(); z <= Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][2].asFloat(); z += spacing.z)
                        {
                            coords.push_back({x, y, z});
                        }
                    }
                }
            }
            else
            {
                coords.push_back({Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][0].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][1].asFloat(), Map["Object"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][2].asFloat()});
            }
            CoordCount++;
        }
    }
};

void MessageAdd(std::vector<std::pair<std::pair<std::string, std::string>, Color>> *messages, std::string name, std::string message, Color color, uint32_t max)
{
    if (messages->size() >= max)
    {
        messages->erase(messages->begin());
    }
    messages->push_back({{name, message}, color});
}

void MessageDelete(std::vector<std::pair<std::pair<std::string, std::string>, Color>> *messages, std::string name)
{
    for (uint32_t i = 0; i < messages->size(); i++)
    {
        if ((*messages)[i].first.first == name)
        {
            messages->erase(messages->begin() + i);
        }
    }
}

std::string convert_seconds(int seconds)
{
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    seconds = seconds % 60;

    std::ostringstream oss;
    oss << std::setw(2) << std::setfill('0') << hours;
    oss << ":";
    oss << std::setw(2) << std::setfill('0') << minutes;
    oss << ":";
    oss << std::setw(2) << std::setfill('0') << seconds;
    return oss.str();
}

int main(int argc, const char *argv[])
{
    const std::string Title = "ExWorlds 1.0.0 by Veress Bence Gyula 2022-2023";
    std::cout << Title << "\nLoading...\n";
    std::string ArgFile = "map.json";
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
    SetWindowIcon(LoadImage("ExWorlds.png"));
    Font Font = LoadFont(Settings["Font"].asCString());
    std::ifstream map(ArgFile);
    Json::Value Map;
    Reader.parse(map, Map);
    float Gravity = Map["Gravity"].asFloat();
    float Time = Map["Time"].asFloat();
    std::vector<std::pair<float, Color>> SkyColor;
    uint32_t NodeCount = 0;
    while (Map["Sky"].isValidIndex(NodeCount))
    {
        SkyColor.push_back({Map["Sky"][Json::ArrayIndex(NodeCount)][0][0].asFloat(), {(unsigned char)Map["Sky"][Json::ArrayIndex(NodeCount)][1][0].asUInt(), (unsigned char)Map["Sky"][Json::ArrayIndex(NodeCount)][1][1].asUInt(), (unsigned char)Map["Sky"][Json::ArrayIndex(NodeCount)][1][2].asUInt()}});
        NodeCount++;
    }
    Color SkyColorCurrent;
    std::vector<std::pair<float, Color>> ObjectColor;
    NodeCount = 0;
    while (Map["Light"].isValidIndex(NodeCount))
    {
        ObjectColor.push_back({Map["Light"][Json::ArrayIndex(NodeCount)][0][0].asFloat(), {(unsigned char)Map["Light"][Json::ArrayIndex(NodeCount)][1][0].asUInt(), (unsigned char)Map["Light"][Json::ArrayIndex(NodeCount)][1][1].asUInt(), (unsigned char)Map["Light"][Json::ArrayIndex(NodeCount)][1][2].asUInt(), (unsigned char)Map["Light"][Json::ArrayIndex(NodeCount)][1][3].asUInt()}});
        NodeCount++;
    }
    Color ObjectColorCurrent;
    std::vector<Object> Objects;
    NodeCount = 0;
    while (Map["Object"].isValidIndex(NodeCount))
    {
        Object object;
        object.load(ArgFile, NodeCount);
        Objects.push_back(object);
        NodeCount++;
    }
    std::vector<std::pair<std::pair<std::string, std::string>, Color>> messages;
    float MessageY = 0.0f;
    float FreefallCapturePosition, FreefallCaptureTarget, FreefallSpeed, FreefallTime = 0.0f;
    Camera camera;
    camera.position = {0.2f, 1.6f, 0.2f};
    camera.target = {10.0f, 1.6f, 0.0f};
    camera.fovy = 45.0f;
    camera.up = {0, 1, 0};
    camera.projection = CAMERA_PERSPECTIVE;
    SetCameraMode(camera, CAMERA_CUSTOM);
    SetTargetFPS(FPS);
    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);
        Vector3 Forward = Vector3Subtract(camera.target, camera.position);
        camera.target = Vector3Add(camera.position, Forward);
        if (IsKeyDown(KEY_UP))
        {
        }
        if (IsKeyDown(KEY_DOWN))
        {
        }
        if (IsKeyDown(KEY_RIGHT))
        {
        }
        if (IsKeyDown(KEY_LEFT))
        {
        }
        if (IsKeyDown(KEY_W))
        {
        }
        if (IsKeyDown(KEY_S))
        {
        }
        if (IsKeyDown(KEY_A))
        {
        }
        if (IsKeyDown(KEY_D))
        {
        }
        if (IsKeyDown(KEY_SPACE))
        {
        }
        if (IsKeyDown(KEY_LEFT_SHIFT))
        {
        }
        if (IsKeyDown(KEY_LEFT_CONTROL))
        {
        }
        if (Time >= 86400.0f)
        {
            Time = 0.0f;
        }
        if (GetFPS() != 0)
        {
            Time += 1.0f / GetFPS();
        }
        for (auto &color : SkyColor)
        {
            if (color.first <= Time)
            {
                SkyColorCurrent = color.second;
            }
        }
        for (auto &color : ObjectColor)
        {
            if (color.first <= Time)
            {
                SkyColorCurrent = color.second;
            }
        }
        bool Collision = false;
        std::stringstream ss;
        ss << (std::string)Title << " - FPS: " << GetFPS() << " - Time: " << convert_seconds(Time);
        SetWindowTitle(ss.str().c_str());
        BeginDrawing();
        BeginMode3D(camera);
        ClearBackground(SkyColorCurrent);
        for (auto &object : Objects)
        {
            for (auto &coord : object.coords)
            {
                if (Vector3Distance(camera.position, coord) <= Vector3Length(RenderDistance))
                {
                    DrawModel(object.model, coord, 1.0f, object.color.first ? object.color.second : ObjectColorCurrent);
                }
                // if (CheckCollisionBoxes(GetModelBoundingBox(object.model), {{camera.position.x - PlayerSize.x, camera.position.y - PlayerSize.y, camera.position.z - PlayerSize.z / 2}, {camera.position.x, camera.position.y, camera.position.z + PlayerSize.z / 2}}))
                // {
                //     camera.position.y = coord.y + PlayerSize.y;
                //     camera.target.y = coord.y + PlayerSize.y;
                //     FreefallCapturePosition = camera.position.y;
                //     FreefallCaptureTarget = camera.target.y;
                //     FreefallSpeed = 0.0f;
                //     FreefallTime = 0.0f;
                //     Collision = true;
                // }
            }
        }
        // if (!Collision && GetFPS() != 0)
        // {
        //     camera.position.y = FreefallCapturePosition + (FreefallSpeed * FreefallTime - 0.5f * Gravity * FreefallTime * FreefallTime);
        //     camera.target.y = FreefallCaptureTarget + (FreefallSpeed * FreefallTime - 0.5f * Gravity * FreefallTime * FreefallTime);
        //     FreefallTime += 1.0f / GetFPS();
        // }
        DrawGrid(100, 1.0f);
        EndMode3D();
        for (auto &message : messages)
        {
            DrawTextEx(Font, message.first.second.c_str(), {0.0f, MessageY}, 20.0f, 1.0f, message.second);
            MessageY += 20.0f;
        }
        MessageY = 0.0f;
        EndDrawing();
    }
    SetWindowTitle(((std::string)Title + " - Unloading...").c_str());
    for (auto &object : Objects)
    {
        UnloadTexture(object.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);
        UnloadModel(object.model);
    }
    UnloadFont(Font);
    CloseWindow();
}