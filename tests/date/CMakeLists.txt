# build the unit test executable.
set(CURRENT_EXE_NAME date_test)
set(SOURCE_FILES
    main.cpp
    DateTest.cpp
    )

add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -Wshadow -g -ggdb -o0)
# add_compile_options(-Wall -Wextra -pedantic -Werror -Wconversion -std=c++17 -Wshadow -g -ggdb -o0)
add_executable(${CURRENT_EXE_NAME} ${SOURCE_FILES})
add_dependencies(${CURRENT_EXE_NAME} cpputest)
target_include_directories(${CURRENT_EXE_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)
target_link_libraries(${CURRENT_EXE_NAME} CppUTest CppUTestExt date)
include_directories("../../include")
include_directories("include")

# Enable code coverage
if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --coverage")
endif()

if (CMAKE_CXX_COMPILER MATCHES "clang")
  set (CMAKE_CXX_COMPILER "/usr/bin/clang++-12")
elseif(CMAKE_BUILD_TOOL MATCHES "gcc")
set (CMAKE_CXX_COMPILER "/usr/bin/g++")
endif()

# add the test to the project to be run by ctest.
add_test(date_test ${CURRENT_EXE_NAME})