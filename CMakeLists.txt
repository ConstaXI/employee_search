cmake_minimum_required(VERSION 3.23)
project(employee_search C)

set(CMAKE_C_STANDARD 17)

add_executable(employee_search main.c generate/generation.c generate/generation.h employee/employee.h files/files.c files/files.h interface/interface.c interface/interface.h manipulation/manipulation.c manipulation/manipulation.h btree/btree.c btree/btree.h key/key.h)
