find_package(Threads REQUIRED)

# find_package(Boost REQUIRED system filesystem date_time thread)
find_package(Eigen3 REQUIRED)

add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
add_definitions(-DDO_NOT_USE_SHARED_MEMORY)

file(GLOB SOURCES CONFIGURE_DEPENDS
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/remoteApi/*.c
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/IK/*.cpp
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/IK/*.h
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/simMath/*.h
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/simMath/*cpp
)

message(STATUS "App level SOURCES include dir: ${SOURCES}")

get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()

include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${EIGEN3_INCLUDE_DIR}
)

add_library(lib STATIC ${SOURCES})

message(STATUS "App level CMAKE_SOURCE_DIR include dir: ${CMAKE_SOURCE_DIR}")
target_include_directories(lib
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include        
        ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/include
        ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/remoteApi
        ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/simMath
        ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/IK
)



add_executable(shell-app main.cpp state.cpp solver.cpp robot.cpp simulator.cpp)

target_link_libraries(shell-app PRIVATE lib Threads::Threads)
