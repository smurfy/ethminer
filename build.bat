set PATH=%PATH%;f:\files\qt\CUDA\v8.0\bin
set PATH=%PATH%;"c:\Program Files\CMake\bin"
cmake -G "Visual Studio 14 2015 Win64" -H. -Bbuild -DETHASHCUDA=ON -DAPICORE=ON -DETHSTRATUM=ON -DETHGETWORK=ON
cmake --build build --config Release
