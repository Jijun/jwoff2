# Try to find WOFF2Enc.
# Once done, this will define
#
#  WOFF2ENC_FOUND - system has WOFF2Enc.
#  WOFF2ENC_INCLUDE_DIRS - the WOFF2Enc include directories
#  WOFF2ENC_LIBRARIES - link these to use WOFF2Enc.


find_package(PkgConfig)
pkg_check_modules(PC_WOFF2ENC libwoff2enc)

find_path(WOFF2ENC_INCLUDE_DIRS
    NAMES woff2/encode.h
    HINTS ${PC_WOFF2ENC_INCLUDEDIR}
)

find_library(WOFF2ENC_LIBRARIES
    NAMES woff2enc
    HINTS ${PC_WOFF2ENC_LIBDIR}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WOFF2Enc
    REQUIRED_VARS WOFF2ENC_INCLUDE_DIRS WOFF2ENC_LIBRARIES
    FOUND_VAR WOFF2ENC_FOUND
    VERSION_VAR PC_WOFF2ENC_VERSION)

mark_as_advanced(
    WOFF2ENC_INCLUDE_DIRS
    WOFF2ENC_LIBRARIES
)