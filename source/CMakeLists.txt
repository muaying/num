add_executable(num)
file(GLOB_RECURSE   SRCS  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}  LIST_DIRECTORIES false
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.ui
        )
include_directories("${CMAKE_BINARY_DIR}/${PROJECT_NAME}_autogen/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(num PRIVATE
        ${SRCS}
        )
target_link_libraries(num
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )
