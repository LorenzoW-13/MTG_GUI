# MTG_GUI
MTG Collection Manager with Graphic User Interface



# Developer
If you found this program you most likely already know who I am, since you con't have found it anywhere but my GitHub, however...
I'm Lorenzo, a coding and developer student, and this is my first real project outside university works. You can fin my GitHub profile at: 
    https://github.com/LorenzoW-13
Other than a bunch of private folders, you may find this very project, probably updated to its most recent improvements, and hopefully a couple more applications either complete or in development.



# Note
As this was my first application of this level of complexity, I've found out a lot of things, mainly about Qt, SQL and the compilers, while writing and testing this code. For this reason, some of the comments below may seem superfluous to developers with more experience, or even redundant in some cases. This is because every time I encountered an issue that I thought someone else could have, I made sure to describe the problem and write down the solution. Also, after all the important information I've sometimes described stuff that might not be immediately obvious.



# Before launching

### If you're testing or working with the precompiled release, you can probably skip ahead to section "# How does it work". However, if you're working with the source code, recompiling the app, or making any changes to the project, please read carefully

If you're working with the source code (either compiling it to test/use the application, or making any modifications) there are a couple of steps to follow before accessing the main application, to ensure everything is up to date and fully compatible with your system.

## Check for Qt and SQLite
Before running the application, check that Qt 6 and SQLite are installed on your system.
    - Qt: https://www.qt.io (installer: https://www.qt.io/download-qt-installer-oss)
    - SQLite: https://sqlite.org/ (installer: https://sqlite.org/download.html)
Then, check everything is up and running, as follows:
This application comes toghether with some test apps (found in the /Test subfolder). By running some very basic code both in Qt 6 and SQLite, these test applications serve to ckeck if everything has been correctly installed, if you have the right version of both dependencies (which, for this release, should be sqlite3, specifically version 3.49.1, and Qt 6, specifically version 6.9.0)
    > note: the instructions below are written for Linux Ubuntu. Note that if you're working from Windows or MacOS, you might need to change some characters and keywords. For example, in windows the `/` character that separates folders and files in paths is actually `\`, and executable files (/Test in the instructions below) will most likely be .exe files (/Test.exe)

### Qt
- 1) To compile Qt-C++ applications, you'll need CMake, as well as CLang. Opening the main folder (/MTG_GUI) run these commands from terminal:
    - Configure CMake: `cmake -S Test/Qt -B Test/Qt/build -G Ninja`
        > `-S Test/Qt` runs CMake configuration in the Test/Qt folder, avoiding the CMakeLists.txt found in /MTG_GUI. Using the wrong CMakeLists file will result in the application not compiling, as that file holds the configuration infos for the main application, not the test apps. This is the reason why you need to compile and run the test apps from terminal, as the CMake extension, at least in VS Code, uses the main folder's CMakeLists, and won't be able to compile the test applications.
        > `-B Test/Qt/build` creates the build directory inside the Qt test folder, ensuring to avoid conflicts and errors while building the main application
        > `-G Ninja` forces Ninja as the generator. As I've not tested neither app with any other generator, I suggest sticking with Ninja. If you test any other generator, feel free to submit a feedback.
    - In case any error occurs or CLang is not used as compiler, check that CLang is correctly installed, and if so try configuring again with the extended command: `cmake -S Test/Qt -B Test/Qt/build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON`
- 2) Build, then debug the application: `cmake --build Test/Qt/build` then `gdb ./Test/Qt/build/Test`
        > 1: either gdb or lldb can be used as debuggers.
        > 2: as gdb is the debugger, it will not run the code by itself. The debugger will ask for some input. Personally I debugged with option "c" (continue without paging). To run the program while in debug mode, give gdb command `run`
        > 3: this step is supposed to make easier to spot any possible missing or obsolete dependency, but, since I've already tested and debugged the test applications, it can be entirely skipped by just typing in terminal `./Test/Qt/build/Test`
