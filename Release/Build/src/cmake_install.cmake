# Install script for directory: C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/CopperSpice/Prg/PrabhupadaDictionary/Release/Bin")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE EXECUTABLE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Release/Build/bin/PrabhupadaDictionary.exe")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./PrabhupadaDictionary.exe" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./PrabhupadaDictionary.exe")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/mingw64/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/./PrabhupadaDictionary.exe")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/ShrilaPrabhupada.jpg")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Sanskrit.db")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/PrabhupadaLila.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/PrabhupadaBukvary.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Letter.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Help.txt")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/m_YazykVector.ini")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/Start.bat")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gtb.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gti.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles/Fonts" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionaryFiles/Fonts/gtr.ttf")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary_CS-CZ.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary_EN-US.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary_ES-ES.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary_PT-BR.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources/PrabhupadaDictionaryFiles" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary_RU-RU.qm")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsCore1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsGui1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsNetwork1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsOpenGL1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsScript1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsSql1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsSvg1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsXml1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsXmlPatterns1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsPrabhupada1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/." TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/bin/libCsMultimedia1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./platforms" TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/lib/CsGuiWin1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./mediaservices" TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/lib/CsMultimedia_DirectShow1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./playlistformats" TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/lib/CsMultimedia_m3u1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./sqldrivers" TYPE FILE FILES "C:/CopperSpice/Lib/Release/1.8.0/lib/CsSqlPsql1.8.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/./resources" TYPE FILE FILES "C:/CopperSpice/Prg/PrabhupadaDictionary/Source/src/../resources/PrabhupadaDictionary.ico")
endif()

