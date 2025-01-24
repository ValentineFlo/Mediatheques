project(api)

set (HEADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

set (HEADERS
    ${HEADER_DIR}/Api.h
    ${HEADER_DIR}/Interpreter.h
    ${HEADER_DIR}/Client.h
    ${HEADER_DIR}/Medias.h
    ${HEADER_DIR}/Borrow.h
    ${HEADER_DIR}/Command.h
    ${HEADER_DIR}/Console.h
    ${HEADER_DIR}/Exceptions.h
    ${HEADER_DIR}/Process.h
)

set (SOURCES
    ${SOURCE_DIR}/Api.cpp
    ${SOURCE_DIR}/Interpreter.cpp
    ${SOURCE_DIR}/Command.cpp
    ${SOURCE_DIR}/Client.cpp
    ${SOURCE_DIR}/Medias.cpp
    ${SOURCE_DIR}/Borrow.cpp
    ${SOURCE_DIR}/Console.cpp
)

add_library(${PROJECT_NAME}
STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(${PROJECT_NAME} 
PUBLIC 
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${HEADER_DIR}>
)

set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Libraries")
