add_library(
    storm_dynamics
    STATIC
        constant_velocity.cpp
)

add_library(STORM::dynamics ALIAS storm_dynamics)

target_include_directories(
    storm_dynamics
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    storm_dynamics
    PUBLIC
        Eigen3::Eigen
)