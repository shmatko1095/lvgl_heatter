/*
 * EventController.h
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef EVENTCONTROLLER_H_
#define EVENTCONTROLLER_H_

#include "IEventReceiver.hpp"
#include "Common/Pair.hpp"
#include "Common/List.hpp"
#include "Common/Types.h"
#include "Common/Map.hpp"

class EventController {
public:
	static void registerReceiver(IEventReceiver &receiver) {
		EventController &controller = EventController::getInstance();
		controller.runnables.addLast(receiver.item);
	}

	static void pushEvent(IEventReceiver::EventId event, void* params) {
		EventController &controller = EventController::getInstance();
		List::Itterator itt = controller.runnables.getItterator();
		while(itt) {
			containerOf(*(itt++), &IEventReceiver::item).onReceive(event, params);
		}
	}

private:
	static EventController &getInstance(){
	    static EventController controller;
	    return controller;
	}

	List runnables;
};

#endif /* EVENTCONTROLLER_H_ */
