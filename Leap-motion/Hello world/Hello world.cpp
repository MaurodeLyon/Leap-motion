// Hello world.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <Leap/Leap.h>

using namespace Leap;

class SampleListener : public Listener {
public:
	virtual void onConnect(const Controller&);
	virtual void onFrame(const Controller&);
};

void SampleListener::onConnect(const Controller& controller)
{
	std::cout << "Connected" << std::endl;
	controller.enableGesture(Gesture::TYPE_SWIPE);
	controller.enableGesture(Gesture::TYPE_CIRCLE);
	controller.enableGesture(Gesture::TYPE_KEY_TAP);
	controller.enableGesture(Gesture::TYPE_SCREEN_TAP);
	controller.enableGesture(Gesture::TYPE_INVALID);
}

void SampleListener::onFrame(const Controller& controller)
{
	auto frame = controller.frame();
	auto hands = frame.hands();
	auto pointables = frame.pointables();
	auto fingers = frame.fingers();
	auto tools = frame.tools();
	std::cout << "hands: " << hands.count() << " pointables: " << pointables.count() << " fingers: " << fingers.count() << " tools: " << tools.count() << std::endl;
	

	//std::cout << "Frame id: " << frame.id() << ", timestamp: " << frame.timestamp() << ", hands: " << frame.hands().count() << ", fingers: " << frame.fingers().count() << ", tools: " << frame.tools().count() << ", gestures: " << frame.gestures().count() << std::endl;
	/*for each(Hand hand in frame.hands())
	{
		for each(Finger finger in hand.fingers()) {
			std::cout << finger.TYPE_MIDDLE << std::endl;
		}
	}*/
}


int main(int argc, char** argv) {
	SampleListener listener;
	Controller controller;

	controller.addListener(listener);

	// Keep this process running until Enter is pressed
	std::cout << "Press Enter to quit..." << std::endl;
	std::cin.get();

	controller.removeListener(listener);

	return 0;
}