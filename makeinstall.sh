#!/bin/bash
cd build
sed -i '/^QMAKE/d' TExcept/Makefile*
sed -i '/^QMAKE/d' TRedis/Makefile*
sed -i '/^QMAKE/d' TUtil/Makefile*
sed -i '/^QMAKE/d' Makefile*
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
