cmake_minimum_required(VERSION 3.10.2)
project("Metin2Mobile")

add_definitions(-D__ANDROID__)
add_definitions(-DENABLE_OPENGL)
add_definitions(-DENABLE_MOBILE_CONTROLS)
add_definitions(-DLOCALE_SERVICE_EUROPE)

if(ANDROID)
    # Some older Granny versions use these for 64-bit
    add_definitions(-DGRANNY_ONLY_TYPES)
endif()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/android_compat
    ${CMAKE_CURRENT_SOURCE_DIR}/../Extern/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../Extern/include/granny2
    ${CMAKE_CURRENT_SOURCE_DIR}/../Extern/include/Python2
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/eterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/eterLib
    ${CMAKE_CURRENT_SOURCE_DIR}/eterPythonLib
    ${CMAKE_CURRENT_SOURCE_DIR}/gameLib
    ${CMAKE_CURRENT_SOURCE_DIR}/userInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/milesLib
    ${CMAKE_CURRENT_SOURCE_DIR}/effectLib
    ${CMAKE_CURRENT_SOURCE_DIR}/sphereLib
    ${CMAKE_CURRENT_SOURCE_DIR}/eterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/eterGrnLib
    ${CMAKE_CURRENT_SOURCE_DIR}/eterImageLib
    ${CMAKE_CURRENT_SOURCE_DIR}/speedTreeLib
    ${CMAKE_CURRENT_SOURCE_DIR}/prTerrainLib
    ${CMAKE_CURRENT_SOURCE_DIR}/scriptLib
    ${CMAKE_CURRENT_SOURCE_DIR}/eterLocale
    ${CMAKE_CURRENT_SOURCE_DIR}/cWebBrowser
)

set(ETER_BASE_SOURCES
    eterBase/CPostIt.cpp
    eterBase/CRC32.cpp
    eterBase/Debug.cpp
    eterBase/FileBase.cpp
    eterBase/FileDir.cpp
    eterBase/FileLoader.cpp
    eterBase/MappedFile.cpp
    eterBase/Random.cpp
    eterBase/StdAfx.cpp
    eterBase/Stl.cpp
    eterBase/TempFile.cpp
    eterBase/Timer.cpp
    eterBase/Utils.cpp
    eterBase/cipher.cpp
    eterBase/error.cpp
    eterBase/lzo.cpp
    eterBase/tea.cpp
)

set(ETER_LIB_SOURCES
    eterLib/Camera.cpp
    eterLib/GrpDevice.cpp
    eterLib/GrpObjectInstance.cpp
    eterLib/GrpScreen.cpp
    eterLib/GrpTexture.cpp
    eterLib/GrpImageTexture.cpp
    eterLib/GrpOpenGL.cpp
    eterLib/GrpBase.cpp
    eterLib/GrpColor.cpp
    eterLib/GrpColorInstance.cpp
    eterLib/GrpImage.cpp
    eterLib/GrpImageInstance.cpp
    eterLib/GrpIndexBuffer.cpp
    eterLib/GrpMath.cpp
    eterLib/GrpVertexBuffer.cpp
    eterLib/GrpText.cpp
    eterLib/GrpTextInstance.cpp
    eterLib/MSApplication.cpp
    eterLib/Input.cpp
    eterLib/NetDevice.cpp
    eterLib/ResourceManager.cpp
    eterLib/NetAddress.cpp
    eterLib/NetDatagramReceiver.cpp
    eterLib/NetDatagramSender.cpp
    eterLib/NetStream.cpp
    eterLib/StdAfx.cpp
    eterLib/AttributeData.cpp
    eterLib/AttributeInstance.cpp
    eterLib/CollisionData.cpp
    eterLib/Resource.cpp
    eterLib/TargaResource.cpp
    eterLib/TextFileLoader.cpp
    eterLib/Util.cpp
)

set(ETER_IMAGE_LIB_SOURCES
    eterImageLib/DXTCImage.cpp
    eterImageLib/Image.cpp
    eterImageLib/StdAfx.cpp
    eterImageLib/TGAImage.cpp
    eterImageLib/stb_image.cpp
)

