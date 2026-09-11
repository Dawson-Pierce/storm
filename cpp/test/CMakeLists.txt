if(CPP_ENABLE_PLOTTING)
    add_executable(
        storm_test_ggiw
        test_ggiw.cpp
    )

    target_link_libraries(
        storm_test_ggiw
        PRIVATE
            STORM::models
            STORM::plotting
    )

    add_test(
        NAME storm.ggiw_plot
        COMMAND storm_test_ggiw
    )
endif()
