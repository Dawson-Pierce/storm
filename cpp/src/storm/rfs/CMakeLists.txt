add_library(
    storm_rfs
    STATIC
        phd.cpp
)

add_library(STORM::rfs ALIAS storm_rfs)

target_include_directories(
    storm_rfs
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    storm_rfs
    PUBLIC
        Eigen3::Eigen
)