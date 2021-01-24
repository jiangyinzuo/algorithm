cmake_minimum_required(VERSION 3.17)
project(algorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(heap_queue heap_queue.cpp)
add_executable(BSTree tree/BSTree.cpp)
add_executable(treap tree/treap.cpp)