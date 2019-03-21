# Try to find WOFF2Dec.
# Once done, this will define
#
#  WOFF2DEC_FOUND - system has WOFF2Dec.
#  WOFF2DEC_INCLUDE_DIRS - the WOFF2Dec include directories
#  WOFF2DEC_LIBRARIES - link these to use WOFF2Dec.

find_package(PkgConfig)
pkg_check_modules(PC_WOFF2DEC libwoff2dec)

find_path(WOFF2DEC_INCLUDE_DIRS
    NAMES woff2/decode.h
    HINTS ${PC_WOFF2DEC_INCLUDEDIR}
)

find_library(WOFF2DEC_LIBRARIES
    NAMES woff2dec
    HINTS ${PC_WOFF2DEC_LIBDIR}
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(WOFF2Dec
    REQUIRED_VARS WOFF2DEC_INCLUDE_DIRS WOFF2DEC_LIBRARIES
    FOUND_VAR WOFF2DEC_FOUND
    VERSION_VAR PC_WOFF2DEC_VERSION)

mark_as_advanced(
    WOFF2DEC_INCLUDE_DIRS
    WOFF2DEC_LIBRARIES
)