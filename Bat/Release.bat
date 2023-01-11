set BUILD_DIR=C:/CopperSpice/Prg/PrabhupadaDictionary/Release/Build

cd %BUILD_DIR%
cmake -G "Ninja" -DCMAKE_BUILD_TYPE=Release ^
-DCMAKE_INSTALL_PREFIX="C:/CopperSpice/Prg/PrabhupadaDictionary/Release/Bin" ^
-DCMAKE_PREFIX_PATH="C:/CopperSpice/Lib/Release/1.8.0/cmake/CopperSpice" ^
C:/CopperSpice/Prg/PrabhupadaDictionary/Source

cd %BUILD_DIR%
ninja -v

cd %BUILD_DIR%
ninja -v install
