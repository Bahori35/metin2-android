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
    ${CMAKE_CURRENT_SOURCE_DIR}/EterBase
    ${CMAKE_CURRENT_SOURCE_DIR}/EterLib
    ${CMAKE_CURRENT_SOURCE_DIR}/EterPythonLib
    ${CMAKE_CURRENT_SOURCE_DIR}/GameLib
    ${CMAKE_CURRENT_SOURCE_DIR}/UserInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/MilesLib
    ${CMAKE_CURRENT_SOURCE_DIR}/EffectLib
    ${CMAKE_CURRENT_SOURCE_DIR}/SphereLib
    ${CMAKE_CURRENT_SOURCE_DIR}/eterPack
    ${CMAKE_CURRENT_SOURCE_DIR}/EterGrnLib
    ${CMAKE_CURRENT_SOURCE_DIR}/EterImageLib
    ${CMAKE_CURRENT_SOURCE_DIR}/SpeedTreeLib
    ${CMAKE_CURRENT_SOURCE_DIR}/PRTerrainLib
    ${CMAKE_CURRENT_SOURCE_DIR}/ScriptLib
    ${CMAKE_CURRENT_SOURCE_DIR}/EterLocale
    ${CMAKE_CURRENT_SOURCE_DIR}/CWebBrowser
)

set(ETER_BASE_SOURCES
    EterBase/CPostIt.cpp
    EterBase/CRC32.cpp
    EterBase/Debug.cpp
    EterBase/FileBase.cpp
    EterBase/FileDir.cpp
    EterBase/FileLoader.cpp
    EterBase/MappedFile.cpp
    EterBase/Random.cpp
    EterBase/StdAfx.cpp
    EterBase/Stl.cpp
    EterBase/TempFile.cpp
    EterBase/Timer.cpp
    EterBase/Utils.cpp
    EterBase/cipher.cpp
    EterBase/error.cpp
    EterBase/lzo.cpp
    EterBase/tea.cpp
)

set(ETER_LIB_SOURCES
    EterLib/Camera.cpp
    EterLib/GrpDevice.cpp
    EterLib/GrpObjectInstance.cpp
    EterLib/GrpScreen.cpp
    EterLib/GrpTexture.cpp
    EterLib/GrpImageTexture.cpp
    EterLib/GrpOpenGL.cpp
    EterLib/GrpBase.cpp
    EterLib/GrpColor.cpp
    EterLib/GrpColorInstance.cpp
    EterLib/GrpImage.cpp
    EterLib/GrpImageInstance.cpp
    EterLib/GrpIndexBuffer.cpp
    EterLib/GrpMath.cpp
    EterLib/GrpVertexBuffer.cpp
    EterLib/GrpText.cpp
    EterLib/GrpTextInstance.cpp
    EterLib/MSApplication.cpp
    EterLib/Input.cpp
    EterLib/NetDevice.cpp
    EterLib/ResourceManager.cpp
    EterLib/NetAddress.cpp
    EterLib/NetDatagramReceiver.cpp
    EterLib/NetDatagramSender.cpp
    EterLib/NetStream.cpp
    EterLib/StdAfx.cpp
    EterLib/AttributeData.cpp
    EterLib/AttributeInstance.cpp
    EterLib/CollisionData.cpp
    EterLib/Resource.cpp
    EterLib/TargaResource.cpp
    EterLib/TextFileLoader.cpp
    EterLib/Util.cpp
)

set(ETER_IMAGE_LIB_SOURCES
    EterImageLib/DXTCImage.cpp
    EterImageLib/Image.cpp
    EterImageLib/StdAfx.cpp
    EterImageLib/TGAImage.cpp
    EterImageLib/stb_image.cpp
)

set(GAME_LIB_SOURCES
    GameLib/Area.cpp
    GameLib/AreaLoaderThread.cpp
    GameLib/ActorInstance.cpp
    GameLib/ActorInstanceAttach.cpp
    GameLib/ActorInstanceBattle.cpp
    GameLib/ActorInstanceBlend.cpp
    GameLib/ActorInstanceCollisionDetection.cpp
    GameLib/ActorInstanceData.cpp
    GameLib/ActorInstanceEvent.cpp
    GameLib/ActorInstanceFly.cpp
    GameLib/ActorInstanceMotion.cpp
    GameLib/ActorInstanceMotionEvent.cpp
    GameLib/ActorInstancePosition.cpp
    GameLib/ActorInstanceRender.cpp
    GameLib/ActorInstanceRotation.cpp
    GameLib/ActorInstanceSync.cpp
    GameLib/ActorInstanceWeaponTrace.cpp
    GameLib/FlyingInstance.cpp
    GameLib/GameEventManager.cpp
    GameLib/ItemData.cpp
    GameLib/ItemManager.cpp
    GameLib/MapManager.cpp
    GameLib/MapOutdoor.cpp
    GameLib/PropertyManager.cpp
    GameLib/RaceData.cpp
    GameLib/RaceManager.cpp
    GameLib/StdAfx.cpp
)

