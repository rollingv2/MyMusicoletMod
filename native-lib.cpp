#include <jni.h>

extern "C" {
    // Fungsi agar lib_musicolet tidak crash saat mencari simbol
    void ExecuteProgram() {
        // Kosongkan saja
    }

    // Fungsi untuk bypass VMRunner di Smali
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_invoke(JNIEnv *env, jclass clazz, jstring str, jobjectArray args) {
        return nullptr;
    }
}

