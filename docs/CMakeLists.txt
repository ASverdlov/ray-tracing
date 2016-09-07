find_package(Doxygen)
if(DOXYGEN_FOUND)
  set(DOXYFILE ${CMAKE_HOME_DIRECTORY}/docs/Doxyfile)
  add_custom_target(docs
    ${DOXYGEN_EXECUTABLE} ${DOXYFILE}
    WORKING_DIRECTORY ${CMAKE_HOME_DIRECTORY}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif(DOXYGEN_FOUND)
