/* DO NOT EDIT THIS FILE - it is machine generated */

#ifdef __APPLE__
#include <JavaVM/jni.h>
#else
#include <jni.h>
#endif
/* Header for class org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD */

#ifndef _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
#define _Included_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NewFastNoiseSIMD
 * Signature: (I)J
 */
JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD
  (JNIEnv *, jclass, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    SIMDLevel
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_SIMDLevel
  (JNIEnv *, jclass);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFree
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetSeed
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeGetSeed
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed
  (JNIEnv *, jclass, jlong);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFrequency
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetNoiseType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetNoiseType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalOctaves
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalOctaves
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalLacunarity
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalLacunarity
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalGain
 * Signature: (JF)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalGain
  (JNIEnv *, jclass, jlong, jfloat);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeSetFractalType
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalType
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD
 * Method:    NativeFillNoiseSet
 * Signature: (J[FIIIIII)V
 */
JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSet
  (JNIEnv *, jclass, jlong, jfloatArray, jint, jint, jint, jint, jint, jint);

#ifdef __cplusplus
}
#endif
#endif