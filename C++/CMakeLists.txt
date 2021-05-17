cmake_minimum_required(VERSION 3.17)
project(C_Plus_Plus)

set(CMAKE_CXX_STANDARD 14)

file(GLOB APP_SOURCES */*.cpp)
foreach (source_file ${APP_SOURCES})
    get_filename_component(file_name ${source_file} NAME_WLE)
    get_filename_component(dirname ${source_file} DIRECTORY)
    string(REPLACE " " "-" executable_name ${file_name})
    message("${executable_name} | ${dirname}/${file_name}.cpp \n")
    add_executable("${executable_name}" ${dirname}//${file_name}.cpp)
endforeach (source_file ${APP_SOURCES})