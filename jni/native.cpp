#include <jni.h>

#include "native.h"

static jmethodID id_draw;
static jmethodID id_getCanvas;


void native_drawString(JNIEnv *env,jobject obj,jstring path)
{
	// jstring str=(*env)->NewStringUTF(env,"hello");

	 env->CallVoidMethod(obj,id_draw,path);

	 jobject can=env->CallObjectMethod(obj,id_getCanvas);
	 //获得Canvas类
	 jclass cls =env->GetObjectClass(can);
	
	jmethodID id_translate =env->GetMethodID(cls, "tr", "(Ljava/lang/String;)V");
	

	 
}

//注册java方法
void initJniId(JNIEnv * env,jobject obj)
{
    //HelloJni
	//jobject obj_emu=env->NewGlobalRef(obj);
	
	
    jclass cls =env->GetObjectClass(obj);
	
	id_draw =env->GetMethodID(cls, "draw", "(Ljava/lang/String;)V");
	
	id_getCanvas=env->GetMethodID(cls, "getCanvas", "()V");
	
	
	env->DeleteLocalRef(cls);
	
}
