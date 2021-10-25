set(GTEST_SHUFFLE 1)

find_package(Threads REQUIRED)
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
add_executable(
    cpp-test
    main.cpp
    test.cpp
    ../app/solver.cpp
    ../app/state.cpp
    ../app/robot.cpp
    ../app/simulator.cpp
    ${SOURCES}
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${EIGEN3_INCLUDE_DIR}
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/include
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/remoteApi
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/simMath
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/IK
                                           )
target_link_libraries(cpp-test PUBLIC gtest Threads::Threads)


message(STATUS "Test level SOURCES include dir: ${SOURCES}")
get_property(dirs DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
foreach(dir ${dirs})
  message(STATUS "dir='${dir}'")
endforeach()