cmake_minimum_required(VERSION 2.80)

project(ecef)

include_directories(aquarius2)
link_directories(../out/runtime)

#add_definitions(-D_AFXDLL)
set(CMAKE_MFC_FLAG 1)
add_compile_options(/MT)


set(MSVCCMAKE_PCH ${CMAKE_SOURCE_DIR})
set(PCH_HEADER ${CMAKE_SOURCE_DIR}/stdafx.h)
set(PCH_SOURCE ${CMAKE_SOURCE_DIR}/stdafx.cpp)
LIST(APPEND CMAKE_MODULE_PATH ${MSVCCMAKE_PCH})
INCLUDE(msvcpch)


set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/../out)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../out)
aux_source_directory(./ SOURCES)

#############################################################

# dynamic link library
add_library(ecef SHARED ecef.def ecef.rc ${SOURCES})
set_target_properties(ecef PROPERTIES SUFFIX ".fne")
target_link_libraries(ecef PUBLIC aquarius2.lib)
#USE_MSVC_PCH(ecef stdafx.h ${PCH_SOURCE})

#############################################################
# static library
add_library(ecef_static STATIC ${SOURCES})
target_compile_definitions(ecef_static PUBLIC -D__E_STATIC_LIB)
target_link_libraries(ecef_static PUBLIC aquarius2.lib)
USE_MSVC_PCH(ecef_static stdafx.h ${PCH_SOURCE})
