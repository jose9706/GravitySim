/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "raylib.h"
#include "Simulator.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	auto simulator = Simulator();
	simulator.ConfigRaylibWindow();

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");
	
	simulator.Simulate();
	return 0;
}
