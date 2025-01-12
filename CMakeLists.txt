cmake_minimum_required(VERSION 3.5.0)
project(Astroido VERSION 0.1.0 LANGUAGES C CXX)

find_package(SFML 2.5 COMPONENTS 
                      graphics 
                      window 
                      audio 
                      REQUIRED)

add_executable(${PROJECT_NAME} 
               src/main.cpp
               src/engine/renderer.cpp
               src/engine/game.cpp
               src/engine/eventHandler.cpp
               src/engine/world.cpp
               src/entities/playerCharacter.cpp
               src/entities/orbitBall.cpp)

target_include_directories(${PROJECT_NAME} 
                           PRIVATE 
                           include)

target_link_libraries(${PROJECT_NAME} 
                      PRIVATE 
                      sfml-graphics 
                      sfml-window 
                      sfml-audio)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
