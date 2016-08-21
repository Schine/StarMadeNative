#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

#include "FastNoiseSIMD_JNI.h"

using namespace std;

// For debug only, don't include in release
int _tmain(int argc, _TCHAR* argv[])
{
	auto p = Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NewFastNoiseSIMD(nullptr, nullptr, 1234);
	Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetFrequency(nullptr, nullptr,p, 0.0008f);
	Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeSetSeed(nullptr, nullptr, p, 69);

	cout << Java_org_schema_game_server_controller_world_factory_planet_FastNoiseSIMD_NativeGetSeed(nullptr, nullptr, p) << endl;

	cout << "Press any key to exit" << endl;
	_getch();
}