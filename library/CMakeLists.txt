add_library(PolynaryTree source/PolynaryTree.c)
target_include_directories(PolynaryTree  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(libmain libmain.c)
target_link_libraries(libmain PolynaryTree)