If everything is correctly installed and working, a window should pop up, containing the message "Qt is working correctly!". The "OK!" button works as a close button.

### SQLite / SQL
- 1) To use SQLite and SQL databases, you'll need to have SQLite running within you application. First, chehck if the /Libraries folder if found inside /MTG_GUI and verify that it contains files:
    - shell.c
    - sqlite3.c
    - sqlite3.h
    - sqlite3ext.h
If any are missing, please delete the content of the folder, then download file sqlite-src-3490100 from "SQLite - Source Code" at SQLite (https://sqlite.org/download.html), extract the contents in MTG_GUI/Libraries, and once all files listed above are present, you can proceed with the test.
- 2) While /sqlite3.o should be already present and correctly working, you can, if you want (or if you encounter any issues with the next passages), re-compile SQLite. To do so, from terminal run: `gcc -c Libraries/sqlite3.c -o sqlite3.o`
    > `gcc -c` compiles SQLite using the c GNU compiler, as SQLite is written in C, not C++
- 3) Compile the test app: `g++ -I ./Libraries Test/SQLite/test.cpp sqlite3.o -Wall -o Test/SQLite/Test`
    > `-I ./Libraries` tells the compiler where to find the header /sqlite3.h, which is needed to compile the sQLite Test app
- 4) Run the Test app: `./Test/SQLite/Test`
If everything is correctly installed and working, you should see, in your terminal, the output:
    > id: 1; name: NameNumber 0; position: PositionNumber 0;
      id: 2; name: NameNumber 1; position: PositionNumber 1;
      id: 3; name: NameNumber 2; position: PositionNumber 2;
      id: 4; name: NameNumber 3; position: PositionNumber 3;
      id: 5; name: NameNumber 4; position: PositionNumber 4;



# The Main Application
After testing that all the depencencies are correctly installed and working, you can build, run and make any modification you desire to the application. Here follow the instructions to build and run the app both from VS Code, or from shell (terminal).

## Both
- 1) Before configuring, compiling or running anything, please make sure that the CMakeLists.txt file in the main directory (/MTG_GUI) has listed all the .cpp and .ui files under the   "qt_add_executable(MTGManager 
                                                                 //Filenames
                                                            )"
    > Obviously, ignore any .cpp or .ui files that are found in the /Test subfolders.

- 2) Whenever you add or delete any .cpp or .ui files from /MTG_GUI, as well as any subfolder you might have added yourself, make sure to include (or remove) these files to the Filenames section of the "qt_add_executables" section of CMakeLists.txt, otherwise CMake won't be able to compile your application correctly, or at all.

- 3) Whenever you create or delete any file, or make any modification to the CMakeLists.txt file in /MTG_GUI, please make sure to repeat all passages below from step 1 (either from VS Code or from Terminal).

- 4) Whenever you make any modifications to the files already listed in CMakeLists.txt, please make sure to rebuild the project. If you haven't created or destroyed any .cpp or .ui files, you don't need to reconfigure CMake.

## From VS Code
While you can build and run the application form VS Code's terminal by following the instruction of subsection "## From Terminal", this IDE offers a quicker and easier way to configure CMake and use it to build, debug and run programs.
- 1) Open Command Palette (Ctrl + Shift + P) and select "CMake: Configure". If prompted, select Ninja as the generator
- 2) Open Command Palette and select "CMake: Build"
- 3) Open Command Palette and select "CMake: Debug"

## From Terminal
While inside /MTG_GUI, run:
- 1) `cmake -S . -B build -G Ninja` (to configure CMake)
    > if there are errors or CLang is not used as the compiler, run `cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_EXPORT_COMPILE_COMMANDS=ON` instead
- 2) `cmake --build build` build the application
- 3) `gdb ./Test/Qt/build/Test` to debug the application
    > if you encounter any issues while running your program in debug mode, please refer to section "# Before Launching", subsection "## Check for Qt and SQLite | ### Qt", step 2, note "2"
gdb ./Test/Qt/build/Test