add_library(physicalData
    physicalData.cpp
)

target_include_directories(physicalData
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include/physicalData
)

target_link_libraries(physicalData
    PUBLIC
    utilities
    simulationBox
)

install(TARGETS physicalData
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
)