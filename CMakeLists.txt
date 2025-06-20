cmake_minimum_required(VERSION 3.14)
project(RendellStuff VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)

set(BINARY_NAME rendell_stuff)

add_subdirectory(glm)

add_subdirectory(logx)

add_subdirectory(rendell)

add_subdirectory(rendell-text)
# Specify PUBLIC to link the rendell-ui to this stuff.
target_link_libraries(rendell_text PUBLIC glm logx rendell)

add_subdirectory(rendell-ui)
target_link_libraries(rendell_ui PRIVATE rendell_text)

add_library(${BINARY_NAME} STATIC
    $<TARGET_OBJECTS:glm>
    $<TARGET_OBJECTS:logx>
    $<TARGET_OBJECTS:rendell>
    $<TARGET_OBJECTS:rendell_ui>
    $<TARGET_OBJECTS:rendell_text>
)

target_link_libraries(${BINARY_NAME} PUBLIC
    glm
    $<IF:$<TARGET_EXISTS:logx>,logx,>
    $<IF:$<TARGET_EXISTS:rendell>,rendell,>
    $<IF:$<TARGET_EXISTS:rendell_ui>,rendell_ui,>
    $<IF:$<TARGET_EXISTS:rendell_text>,rendell_text,>
)


target_include_directories(${BINARY_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/logx/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/rendell/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/rendell-ui/include>
)