set(GAME_LIB_SOURCES
    gameLib/Area.cpp
    gameLib/AreaLoaderThread.cpp
    gameLib/ActorInstance.cpp
    gameLib/ActorInstanceAttach.cpp
    gameLib/ActorInstanceBattle.cpp
    gameLib/ActorInstanceBlend.cpp
    gameLib/ActorInstanceCollisionDetection.cpp
    gameLib/ActorInstanceData.cpp
    gameLib/ActorInstanceEvent.cpp
    gameLib/ActorInstanceFly.cpp
    gameLib/ActorInstanceMotion.cpp
    gameLib/ActorInstanceMotionEvent.cpp
    gameLib/ActorInstancePosition.cpp
    gameLib/ActorInstanceRender.cpp
    gameLib/ActorInstanceRotation.cpp
    gameLib/ActorInstanceSync.cpp
    gameLib/ActorInstanceWeaponTrace.cpp
    gameLib/FlyingInstance.cpp
    gameLib/GameEventManager.cpp
    gameLib/ItemData.cpp
    gameLib/ItemManager.cpp
    gameLib/MapManager.cpp
    gameLib/MapOutdoor.cpp
    gameLib/PropertyManager.cpp
    gameLib/RaceData.cpp
    gameLib/RaceManager.cpp
    gameLib/StdAfx.cpp
)

set(USER_INTERFACE_SOURCES
    userInterface/AndroidMain.cpp
    userInterface/PythonApplication.cpp
    userInterface/PythonApplicationModule.cpp
    userInterface/PythonPlayerModule.cpp
    userInterface/PythonPlayer.cpp
    userInterface/PythonNetworkStream.cpp
    userInterface/PythonNetworkStreamModule.cpp
    userInterface/PythonNetworkStreamPhaseGame.cpp
    userInterface/PythonNetworkStreamPhaseLoading.cpp
    userInterface/PythonNetworkStreamPhaseLogin.cpp
    userInterface/PythonNetworkStreamPhaseSelect.cpp
    userInterface/UserInterface.cpp
    userInterface/StdAfx.cpp
)

set(ETER_PACK_SOURCES
    eterPack/EterPack.cpp
    eterPack/EterPackCursor.cpp
    eterPack/EterPackManager.cpp
    eterPack/EterPackPolicy_CSHybridCrypt.cpp
    eterPack/md5.c
    eterPack/StdAfx.cpp
)

set(ETER_GRN_LIB_SOURCES
    eterGrnLib/Material.cpp
    eterGrnLib/Mesh.cpp
    eterGrnLib/Model.cpp
    eterGrnLib/ModelInstance.cpp
    eterGrnLib/ModelInstanceCollisionDetection.cpp
    eterGrnLib/ModelInstanceModel.cpp
    eterGrnLib/ModelInstanceRender.cpp
    eterGrnLib/ModelInstanceUpdate.cpp
    eterGrnLib/StdAfx.cpp
    eterGrnLib/Thing.cpp
    eterGrnLib/ThingInstance.cpp
)

set(EFFECT_LIB_SOURCES
    effectLib/EffectData.cpp
    effectLib/EffectElementBase.cpp
    effectLib/EffectElementBaseInstance.cpp
    effectLib/EffectInstance.cpp
    effectLib/EffectManager.cpp
    effectLib/EffectMesh.cpp
    effectLib/EffectMeshInstance.cpp
    effectLib/EffectUpdateDecorator.cpp
    effectLib/EmitterProperty.cpp
    effectLib/FrameController.cpp
    effectLib/ParticleInstance.cpp
    effectLib/ParticleProperty.cpp
    effectLib/ParticleSystemData.cpp
    effectLib/ParticleSystemInstance.cpp
    effectLib/SimpleLightData.cpp
    effectLib/SimpleLightInstance.cpp
    effectLib/StdAfx.cpp
    effectLib/Type.cpp
)

set(ETER_PYTHON_LIB_SOURCES
    eterPythonLib/PythonGraphic.cpp
    eterPythonLib/PythonGraphicImageModule.cpp
    eterPythonLib/PythonGraphicModule.cpp
    eterPythonLib/PythonGraphicTextModule.cpp
    eterPythonLib/PythonGraphicThingModule.cpp
    eterPythonLib/PythonGridSlotWindow.cpp
    eterPythonLib/PythonSlotWindow.cpp
    eterPythonLib/PythonWindow.cpp
    eterPythonLib/PythonWindowManager.cpp
    eterPythonLib/PythonWindowManagerModule.cpp
    eterPythonLib/StdAfx.cpp
)

