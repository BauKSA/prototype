cmake_minimum_required(VERSION 3.10)

project(Prototype)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Archivos fuente
file(GLOB_RECURSE SOURCES 
    src/*.cpp
    src/*/*.cpp
    src/*/*/*.cpp
)

add_executable(Prototype ${SOURCES} "include/game/system/PlayerInput.h" "src/game/system/playerInput.cpp" "include/game/component/Speed.h" "include/game/system/Movement.h" "src/game/system/movement.cpp" "include/game/system/ConstantForwardMovement.h" "src/game/system/constantForwardMovement.cpp" "include/actors/bullet/Bullet.h" "src/actors/bullet/bullet.cpp" "include/game/component/State.h"  "include/game/input/PlayerShoot.h" "src/game/input/playerShoot.cpp" "src/game/entity.cpp"  "include/actors/star/Star.h" "src/actors/star/star.cpp" "include/actors/camera/Camera.h" "src/actors/camera/camera.cpp" "include/game/component/Layer.h" "src/game/component/layer.cpp"    "include/game/component/Shape.h" "include/actors/splinter/Splinter.h"  "src/actors/splinter/splinter.cpp" "include/actors/explosion/Explosion.h" "include/game/system/CollisionSystem.h" "include/game/system/AABB.h" "src/game/system/aabb.cpp" "include/game/system/CollisionSystem.h" "src/game/system/collisionSystem.cpp")

target_include_directories(Prototype
    PRIVATE "${PROJECT_SOURCE_DIR}/include"
    PRIVATE "C:/Program Files/SFML/include"
)
target_link_libraries(Prototype sfml-graphics sfml-window sfml-system)
