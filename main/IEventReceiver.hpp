/*
 * IEventReceiver.hpp
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef IEVENTRECEIVER_HPP_
#define IEVENTRECEIVER_HPP_

#include "Common/List.hpp"

class IEventReceiver {
public:
	enum EventId {
		WifiReady,
		WifiScanDone,
		WifiStart,
		WifiStop,
		WifiConnected,
		WifiDisconnected,
		WifiGotIp,
		WifiLostIp,
		EventAmount
	};

	IEventReceiver() {}

	virtual void onReceive(EventId event, void* params) = 0;

	List::Item item;

protected:
	virtual ~IEventReceiver(){}
};

#endif /* IEVENTRECEIVER_HPP_ */
