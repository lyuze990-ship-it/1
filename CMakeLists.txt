cmake_minimum_required(VERSION 3.16)
project(ShootingGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 源文件列表
set(SOURCES
    src/main.cpp
    src/core/engine.cpp
    src/core/window.cpp
    src/game/game_manager.cpp
    src/game/player.cpp
    src/game/team.cpp
    src/game/weapon.cpp
    src/game/map.cpp
    src/graphics/renderer.cpp
    src/graphics/shader.cpp
    src/graphics/model.cpp
    src/graphics/camera.cpp
    src/physics/physics_engine.cpp
    src/physics/collision.cpp
)

# 创建可执行文件
add_executable(ShootingGame ${SOURCES})

# 查找依赖库
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(assimp REQUIRED)

# 链接库
target_link_libraries(ShootingGame
    OpenGL::OpenGL
    glfw
    glm::glm
    assimp::assimp
)

# 包含目录
target_include_directories(ShootingGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 编译选项
if(MSVC)
    target_compile_options(ShootingGame PRIVATE /W4)
else()
    target_compile_options(ShootingGame PRIVATE -Wall -Wextra -Wpedantic)
endif()
