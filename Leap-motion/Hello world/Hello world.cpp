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

	auto frontHand = hands.frontmost();
	auto handPosition = frontHand.palmPosition();
	std::cout << "X: " << int (handPosition.x) << " Y: " << int ( handPosition.y) << " Z: " << int(handPosition.z) << std::endl;
	
	//display hand info
	//std::cout << "hands: " << hands.count() << " pointables: " << pointables.count() << " fingers: " << fingers.count() << " tools: " << tools.count() << std::endl;

	//display gestures
	/*auto circle = 0;
	auto swipe = 0;
	auto keytap = 0;
	auto screentap = 0;
	Leap::GestureList gestures = frame.gestures();
	for (Leap::GestureList::const_iterator gl = gestures.begin(); gl != frame.gestures().end(); gl++)
	{
		switch ((*gl).type()) {
		case Leap::Gesture::TYPE_CIRCLE:
			//Handle circle gestures
			circle++;
			break;
		case Leap::Gesture::TYPE_KEY_TAP:
			//Handle key tap gestures
			keytap++;
			break;
		case Leap::Gesture::TYPE_SCREEN_TAP:
			//Handle screen tap gestures
			screentap++;
			break;
		case Leap::Gesture::TYPE_SWIPE:
			//Handle swipe gestures
			swipe++;
			break;
		default:
			//Handle unrecognized gestures
			break;
		}
		std::cout << "Circle: " << circle << "\t swipe: " << swipe << "\t keytap: " << keytap << "\t screentap: " << screentap << std::endl;
	}*/

	//displayframe info
	/*std::cout << "Frame id: " << frame.id() << ", timestamp: " << frame.timestamp() << ", hands: " << frame.hands().count() << ", fingers: " << frame.fingers().count() << ", tools: " << frame.tools().count() << ", gestures: " << frame.gestures().count() << std::endl;
	for each(Hand hand in frame.hands())
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