#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "FastNoiseSIMD_JNI.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//auto pv = Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewVectorSet(nullptr, nullptr, 0, new jfloatArray());

	auto p = Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD(nullptr, nullptr, 1234);
	Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency(nullptr, nullptr,p, 0.0008f);
	Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed(nullptr, nullptr, p, 69);

	cout << Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed(nullptr, nullptr, p) << endl;

	cout << "Press any key to exit" << endl;
	_getch();
}