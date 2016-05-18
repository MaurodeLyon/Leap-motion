#include "stdafx.h"
#include "LeapInput.h"

#include "stdafx.h"

using namespace Leap;

void onConnect(const Controller& controller)
{
	std::cout << "Leap connected" << std::endl;
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Leap::Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Leap::Gesture::TYPE_INVALID);
}

float prevGesture;

void onFrame(const Leap::Controller& controller)
{
	auto frame = controller.frame();
	auto hands = frame.hands();
	auto pointables = frame.pointables();
	auto fingers = frame.fingers();
	auto frontHand = hands.frontmost();
	std::cout << "pitch :" << int((frontHand.palmNormal().pitch() * 180) / PI) << "	roll :" << int((frontHand.palmNormal().roll() * 180) / PI) << "		yaw :" << int((frontHand.palmNormal().yaw() * 180) / PI) << std::endl;
}

LeapInput::LeapInput()
{
}


LeapInput::~LeapInput()
{
}
