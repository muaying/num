set(Eigen3_DIR  3rdParty/eigen-3.4.0/cmake)
find_package(Eigen3 REQUIRED NO_MODULE)



set(CMAKE_PREFIX_PATH "D:/Software/SDK/Qt/5.15.2/mingw81_64")
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_subdirectory(test)
add_subdirectory(num)




