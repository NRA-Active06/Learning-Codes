cmake_minimum_required(VERSION 3.10)
project(MyProject C)

add_library(math_lib math.c)
add_library(cmdline_lib cmdline.c)
add_library(diamond_lib diamondCode.c)
add_library(bitwise_lib turnonbit.c)
add_library(static_stack_lib staticStack.c)
add_library(dynamic_stack_lib dynamicStack.c)
add_library(queue_lib queue.c)

add_executable(assignments_roulette main_menu.c)

target_link_libraries(assignments_roulette PRIVATE math_lib cmdline_lib diamond_lib bitwise_lib static_stack_lib dynamic_stack_lib queue_lib)