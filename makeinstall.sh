#!/bin/bash
mkdir -p build
cd build
qmake ../Taiji.pro
make clean
make
cd ..
echo ..........................make success......................
projects=("TExcept" "TRedis" "TUtil")
for project in ${projects[@]} 
do 
    includePath="./build/Include/Taiji/${project}"
    mkdir -p ${includePath}
    cp ${project}/*.h ${includePath}
    libPath="./build/Lib"
    mkdir -p ${libPath}
    cp ./build/${project}/lib* ${libPath}
done
