#!/bin/bash
if [ -f build/AmarioBros ]; then
  rm build/AmarioBros
fi
if g++ src/*.cpp -o build/AmarioBros -Wall -O2 -L /media/bence/.../Dev/ExCpp -L /home/bence/Dev/raylib -L /home/bence/Dev/JsonCpp -lraylib -ljsoncpp; then
  chmod +x build/AmarioBros
  read -p "Build completed!"
else
  read -p "Build failed!"
fi
