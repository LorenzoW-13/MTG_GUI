# MTG_GUI
MTG collection manager with Graphic User Interface

# Description
This is an in-development upgraded version of the MTG Collection Manager. Other than the presence of a Graphic Interface (developed in Qt 6) the main differences will be in the efficiency of the application, improved mainly by the presence of an index for the SQL tables

# Before launching
Before running this application, or making any modification to the source code, make sure Qt and SQLite are correctly running (Qt: https://www.qt.io/download-qt-installer-oss; SQLite: https://sqlite.org/).
## Qt:
Try launching and compiling some basic Qt-C++ application. In case of issues, please refer to Qt documentation and FAQs.
If all the applications and dependencies are correctly installed and working, you can compile, build and run the application.
To build and run a Qt-C++ application on Linux Ubuntu (VS Code) follow these steps:
- 1) Configure CMake to compile this application. Make sure CMakeLists.txt is present in the source code folder, then check that CLang is installed and running
    `cmake -S . -B build -G ninja`
    If errors occur or CLang is not used as the correct compiler, if CLang is correctly installed, try running the extended command:
    `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
    If working from VS Code, you can configure CMake by running "CMake: Configure" in the commands menu (Ctrl + Shift + P). If prompted, remember to choose Ninja as generator.
- 2) Build and debug the application (this checks if something has become obsolete, there are missing components ecc.) by running:
    `cmake --build build`
    `./build/AppName`
    debug: `gdb ./build/AppName`
    NOTES:
        - if you're using lldb instead of gdb, run `lldb ./build/AppName` instead
        - instead of `AppName` you should obviously compile using the name of the executable, which is, by default, `MTGManager`
    If working from VS Code, you can perform these operation from the commands menu (Ctrl + Shift + P) by choosing "CMake: Build", then "CMake: Debug".
- 3) If you make any change to the application's source code, make sure to build and debug the app again (repeat step - 2).
- 4) If you add any source file and/or modify any source file's name, make sure to modify the "qt_add_executable" in your CMakeLists.txt file, then configure CMake again, then build and debug.
## SQLite:
Before running the application, check that SQLite libraries are downloaded and compile them for your OS. The Libraries folder should contain files:
    - shell.c
    - sqlite3.c
    - sqlite3.h
    - sqlite3ext.h
If any are missing, please delete the content of Libraries, then download file sqlite-src-3490100.zip from "SQLite - Source Code" at SQLite: https://sqlite.org/download.html; extract the contents in folder Libraries, then once all files are present, run:
- `gcc -c Libraries/sqlite3.c -o sqlite3.o`
- `g++ -T./Libraries Test/SQLite/test.cpp sqlite3.o -Wall -o Test/SQLite/Test`
- `./Test/SQLite/Test`
