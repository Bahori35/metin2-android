#include "StdAfx.h"
#include "PythonApplication.h"
#include <jni.h>
#include <android/log.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#define LOG_TAG "Metin2Mobile"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" {

JNIEXPORT void JNICALL Java_com_metin2_client_NativeLib_init(JNIEnv* env, jobject obj, jobject assetManager, jint width, jint height) {
    LOGI("Initializing Metin2 Mobile Engine (%dx%d)", width, height);
    
    // Store AAssetManager globally
    extern AAssetManager* g_pAssetManager;
    g_pAssetManager = AAssetManager_fromJava(env, assetManager);

    static CPythonApplication app;
    
    // We pass NULL for poSelf (Python self object) as we are calling from C++ side
    // and provide some default name, width, height.
    if (!app.Create(NULL, "Metin2Mobile", width, height, 1)) {
        LOGE("CPythonApplication::Create failed!");
        return;
    }
    
    LOGI("Metin2 Mobile Engine Initialized Successfuly");
}

JNIEXPORT void JNICALL Java_com_metin2_client_NativeLib_render(JNIEnv* env, jobject obj) {
    if (CPythonApplication::InstancePtr()) {
        static DWORD dwLastTime = 0;
        DWORD dwCurrentTime = ELTimer_GetMSec();
        
        if (dwLastTime == 0) dwLastTime = dwCurrentTime;
        
        // Update the application
        CPythonApplication::InstancePtr()->Update();
        
        // Render the application
        CPythonApplication::InstancePtr()->Render();
        
        dwLastTime = dwCurrentTime;
    }
}

JNIEXPORT void JNICALL Java_com_metin2_client_NativeLib_touchEvent(JNIEnv* env, jobject obj, jint action, jfloat x, jfloat y) {
    if (CPythonApplication::InstancePtr()) {
        // action matches Android MotionEvent actions:
        // 0: ACTION_DOWN
        // 1: ACTION_UP
        // 2: ACTION_MOVE
        
        if (action == 0) { // ACTION_DOWN
             CPythonApplication::InstancePtr()->OnMouseLeftButtonDown(x, y);
        } else if (action == 1) { // ACTION_UP
             CPythonApplication::InstancePtr()->OnMouseLeftButtonUp(x, y);
        } else if (action == 2) { // ACTION_MOVE
             CPythonApplication::InstancePtr()->OnMouseMove(x, y);
        }
    }
}

}
