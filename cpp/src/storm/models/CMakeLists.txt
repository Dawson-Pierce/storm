add_library(
    storm_models
    STATIC
        GGIW.cpp
)

add_library(STORM::models ALIAS storm_models)

target_include_directories(
    storm_models
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    storm_models
    PUBLIC
        Eigen3::Eigen
)