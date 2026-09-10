add_library(
    storm_plot
    STATIC
        plot_GGIW.cpp
)

add_library(STORM::plotting ALIAS storm_plot)

target_include_directories(
    storm_plot
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    storm_plot
    PUBLIC
        Eigen3::Eigen
)