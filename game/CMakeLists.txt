set(gameSources src/main.cpp)
file(GLOB gameHeaders "include/*.h")

add_executable(game ${gameSources} ${gameHeaders})
target_link_libraries(game sfml-graphics)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
