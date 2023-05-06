#pragma once

#ifdef _WIN32
#include "X:\Dev\ExCpp\ExCpp.hpp"
#include "C:\Dev\JsonCpp\json.h"
#elif __linux__
#endif

struct ObjectModel
{
    bool Collision;
    std::pair<bool, Color> CustomColor;
    Model Model;
    std::vector<Vector3> Coordinates;
    Vector3 Spacing;

    void load(std::string &Path, uint32_t &NodeCount)
    {
        Json::Reader Reader;
        std::ifstream WorldFile(Path);
        Json::Value World;
        Reader.parse(WorldFile, World);
        WorldFile.close();

        Collision = World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Collision"].asBool();
        if (World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Color"].isValidIndex(3))
        {
            CustomColor.first = true;
            CustomColor.second = {(unsigned char)World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Color"][0].asUInt(), (unsigned char)World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Color"][1].asUInt(), (unsigned char)World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Color"][2].asUInt(), (unsigned char)World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Color"][3].asUInt()};
        }
        else
        {
            CustomColor.first = false;
        }
        Model = LoadModel(World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Model"].asCString());
        Model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Texture"].asCString());
        Model.transform = MatrixRotateXYZ(Vector3Scale({45, 45, 45}, DEG2RAD));
        Model.transform = MatrixScale(World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Scale"][0].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Scale"][1].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Scale"][2].asFloat());
        Spacing = {World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Spacing"][0].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Spacing"][1].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Spacing"][2].asFloat()};
        uint32_t CoordCount = 0;
        while (World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"].isValidIndex(CoordCount))
        {
            if (World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)].isValidIndex(1))
            {
                for (float x = World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][0].asFloat(); x <= World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][0].asFloat(); x += Spacing.x)
                {
                    for (float y = World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][1].asFloat(); y <= World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][1].asFloat(); y += Spacing.y)
                    {
                        for (float z = World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][0][2].asFloat(); z <= World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][1][2].asFloat(); z += Spacing.z)
                        {
                            Coordinates.push_back({x, y, z});
                        }
                    }
                }
            }
            else
            {
                Coordinates.push_back({World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][0].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][1].asFloat(), World["Object"]["Model"][Json::ArrayIndex(NodeCount)]["Coord"][Json::ArrayIndex(CoordCount)][Json::ArrayIndex(0)][2].asFloat()});
            }
            CoordCount++;
        }
    }

    void unload()
    {
        UnloadModel(Model);
    }

    void draw(const Vector3 &CameraPosition, const Vector3 &RenderDistance)
    {
        for (auto &Coordinate : Coordinates)
        {
            if (Vector3Distance(CameraPosition, Coordinate) <= Vector3Length(RenderDistance))
            {
                DrawModel(Model, Coordinate, 1.0f, CustomColor.first ? CustomColor.second : WHITE);
            }
        }
    }

    void update()
    {
    }
};