#include <jni.h>
#include <android/log.h>

#define LOG_TAG "DUMMY_PAIRIP"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {

    // Simbol ini yang dicari oleh lib_musicolet.so
    void ExecuteProgram() {
        LOGI("Fungsi ExecuteProgram dipanggil! Bypass berhasil.");
        // Biarkan kosong agar tidak crash
    }

    // Fungsi JNI ini yang dipanggil oleh class VMRunner.smali
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_invoke(JNIEnv *env, jclass clazz, jstring str, jobjectArray args) {
        LOGI("VMRunner.invoke dipanggil dari Smali.");
        // Kita kembalikan NULL (nullptr) agar Java tidak error
        return nullptr;
    }
}