set(SCRIPT_LIB_SOURCES
    scriptLib/PythonDebugModule.cpp
    scriptLib/PythonLauncher.cpp
    scriptLib/PythonMarshal.cpp
    scriptLib/PythonUtils.cpp
    scriptLib/Resource.cpp
    scriptLib/StdAfx.cpp
)

set(SPHERE_LIB_SOURCES
    sphereLib/frustum.cpp
    sphereLib/sphere.cpp
    sphereLib/spherepack.cpp
    sphereLib/StdAfx.cpp
)

set(MILES_LIB_SOURCES
    milesLib/SoundBase.cpp
    milesLib/SoundData.cpp
    milesLib/SoundInstance2D.cpp
    milesLib/SoundInstance3D.cpp
    milesLib/SoundInstanceStream.cpp
    milesLib/SoundManager.cpp
    milesLib/SoundManager2D.cpp
    milesLib/SoundManager3D.cpp
    milesLib/SoundManagerStream.cpp
    milesLib/Stdafx.cpp
    milesLib/Type.cpp
)

set(SPEED_TREE_LIB_SOURCES
    speedTreeLib/BoundaryShapeManager.cpp
    speedTreeLib/SpeedGrassRT.cpp
    speedTreeLib/SpeedGrassWrapper.cpp
    speedTreeLib/SpeedTreeForest.cpp
    speedTreeLib/SpeedTreeForestDirectX8.cpp
    speedTreeLib/SpeedTreeWrapper.cpp
    speedTreeLib/StdAfx.cpp
)

set(PR_TERRAIN_LIB_SOURCES
    prTerrainLib/Terrain.cpp
    prTerrainLib/TextureSet.cpp
    prTerrainLib/StdAfx.cpp
)

set(ETER_LOCALE_SOURCES
    eterLocale/Arabic.cpp
    eterLocale/Japanese.cpp
    eterLocale/StringCodec.cpp
    eterLocale/StringCodec_Vietnamese.cpp
    eterLocale/StdAfx.cpp
)

if(NOT ANDROID)
    set(C_WEB_BROWSER_SOURCES
        cWebBrowser/CWebBrowser.c
    )
    add_definitions(-DENABLE_WEB_BROWSER) # Optional flag if the code needs it
else()
    set(C_WEB_BROWSER_SOURCES "")
endif()

add_library(metin2_mobile SHARED
    ${USER_INTERFACE_SOURCES}
    ${ETER_BASE_SOURCES}
    ${ETER_LIB_SOURCES}
    ${ETER_IMAGE_LIB_SOURCES}
    ${GAME_LIB_SOURCES}
    ${ETER_PACK_SOURCES}
    ${ETER_GRN_LIB_SOURCES}
    ${EFFECT_LIB_SOURCES}
    ${ETER_PYTHON_LIB_SOURCES}
    ${SCRIPT_LIB_SOURCES}
    ${SPHERE_LIB_SOURCES}
    ${MILES_LIB_SOURCES}
    ${SPEED_TREE_LIB_SOURCES}
    ${PR_TERRAIN_LIB_SOURCES}
    ${ETER_LOCALE_SOURCES}
    ${C_WEB_BROWSER_SOURCES}
)

# Extern Library linking
set(EXTERN_LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../Extern/lib/android/${ANDROID_ABI})
link_directories(${EXTERN_LIB_PATH})

find_library(log-lib log)
find_library(android-lib android)
find_library(gles3-lib GLESv3)

# Common Metin2 Libraries (Static)
set(METIN2_EXTERN_LIBS
    python2.7
    cryptopp
    lzo2
    il
    ilu
    ilut
    jpeg
    png
    speedtree
    granny2
    mss
)

target_link_libraries(metin2_mobile
    ${log-lib}
    ${android-lib}
    ${gles3-lib}
    ${METIN2_EXTERN_LIBS}
    z
    m
)
