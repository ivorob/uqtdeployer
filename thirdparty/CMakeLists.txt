CMAKE_MINIMUM_REQUIRED (VERSION 3.0)

IF (BUILD_TESTING)
    SET (BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
    SET (gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY (googletest)
ENDIF (BUILD_TESTING)
