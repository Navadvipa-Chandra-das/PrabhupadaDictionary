list(APPEND PrabhupadaDictionary_INCLUDES
  ${CMAKE_CURRENT_SOURCE_DIR}/PrabhupadaDictionary_build_info.h
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaLoginWindow.h
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaDictionaryWindow.h
  ${CMAKE_CURRENT_SOURCE_DIR}/PrabhupadaUtil.h
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaStorage.h
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaDictionary.h
)

list(APPEND PrabhupadaDictionary_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/PrabhupadaMain.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaLoginWindow.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaDictionaryWindow.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/PrabhupadaUtil.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaStorage.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/QPrabhupadaDictionary.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/../forms/QPrabhupadaLoginWindow.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/../forms/QPrabhupadaDictionaryWindow.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_en.ts
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_de.ts
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_fr.ts
  #qrc_NewRosource.cpp
  qrc_PrabhupadaDictionary.cpp
)

#include(audio/audio.cmake)
#include(camera/camera.cmake)
#include(graphics/graphics.cmake)
#include(network/network.cmake)
#include(views/views.cmake)
#include(widgets/widgets.cmake)

# location for *.qm file, overrides build folder
set( TS_OUTPUT_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/../resources )

# run lrelease to generate translation files
COPPERSPICE_RESOURCES(
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_en.ts
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_de.ts
  ${CMAKE_CURRENT_SOURCE_DIR}/../resources/ks_fr.ts
)

# run rcc to generate qrc output
COPPERSPICE_RESOURCES(
  #${CMAKE_CURRENT_SOURCE_DIR}/../NewRosource.qrc
  ${CMAKE_CURRENT_SOURCE_DIR}/../PrabhupadaDictionary.qrc
)

# run uic to generate source
COPPERSPICE_RESOURCES(
  ${CMAKE_CURRENT_SOURCE_DIR}/../forms/QPrabhupadaLoginWindow.ui
  ${CMAKE_CURRENT_SOURCE_DIR}/../forms/QPrabhupadaDictionaryWindow.ui
)

add_executable( PrabhupadaDictionary ${PrabhupadaDictionary_SOURCES} )

target_include_directories(PrabhupadaDictionary
  PRIVATE
  ${CMAKE_SOURCE_DIR}/src
  #${CMAKE_CURRENT_SOURCE_DIR}/audio
  #${CMAKE_CURRENT_SOURCE_DIR}/camera
  #${CMAKE_CURRENT_SOURCE_DIR}/graphics
  #${CMAKE_CURRENT_SOURCE_DIR}/network
  #${CMAKE_CURRENT_SOURCE_DIR}/views
  #${CMAKE_CURRENT_SOURCE_DIR}/widgets
)

target_link_libraries(PrabhupadaDictionary
  CopperSpice::CsCore
  CopperSpice::CsGui
  CopperSpice::CsNetwork
  CopperSpice::CsOpenGL
  CopperSpice::CsScript
  CopperSpice::CsSql
  CopperSpice::CsSvg
  CopperSpice::CsXml
  CopperSpice::CsXmlPatterns
)

if("Multimedia" IN_LIST COPPERSPICE_COMPONENTS)
  target_link_libraries(PrabhupadaDictionary CopperSpice::CsMultimedia)
endif()

# webkit temporarily removed, pending overflow issue resolution in CsWebKit

# if("WebKit" IN_LIST COPPERSPICE_COMPONENTS)
#  target_link_libraries(PrabhupadaDictionary CopperSpice::CsWebKit)
# endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  set_target_properties( PrabhupadaDictionary PROPERTIES OUTPUT_NAME PrabhupadaDictionary )

  target_link_libraries(PrabhupadaDictionary
    "-framework OpenGL"
  )

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")
  set_target_properties(PrabhupadaDictionary PROPERTIES OUTPUT_NAME PrabhupadaDictionary)

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")
  # disable console on windows
  target_link_libraries(PrabhupadaDictionary
    netapi32
    mpr
    -mwindows
  )

endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
  install(TARGETS PrabhupadaDictionary DESTINATION ../MacOS)
else()
  install(TARGETS PrabhupadaDictionary DESTINATION .)
endif()

# копирует файлы в папку установки
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/ShrilaPrabhupada.jpg DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/Sanskrit.db DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/PrabhupadaLila.txt DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/PrabhupadaBukvary.txt DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/Letter.txt DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionaryFiles/Help.txt DESTINATION ./resources/PrabhupadaDictionaryFiles)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/Start.bat DESTINATION .)

# installs the CopperSpice libraries
cs_copy_library(CsCore)
cs_copy_library(CsGui)
cs_copy_library(CsNetwork)
cs_copy_library(CsOpenGL)
cs_copy_library(CsScript)
cs_copy_library(CsSql)
cs_copy_library(CsSvg)
cs_copy_library(CsXml)
cs_copy_library(CsXmlPatterns)

if("Multimedia" IN_LIST COPPERSPICE_COMPONENTS)
  cs_copy_library(CsMultimedia)
endif()

if("WebKit" IN_LIST COPPERSPICE_COMPONENTS)
  # webkit temporarily removed, pending overflow issue resolution in CsWebKit
  # cs_copy_library(CsWebKit)
endif()

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")

  set(CPACK_DMG_VOLUME_NAME PrabhupadaDictionary)
  set(CPACK_DMG_FORMAT UDBZ)

  # installs the platform Gui plugin
  cs_copy_plugins(CsGui ../plugins)

  # two files
  if("Multimedia" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsMultimedia ../plugins)
  endif()
  if("Sql" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsSqlPsql ../plugins)
  endif()

  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionary.icns DESTINATION ./resources)

elseif(CMAKE_SYSTEM_NAME MATCHES "(Linux|OpenBSD|FreeBSD|NetBSD|DragonFly)")

  # installs the platform Gui plugin
  cs_copy_plugins(CsGui)
  cs_copy_plugins(CsOpenGL)

  # three files
  if("Multimedia" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsMultimedia)
  endif()
  if("Sql" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsSqlPsql)
  endif()

  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionary.png DESTINATION ./resources)

elseif(CMAKE_SYSTEM_NAME MATCHES "Windows")

  # installs the platform Gui plugin
  cs_copy_plugins(CsGui)

  # two files
  if("Multimedia" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsMultimedia)
  endif()
  if("Sql" IN_LIST COPPERSPICE_COMPONENTS)
    cs_copy_plugins(CsSqlPsql)
  endif()

  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/../resources/PrabhupadaDictionary.ico DESTINATION ./resources)

endif()
