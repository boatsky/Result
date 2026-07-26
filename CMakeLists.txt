cmake_minimum_required(VERSION 3.12)

add_library(leaf_Result INTERFACE)
target_include_directories(leaf_Result INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(leaf_Result INTERFACE c_std_23)
