#pragma once

#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#include "C:\Dev\JsonCpp\json.h"
#elif __linux__
#endif

enum Reverser
{
    BACKWARDS = -1,
    NEUTRAL = 0,
    FORWARDS = 1,
};

struct PowerLevel
{
    float a0;
    float a1;
    float v1;
    float v2;
    float e;
};

struct ObjectTrainLocomotive
{
    std::string ID;
    std::pair<bool, Color> CustomColor;
    Model Model;
    Reverser Reverser;
    std::vector<PowerLevel> PowerLevels;
    std::vector<float> BrakeLevels;
    float EmergencyBrakeAcceleration;
    uint32_t CurrentPowerLevel;
    uint32_t CurrentBrakeLevel;
    float Velocity;
    float Acceleration;
    float Distance;

    void load(std::string &Path, uint32_t &NodeCount)
    {
        Json::Reader Reader;
        std::ifstream WorldFile(Path);
        Json::Value World;
        Reader.parse(WorldFile, World);
        WorldFile.close();

        ID = World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["ID"].asString();
        if (World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Color"].isValidIndex(3))
        {
            CustomColor.first = true;
            CustomColor.second = {(unsigned char)World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Color"][0].asUInt(), (unsigned char)World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Color"][1].asUInt(), (unsigned char)World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Color"][2].asUInt(), (unsigned char)World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Color"][3].asUInt()};
        }
        else
        {
            CustomColor.first = false;
        }
        Model = LoadModel(World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Model"].asCString());
        Model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Texture"].asCString());
        Model.transform = MatrixRotateXYZ(Vector3Scale({World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Rotation"][0].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Rotation"][1].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Rotation"][2].asFloat()}, DEG2RAD));
        Model.transform = MatrixScale(World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Scale"][0].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Scale"][1].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Scale"][2].asFloat());
        Reverser = NEUTRAL;
        PowerLevels.push_back({0.0f, 0.0f, 0.0f, 1.0f});
        uint32_t VelocityCount = 0;
        while (World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"].isValidIndex(VelocityCount))
        {
            PowerLevels.push_back({World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"][Json::ArrayIndex(VelocityCount)][0].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"][Json::ArrayIndex(VelocityCount)][1].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"][Json::ArrayIndex(VelocityCount)][2].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"][Json::ArrayIndex(VelocityCount)][3].asFloat(), World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Power"][Json::ArrayIndex(VelocityCount)][4].asFloat()});
            VelocityCount++;
        }
        BrakeLevels.push_back(0.0f);
        VelocityCount = 0;
        while (World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Brake"].isValidIndex(VelocityCount))
        {
            BrakeLevels.push_back(World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Brake"][Json::ArrayIndex(VelocityCount)].asFloat());
            VelocityCount++;
        }
        EmergencyBrakeAcceleration = World["Object"]["Train"]["Locomotive"][Json::ArrayIndex(NodeCount)]["Velocity"]["Emergency"].asFloat();
        CurrentPowerLevel = 0;
        CurrentBrakeLevel = 0;
        Velocity = 0.0f;
        Acceleration = 0.0f;
        Distance = 0.0f;
    }

    void unload()
    {
        UnloadModel(Model);
    }

    void draw(const Vector3 &CameraPosition, const Vector3 &RenderDistance, const Vector3 &Coordinate)
    {
        if (Vector3Distance(CameraPosition, {Coordinate.x + Distance, Coordinate.y, Coordinate.z}) <= Vector3Length(RenderDistance))
        {
            DrawModel(Model, {Coordinate.x + Distance, Coordinate.y, Coordinate.z}, 1.0f, CustomColor.first ? CustomColor.second : WHITE);
        }
    }

    void update()
    {
        float a0 = PowerLevels.at(CurrentPowerLevel).a0;
        float a1 = PowerLevels.at(CurrentPowerLevel).a1;
        float v1 = PowerLevels.at(CurrentPowerLevel).v1;
        float v2 = PowerLevels.at(CurrentPowerLevel).v2;
        float e = PowerLevels.at(CurrentPowerLevel).e;

        if (Velocity == 0.0f)
        {
            Acceleration = a0;
        }
        else if (Velocity >= 0.0f && Velocity < v1)
        {
            Acceleration = a0 + (a1 - a0) * Velocity / v1;
        }
        else if (Velocity == v1)
        {
            Acceleration = a1;
        }
        else if (Velocity > v1 && Velocity < v2)
        {
            Acceleration = v1 * a1 / Velocity;
        }
        else if (Velocity > v2)
        {
            Acceleration = v1 * a1 * std::pow(v2, e - 1) / std::pow(Velocity, e);
        }

        if (CurrentBrakeLevel == BrakeLevels.size())
        {
            Acceleration = EmergencyBrakeAcceleration;
        }
        else
        {
            Acceleration += BrakeLevels.at(CurrentBrakeLevel);
        }

        float DeltaTime = GetFrameTime();
        Velocity += Acceleration * DeltaTime;

        if (Velocity <= 0.0f)
        {
            Velocity = 0.0f;
        }

        Distance += Velocity * DeltaTime;

        if (IsKeyPressed(KEY_C))
        {
            if (CurrentPowerLevel > 0)
            {
                CurrentPowerLevel--;
            }
        }
        if (IsKeyPressed(KEY_V))
        {
            if (CurrentPowerLevel < PowerLevels.size() - 1)
            {
                CurrentPowerLevel++;
            }
        }
        if (IsKeyPressed(KEY_COMMA))
        {
            if (CurrentBrakeLevel > 0)
            {
                CurrentBrakeLevel--;
            }
        }
        if (IsKeyPressed(KEY_PERIOD))
        {
            if (CurrentBrakeLevel < BrakeLevels.size() - 1)
            {
                CurrentBrakeLevel++;
            }
        }
        if (IsKeyPressed(KEY_RIGHT_SHIFT))
        {
            CurrentBrakeLevel = BrakeLevels.size();
        }
    }
};