#include <jni.h>
#include <android/log.h>

// Fungsi log agar kita bisa pantau di Logcat kalau berhasil
#define LOG_TAG "MOD_PAIRIP"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

extern "C" {

    // 1. Fungsi standar yang sering dicari lib_musicolet
    void ExecuteProgram() {
        LOGI("ExecuteProgram dipanggil!");
    }

    // 2. Fungsi VMRunner: invoke (Untuk versi lama/tertentu)
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_invoke(JNIEnv *env, jclass clazz, jstring str, jobjectArray args) {
        LOGI("VMRunner_invoke dipanggil.");
        return nullptr; 
    }

    // 3. Fungsi VMRunner: executeVM (Berdasarkan logcat terakhir kamu)
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_executeVM(JNIEnv *env, jclass clazz, jobjectArray args) {
        LOGI("VMRunner_executeVM dipanggil. Bypass sukses!");
        return nullptr;
    }

    // 4. Inisialisasi Library
    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
        LOGI("Library PairIP Palsu v2 Berhasil Dimuat!");
        return JNI_VERSION_1_6;
    }
}
