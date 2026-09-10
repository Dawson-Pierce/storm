# I assume this version is sufficient
cmake_minimum_required(VERSION 3.24)

# Define project, version, language
project(
    STORM
    VERSION 0.1.0
    LANGUAGES CXX
)

# So we don't fry our hardware with plotting software... 
option(STORM_ENABLE_PLOTTING "Enable desktop plotting support" OFF)
option(STORM_BUILD_TESTS "Build the STORM test scripts" ON)

# IDK what this does exactly
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Allow for fetching content
include(FetchContent)
set(FETCHCONTENT_BASE_DIR "${CMAKE_SOURCE_DIR}/dependencies" CACHE PATH
    "Directory for fetched dependencies")



################################ EIGEN ################################
find_package(Eigen3 3.4 QUIET NO_MODULE)
if(NOT Eigen3_FOUND)
    message(STATUS "Eigen3 not found locally, fetching from GitLab...")
    FetchContent_Declare(
        eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG        3.4.0
        GIT_SHALLOW    TRUE
    )
    set(EIGEN_BUILD_DOC OFF CACHE BOOL "" FORCE)
    set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
    # set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(eigen)
endif()



############################### PLOTTING ###############################
if(STORM_ENABLE_PLOTTING)
    find_package(Matplot++ QUIET CONFIG)

    if(NOT TARGET Matplot++::matplot)
        message(STATUS "Matplot++ not found locally, fetching from GitHub...")

        set(MATPLOTPP_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(MATPLOTPP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
        set(MATPLOTPP_BUILD_INSTALLER OFF CACHE BOOL "" FORCE)
        set(MATPLOTPP_BUILD_PACKAGE OFF CACHE BOOL "" FORCE)
        set(MATPLOTPP_BUILD_HIGH_RESOLUTION_WORLD_MAP OFF CACHE BOOL "" FORCE)
        set(MATPLOTPP_WITH_OPENCV OFF CACHE BOOL "" FORCE)

        FetchContent_Declare(
            matplotplusplus
            GIT_REPOSITORY https://github.com/alandefreitas/matplotplusplus.git
            GIT_TAG        v1.2.2
            GIT_SHALLOW    TRUE
        )

        FetchContent_MakeAvailable(matplotplusplus)
    endif()

endif()



########################## MODULES ########################## 

add_subdirectory(src/storm/dynamics)
add_subdirectory(src/storm/filters)
add_subdirectory(src/storm/models)
add_subdirectory(src/storm/rfs)

if(STORM_ENABLE_PLOTTING)
    add_subdirectory(src/storm/plotting)
endif()

if(STORM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()