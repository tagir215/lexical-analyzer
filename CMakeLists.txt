cmake_minimum_required(VERSION 3.10)
project(LexicalAnalyzer CXX)

file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

add_library(LexicalAnalyzer ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(LexicalAnalyzer PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(LexerTest "test/main.cpp" ${SOURCE_FILES})
target_include_directories(LexerTest PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)
