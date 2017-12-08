
#include <string.h>
#include <jni.h>

#include "native.h"

#ifndef NELEM
#define NELEM(x) ((int)(sizeof(x) / sizeof((x)[0])))
#endif


extern "C"
{
	//初始化和注册部分

	
	/*
	JNIEXPORT jstring JNICALL Java_as_andc_sys_HelloJni_stringFromJNI(JNIEnv* env, jobject thiz)
	{
		return env->NewStringUTF("Hello from JNI !");
	}
	*/
/*
	static JNINativeMethod s_methods[] = {
	
	{"native_pause","()V",(void*) native_pause},
	{"native_setRunC","(Ljava/lang/String;)V",(void*) native_setRunC},
    {"native_setRootDir","(Ljava/lang/String;)V",(void*) native_setRootDir},
    {"native_setScreen","(II)V",(void*) native_setScreen},
    {"native_lockBitmap","()V",(void*) native_lockBitmap},
    {"native_unLockBitmap","()V",(void*) native_unLockBitmap},
	};
*/


static JNINativeMethod s_methods[] = {
	
	{"native_drawString","(Ljava/lang/String;)V",(void*) native_drawString},
	{"initJniId","()V",(void*) initJniId},
	
	};


static int register_methods(JNIEnv* env,char* class_name,JNINativeMethod* methods,int num_methods)
{
	jclass clazz;
	clazz =env->FindClass(class_name);
	//(*env)->FindClass(env, class_name);
	if (clazz == NULL) {
		return JNI_FALSE;
	}
	if (env->RegisterNatives(clazz, methods, num_methods) < 0) {
		return JNI_FALSE;
	}
	return JNI_TRUE;
}

static int register_natives(JNIEnv *env)
{
	if(!register_methods(env, class_path_name, s_methods, NELEM(s_methods)))
		return JNI_FALSE;
		
	return JNI_TRUE;
}

}


//听说这是主函数？
jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;
    //mJavaVm = vm;
	if (vm->GetEnv( (void**) &env, JNI_VERSION_1_4) != JNI_OK) {
	   //初始化失败
	}
	
	if (register_natives(env) < 0) {
	   //注册本地方法失败
	}

	result = JNI_VERSION_1_4;
	return result;
}