set(USER_INTERFACE_SOURCES
    UserInterface/AndroidMain.cpp
    UserInterface/PythonApplication.cpp
    UserInterface/PythonApplicationModule.cpp
    UserInterface/PythonPlayerModule.cpp
    UserInterface/PythonPlayer.cpp
    UserInterface/PythonNetworkStream.cpp
    UserInterface/PythonNetworkStreamModule.cpp
    UserInterface/PythonNetworkStreamPhaseGame.cpp
    UserInterface/PythonNetworkStreamPhaseLoading.cpp
    UserInterface/PythonNetworkStreamPhaseLogin.cpp
    UserInterface/PythonNetworkStreamPhaseSelect.cpp
    UserInterface/UserInterface.cpp
    UserInterface/StdAfx.cpp
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
    EterGrnLib/Material.cpp
    EterGrnLib/Mesh.cpp
    EterGrnLib/Model.cpp
    EterGrnLib/ModelInstance.cpp
    EterGrnLib/ModelInstanceCollisionDetection.cpp
    EterGrnLib/ModelInstanceModel.cpp
    EterGrnLib/ModelInstanceRender.cpp
    EterGrnLib/ModelInstanceUpdate.cpp
    EterGrnLib/StdAfx.cpp
    EterGrnLib/Thing.cpp
    EterGrnLib/ThingInstance.cpp
)

set(EFFECT_LIB_SOURCES
    EffectLib/EffectData.cpp
    EffectLib/EffectElementBase.cpp
    EffectLib/EffectElementBaseInstance.cpp
    EffectLib/EffectInstance.cpp
    EffectLib/EffectManager.cpp
    EffectLib/EffectMesh.cpp
    EffectLib/EffectMeshInstance.cpp
    EffectLib/EffectUpdateDecorator.cpp
    EffectLib/EmitterProperty.cpp
    EffectLib/FrameController.cpp
    EffectLib/ParticleInstance.cpp
    EffectLib/ParticleProperty.cpp
    EffectLib/ParticleSystemData.cpp
    EffectLib/ParticleSystemInstance.cpp
    EffectLib/SimpleLightData.cpp
    EffectLib/SimpleLightInstance.cpp
    EffectLib/StdAfx.cpp
    EffectLib/Type.cpp
)

set(ETER_PYTHON_LIB_SOURCES
    EterPythonLib/PythonGraphic.cpp
    EterPythonLib/PythonGraphicImageModule.cpp
    EterPythonLib/PythonGraphicModule.cpp
    EterPythonLib/PythonGraphicTextModule.cpp
    EterPythonLib/PythonGraphicThingModule.cpp
    EterPythonLib/PythonGridSlotWindow.cpp
    EterPythonLib/PythonSlotWindow.cpp
    EterPythonLib/PythonWindow.cpp
    EterPythonLib/PythonWindowManager.cpp
    EterPythonLib/PythonWindowManagerModule.cpp
    EterPythonLib/StdAfx.cpp
)

set(SCRIPT_LIB_SOURCES
    ScriptLib/PythonDebugModule.cpp
    ScriptLib/PythonLauncher.cpp
    ScriptLib/PythonMarshal.cpp
    ScriptLib/PythonUtils.cpp
    ScriptLib/Resource.cpp
    ScriptLib/StdAfx.cpp
)

set(SPHERE_LIB_SOURCES
    SphereLib/frustum.cpp
    SphereLib/sphere.cpp
    SphereLib/spherepack.cpp
    SphereLib/StdAfx.cpp
)

set(MILES_LIB_SOURCES
    MilesLib/SoundBase.cpp
    MilesLib/SoundData.cpp
    MilesLib/SoundInstance2D.cpp
    MilesLib/SoundInstance3D.cpp
    MilesLib/SoundInstanceStream.cpp
    MilesLib/SoundManager.cpp
    MilesLib/SoundManager2D.cpp
    MilesLib/SoundManager3D.cpp
    MilesLib/SoundManagerStream.cpp
    MilesLib/Stdafx.cpp
    MilesLib/Type.cpp
)

set(SPEED_TREE_LIB_SOURCES
    SpeedTreeLib/BoundaryShapeManager.cpp
    SpeedTreeLib/SpeedGrassRT.cpp
    SpeedTreeLib/SpeedGrassWrapper.cpp
    SpeedTreeLib/SpeedTreeForest.cpp
    SpeedTreeLib/SpeedTreeForestDirectX8.cpp
    SpeedTreeLib/SpeedTreeWrapper.cpp
    SpeedTreeLib/StdAfx.cpp
)

set(PR_TERRAIN_LIB_SOURCES
    PRTerrainLib/Terrain.cpp
    PRTerrainLib/TextureSet.cpp
    PRTerrainLib/StdAfx.cpp
)

set(ETER_LOCALE_SOURCES
    EterLocale/Arabic.cpp
    EterLocale/Japanese.cpp
    EterLocale/StringCodec.cpp
    EterLocale/StringCodec_Vietnamese.cpp
    EterLocale/StdAfx.cpp
)

if(NOT ANDROID)
    set(C_WEB_BROWSER_SOURCES
        CWebBrowser/CWebBrowser.c
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
