#! bin/bash

mkdir bin
mkdir bin/debug
mkdir bin/release

cd bin/debug
cmake ../../

cd ../release
cmake -DCMAKE_BUILD_TYPE=Release ../../
