cmake_minimum_required(VERSION 3.14)
project(finalProject)

set(CMAKE_CXX_STANDARD 14)
set(SDL_DIR1 /opt/homebrew/Cellar/sdl2/2.0.18/) # 这个SDL开发包的路径,可以通 过brew info sdl2查出来
set(SDL_DIR2 /opt/homebrew/Cellar/sdl2_image/2.0.5/)
set(SDL_DIR3 /opt/homebrew/Cellar/sdl2_ttf/2.0.15/)
set(SDL_DIR4 /opt/homebrew/Cellar/sdl2_mixer/2.0.4_2/)

include_directories(${SDL_DIR1}/include/) # 添加SDL头文件搜索路径
include_directories(${SDL_DIR2}/include/) # 添加SDL头文件搜索路径
include_directories(${SDL_DIR3}/include/) # 添加SDL头文件搜索路径
include_directories(${SDL_DIR4}/include/) # 添加SDL头文件搜索路径
link_directories(${SDL_DIR1}/lib/) # 增加SDL链接库目录
link_directories(${SDL_DIR2}/lib/) # 增加SDL链接库目录
link_directories(${SDL_DIR3}/lib/) # 增加SDL链接库目录
link_directories(${SDL_DIR4}/lib/) # 增加SDL链接库目录
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(finalProject main.cpp)
target_link_libraries(finalProject ${SDL2_LIBRARIES}${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_MIXER_LIBRARY} ${SDL2_bgi_LIBRARY}) # 链接目标库