cmake_minimum_required(VERSION 3.10)
project(stacksAndQueuesC++)

add_library(static_stack_lib StaticStack.cpp)
add_library(dynamic_stack_lib DynamicStack.cpp)
add_library(queue_lib Queue.cpp)

add_executable(stacksAndQueuesC++ main.cpp)

target_link_libraries(stacksAndQueuesC++ PRIVATE static_stack_lib dynamic_stack_lib queue_lib)