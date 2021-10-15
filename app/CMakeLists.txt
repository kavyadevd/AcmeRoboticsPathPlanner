find_package(Threads REQUIRED)

add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
add_definitions(-DDO_NOT_USE_SHARED_MEMORY)

file(GLOB SOURCES CONFIGURE_DEPENDS
$ENV{HOME}/CoppeliaSim_Edu/programming/remoteApi/*.c
)

message(STATUS "SOURCES include dir: ${SOURCES}")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    # CoppeliaSim remoteApi headers
    $ENV{HOME}/CoppeliaSim_Edu/programming/remoteApi
    $ENV{HOME}/CoppeliaSim_Edu/programming/include
)

add_library(lib STATIC ${SOURCES})

target_include_directories(lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
        $ENV{HOME}/CoppeliaSim_Edu/programming/include
        $ENV{HOME}/CoppeliaSim_Edu/programming/remoteApi
)

add_executable(shell-app main.cpp state.cpp solver.cpp robot.cpp simulator.cpp)

target_link_libraries(shell-app PRIVATE lib Threads::Threads)