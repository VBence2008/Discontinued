#!/bin/bash
if [ -f build/Worlds ]; then
  rm build/Worlds
fi
if g++ src/*.cpp -o build/Worlds -Wall -O2 -L /media/bence/.../Dev/ExCpp -L /home/bence/Dev/raylib -L C:/Dev/JsonCpp -lraylib -ljsoncpp; then
  chmod +x build/Worlds
  read -p "Build completed!"
else
  read -p "Build failed!"
fi
