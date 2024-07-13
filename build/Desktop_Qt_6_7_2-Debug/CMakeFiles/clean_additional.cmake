# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appSerialCommunication_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appSerialCommunication_autogen.dir/ParseCache.txt"
  "appSerialCommunication_autogen"
  )
endif()
