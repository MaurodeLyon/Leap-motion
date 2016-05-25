// Hello World.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

Leap::Controller controller;

int main()
{
	auto listener = LeapInput();
	controller.addListener(listener);
	std::cout << "Hello world" << std::endl;
	while (true);
    return 0;
}

