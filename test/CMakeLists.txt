set(GTEST_SHUFFLE 1)

find_package(Threads REQUIRED)
find_package(Eigen3 REQUIRED)

add_definitions(-DNON_MATLAB_PARSING)
add_definitions(-DMAX_EXT_API_CONNECTIONS=255)
add_definitions(-DDO_NOT_USE_SHARED_MEMORY)

file(GLOB SOURCES CONFIGURE_DEPENDS
${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/remoteApi/*.c
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
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/include
                                           ${CMAKE_SOURCE_DIR}/../CoppeliaSim_Edu/programming/remoteApi
                                           )
target_link_libraries(cpp-test PUBLIC gtest Threads::Threads)
