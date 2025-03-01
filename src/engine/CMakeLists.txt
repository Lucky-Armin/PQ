set(engine_source_files
    engine.cpp

    optEngine.cpp
    mdEngine.cpp

    mmmdEngine.cpp
    qmmdEngine.cpp
    ringPolymerEngine.cpp
    ringPolymerqmmdEngine.cpp

    hybridMDEngine.cpp
    qmmmMDEngine.cpp

    engineOutput.cpp
)

if(BUILD_WITH_KOKKOS)
    set(engine_source_files
        ${engine_source_files}
        engine_kokkos.cpp
    )
endif()

add_library(engine
    ${engine_source_files}
)

target_include_directories(engine
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include/engine
    PRIVATE
    ${PROJECT_SOURCE_DIR}/external/progressbar/include
)

if(BUILD_WITH_MPI)
    target_link_libraries(engine
        PRIVATE
        MPI::MPI_C
        PQ_mpi
    )
endif()

target_link_libraries(engine
    PUBLIC
    constraints
    integrator
    manostat
    potential
    resetKinetics
    settings
    thermostat
    output
    simulationBox
    timings
    physicalData
    virial
    forceField
    intraNonBonded
    references

    optimization
    QM
    externalQM
)

if(BUILD_WITH_ASE)
    target_link_libraries(engine
        PUBLIC
        aseQM
    )
endif()

if(BUILD_WITH_KOKKOS)
    target_link_libraries(engine
        PUBLIC
        nonCoulombPotential_kokkos
        coulombPotential_kokkos
    )
endif()

if(BUILD_WITH_PYBIND11)
    target_include_directories(engine
        PRIVATE
        ${pybind11_INCLUDE_DIR}
    )
    target_link_libraries(engine
        PRIVATE
        pybind11::embed
    )
endif()

install(TARGETS engine
    DESTINATION ${CMAKE_INSTALL_PREFIX}/lib/
)