#include "FastNoiseSIMD_JNI.h"
#include "FastNoiseSIMD/FastNoiseSIMD.h"

#define L_2_FNP(l) reinterpret_cast<FastNoiseSIMD*>(l)
#define L_2_VSP(l) reinterpret_cast<FastNoiseVectorSet*>(l)

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_GetSIMDLevel(JNIEnv*, jclass)
{
	return FastNoiseSIMD::GetSIMDLevel();
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_SetSIMDLevel(JNIEnv*, jclass, jint level)
{
	FastNoiseSIMD::SetSIMDLevel(level);
}

JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD(JNIEnv*, jclass, jint seed)
{
	return reinterpret_cast<jlong>(FastNoiseSIMD::NewFastNoiseSIMD(seed));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFree(JNIEnv*, jclass, jlong p)
{
	delete L_2_FNP(p);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed(JNIEnv*, jclass, jlong p, jint seed)
{
	L_2_FNP(p)->SetSeed(seed);
}

JNIEXPORT jint JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed(JNIEnv*, jclass, jlong p)
{
	return L_2_FNP(p)->GetSeed();
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency(JNIEnv*, jclass, jlong p, jfloat freq)
{
	L_2_FNP(p)->SetFrequency(freq);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetNoiseType(JNIEnv*, jclass, jlong p, jint noiseType)
{
	L_2_FNP(p)->SetNoiseType(static_cast<FastNoiseSIMD::NoiseType>(noiseType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetAxisScales(JNIEnv*, jclass, jlong p, jfloat xScale, jfloat yScale, jfloat zScale)
{
	L_2_FNP(p)->SetAxisScales(xScale, yScale, zScale);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalOctaves(JNIEnv*, jclass, jlong p, jint octaves)
{
	L_2_FNP(p)->SetFractalOctaves(static_cast<unsigned int>(octaves));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalLacunarity(JNIEnv*, jclass, jlong p, jfloat lacunarity)
{
	L_2_FNP(p)->SetFractalLacunarity(lacunarity);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalGain(JNIEnv*, jclass, jlong p, jfloat gain)
{
	L_2_FNP(p)->SetFractalGain(gain);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFractalType(JNIEnv*, jclass, jlong p, jint fractalType)
{
	L_2_FNP(p)->SetFractalType(static_cast<FastNoiseSIMD::FractalType>(fractalType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularDistanceFunction(JNIEnv*, jclass, jlong p, jint cellularDistanceFunction)
{
	L_2_FNP(p)->SetCellularDistanceFunction(static_cast<FastNoiseSIMD::CellularDistanceFunction>(cellularDistanceFunction));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetCellularReturnType(JNIEnv*, jclass, jlong p, jint cellularReturnType)
{
	L_2_FNP(p)->SetCellularReturnType(static_cast<FastNoiseSIMD::CellularReturnType>(cellularReturnType));
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSet(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jint xStart, jint yStart, jint zStart, jint xSize, jint ySize, jint zSize)
{
	float* arrayP = jEnv->GetFloatArrayElements(noiseSet, nullptr);

	L_2_FNP(p)->FillNoiseSet(arrayP, xStart, yStart, zStart, xSize, ySize, zSize);

	jEnv->ReleaseFloatArrayElements(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSet(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jint xStart, jint yStart, jint zStart, jint xSize, jint ySize, jint zSize, jint sampleScale)
{
	float* arrayP = static_cast<float*>(jEnv->GetFloatArrayElements(noiseSet, nullptr));

	L_2_FNP(p)->FillSampledNoiseSet(arrayP, xStart, yStart, zStart, xSize, ySize, zSize, sampleScale);

	jEnv->ReleaseFloatArrayElements(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillNoiseSetVector(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jlong pVS, jfloat xOffset, jfloat yOffset, jfloat zOffset)
{
	float* arrayP = static_cast<float*>(jEnv->GetFloatArrayElements(noiseSet, nullptr));

	L_2_FNP(p)->FillNoiseSet(arrayP, L_2_VSP(pVS), xOffset, yOffset, zOffset);

	jEnv->ReleaseFloatArrayElements(noiseSet, arrayP, 0);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeFillSampledNoiseSetVector(JNIEnv* jEnv, jclass, jlong p, jfloatArray noiseSet, jlong pVS, jint xSize, jint ySize, jint zSize, jfloat xOffset, jfloat yOffset, jfloat zOffset)
{
	float* arrayP = static_cast<float*>(jEnv->GetFloatArrayElements(noiseSet, nullptr));

	L_2_FNP(p)->FillSampledNoiseSet(arrayP, L_2_VSP(pVS), xSize, ySize, zSize, xOffset, yOffset, zOffset);

	jEnv->ReleaseFloatArrayElements(noiseSet, arrayP, 0);
}

JNIEXPORT jlong JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewVectorSet(JNIEnv* jEnv, jclass, jint samplingScale, jfloatArray xSet, jfloatArray ySet, jfloatArray zSet)
{
	FastNoiseVectorSet* vectorSet = new FastNoiseVectorSet();

	vectorSet->size = static_cast<int>(jEnv->GetArrayLength(xSet));
	vectorSet->sampleScale = static_cast<int>(samplingScale);
	vectorSet->xSet = jEnv->GetFloatArrayElements(xSet, nullptr);
	vectorSet->ySet = jEnv->GetFloatArrayElements(ySet, nullptr);
	vectorSet->zSet = jEnv->GetFloatArrayElements(zSet, nullptr);

	return reinterpret_cast<jlong>(vectorSet);
}

JNIEXPORT void JNICALL Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_FreeVectorSet(JNIEnv*, jclass, jlong p)
{
	delete L_2_VSP(p);
}
