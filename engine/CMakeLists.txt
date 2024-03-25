add_library(PieceTypes)
target_include_directories(PieceTypes PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(PieceTypes DataStructures)
target_sources(PieceTypes
  PRIVATE piecetypes/Rook.c)

add_library(Engine)
target_include_directories(Engine PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_include_directories(Engine PRIVATE ${CMAKE_CURRENT_LIST_DIR}/piecetypes)
target_link_libraries(Engine
  DataStructures
  PieceTypes)
target_sources(Engine
  PRIVATE source/Game.c
  PRIVATE source/Board.c
  PRIVATE source/Piece.c)

add_executable(enginemain enginemain.c)
target_link_libraries(enginemain Engine)