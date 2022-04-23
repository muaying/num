
set(Eigen3_DIR  ${CMAKE_SOURCE_DIR}/3rdParty/eigen-3.4.0/cmake)
find_package(Eigen3 REQUIRED)


add_subdirectory(test)
add_subdirectory(num)




