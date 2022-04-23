project(num)




file(GLOB_RECURSE   SRCS  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  LIST_DIRECTORIES false
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.ui
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
        )

include_directories("${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include")
include_directories(Frame core widget model)


add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE
        ${SRCS}
        )
target_link_libraries(${PROJECT_NAME}
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Eigen3::Eigen
        )