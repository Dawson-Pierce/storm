add_library(
    storm_filters
    STATIC
        kalman_filter.cpp
)

add_library(STORM::filters ALIAS storm_filters)

target_include_directories(
    storm_filters
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    storm_filters
    PUBLIC
        Eigen3::Eigen
)