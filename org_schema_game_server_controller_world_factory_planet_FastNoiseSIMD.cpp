#include "org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD.h"
#include "FastNoiseSIMD.h"

#define L2P(l) reinterpret_cast<FastNoiseSIMD*>(l)

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_SIMDLevel(JNIEnv*, jclass)
{
	return FastNoiseSIMD::GetSIMDLevel();
}

JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD(JNIEnv*, jclass, jint seed)
{
	return reinterpret_cast<jlong>(FastNoiseSIMD::NewFastNoiseSIMD(seed));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFree(JNIEnv*, jclass, jlong p)
{
	delete L2P(p);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed(JNIEnv*, jclass, jlong p, jint seed)
{
	L2P(p)->SetSeed(seed);
}

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed(JNIEnv*, jclass, jlong p)
{
	return L2P(p)->GetSeed();
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency(JNIEnv*, jclass, jlong p, jfloat freq)
{
	L2P(p)->SetFrequency(freq);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetNoiseType(JNIEnv*, jclass, jlong p, jint noiseType)
{
	L2P(p)->SetNoiseType(static_cast<FastNoiseSIMD::NoiseType>(noiseType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalOctaves(JNIEnv*, jclass, jlong p, jint octaves)
{
	L2P(p)->SetFractalOctaves(static_cast<unsigned int>(octaves));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalLacunarity(JNIEnv*, jclass, jlong p, jfloat lacunarity)
{
	L2P(p)->SetFractalLacunarity(lacunarity);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalGain(JNIEnv*, jclass, jlong p, jfloat gain)
{
	L2P(p)->SetFractalGain(gain);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalType(JNIEnv*, jclass, jlong p, jint fractalType)
{
	L2P(p)->SetFractalType(static_cast<FastNoiseSIMD::FractalType>(fractalType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSet(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jint xStart, jint yStart, jint zStart, jint xSize, jint ySize, jint zSize)
{
	float* arrayP = static_cast<float*>(jEnv->GetFloatArrayElements(noiseSet, nullptr));

	L2P(p)->FillNoiseSet(arrayP, xStart, yStart, zStart, xSize, ySize, zSize);

	jEnv->ReleaseFloatArrayElements(noiseSet, arrayP, 0);
}
