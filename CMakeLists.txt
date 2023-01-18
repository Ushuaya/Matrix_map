cmake_minimum_required(VERSION 3.14)
project(mtx_rally)
include(FetchContent)
include(GoogleTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
add_executable(mtx_rally ${SOURCES})


#gtest_discover_tests(Tests)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  Matrix_test
  Tests/Matrix_test/Matrix_test.cpp
)
target_link_libraries(
  Matrix_test
  GTest::gtest_main
)

add_executable(
  Parser_test
  Tests/Parset_test/Parser_test.cpp
)
target_link_libraries(
  Parser_test
  GTest::gtest_main
)

add_executable(
  Proxy_test
  Tests/Proxy_test/Proxy_test.cpp
)
target_link_libraries(
  Proxy_test
  GTest::gtest_main
)

add_executable(
  Ration_number_test
  Tests/Ration_number_test/Ration_number_test.cpp
)
target_link_libraries(
  Ration_number_test
  GTest::gtest_main
)

add_executable(
  Strint_test
  Tests/Strint_test/StrInt_test.cpp
)
target_link_libraries(
  Strint_test
  GTest::gtest_main
)

#add_test(NAME Matrix_test COMMAND Matrix_test)

#gtest_discover_tests(Matrix_test)
