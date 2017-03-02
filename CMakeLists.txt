cmake_minimum_required(VERSION 2.8.9)
project (tinyrefl)
SET(MYFLAG "-g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_definitions(${MYFLAG})

add_executable(sample_http_action
    ${CMAKE_CURRENT_SOURCE_DIR}/sample/http/main.cc 
    ${CMAKE_CURRENT_SOURCE_DIR}/sample/http/action_base.cc 
    ${CMAKE_CURRENT_SOURCE_DIR}/sample/http/action_get.cc 
    ${CMAKE_CURRENT_SOURCE_DIR}/sample/http/action_set.cc 
    )

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/
    )

