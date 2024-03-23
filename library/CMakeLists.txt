add_library(DataStructures)
target_include_directories(DataStructures  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
target_sources(DataStructures
  PRIVATE source/PolynaryTree.c
  PRIVATE source/DoubleLinkedList.c)

add_executable(libmain libmain.c)
target_link_libraries(libmain DataStructures)