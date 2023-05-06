#!/bin/bash
if [ -f build/ExWorlds ]; then
  rm build/ExWorlds
fi
if g++ src/*.cpp -o build/ExWorlds -Wall -O2 -L /media/bence/.../Dev/ExCpp -L /home/bence/Dev/raylib -L /home/bence/Dev/JsonCpp -lraylib -ljsoncpp; then
  chmod +x build/ExWorlds
  read -p "Build completed!"
else
  read -p "Build failed!"
fi
