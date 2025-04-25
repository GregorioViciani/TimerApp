# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QtApp_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QtApp_autogen.dir\\ParseCache.txt"
  "CMakeFiles\\tests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\tests_autogen.dir\\ParseCache.txt"
  "QtApp_autogen"
  "tests_autogen"
  )
endif()
