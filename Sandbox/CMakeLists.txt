# THIS IS TEMPORARY, CHANGE THIS TO BE AN OPTION LATER ON
set(MINGW_PATH "C:/msys64/ucrt64/")

cmake_minimum_required(VERSION 3.10)

project(Application VERSION 0.0.1)

# set the core directory
set(CORE "${WORKING_DIRECTORY}../core")

# set include dir
set(CORE_INCLUDE_DIR "${CORE}/include")
set(CORE_INCLUDE_LIB "${CORE}/bin")

include_directories(external)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

target_include_directories(${PROJECT_NAME} PUBLIC ${MINGW_PATH}/include)

target_include_directories(${PROJECT_NAME} PUBLIC
 ${PROJECT_SOURCE_DIR}/src
 ${CORE_INCLUDE_DIR}
)

target_link_directories(${PROJECT_NAME} PUBLIC
 ${CORE_INCLUDE_LIB}
)

target_link_libraries(${PROJECT_NAME} libcore)