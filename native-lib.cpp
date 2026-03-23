#include <jni.h>

extern "C" {
    // Fungsi dasar yang dicari lib_musicolet
    void ExecuteProgram() {}

    // Jalur invoke: Kita kembalikan string kosong alih-alih nullptr
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_invoke(JNIEnv *env, jclass clazz, jstring str, jobjectArray args) {
        jstring empty = env->NewStringUTF("");
        return empty;
    }

    // Jalur executeVM: Kita kembalikan argumen pertama jika ada agar tidak null crash
    JNIEXPORT jobject JNICALL
    Java_com_pairip_VMRunner_executeVM(JNIEnv *env, jclass clazz, jobjectArray args) {
        if (args != nullptr && env->GetArrayLength(args) > 0) {
            return env->GetObjectArrayElement(args, 0);
        }
        return nullptr;
    }

    JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
        return JNI_VERSION_1_6;
    }
}
