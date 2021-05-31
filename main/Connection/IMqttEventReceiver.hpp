/*
 * IMqttEventReceiver.hpp
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef IMQTTEVENTRECEIVER_HPP_
#define IMQTTEVENTRECEIVER_HPP_

#include "../Common/List.hpp"
#include <string.h>

class IMqttEventReceiver {
public:

	struct MqttTopicDesc {
		int qos;
		const char* topic;
		List::Item item;
	};

	IMqttEventReceiver() {};

	virtual void onReceive(char* topic, size_t topicLen, char* data, size_t dataLen) = 0;

	void addTopic(MqttTopicDesc& desc) {
		mTopicList.addLast(desc.item);
	}

	List getTopicList() {
		return mTopicList;
	}

	bool isSubscribed(char* topic, size_t len) {
		bool result = false;
		List::Itterator itt = mTopicList.getItterator();
		while(itt) {
			MqttTopicDesc* desc = &containerOf(*(itt++), &MqttTopicDesc::item);
			if (memcmp(desc->topic, topic, len) == 0) {
				result = true;
				break;
			}
		}
		return result;
	}

//	int sendMessage(const char *topic, const char *data, int len, int retain = 0) {
//		return MqttApp::publishMessage(topic, data, len, mQos, retain);
//	}

	List::Item mItem;

protected:
	virtual ~IMqttEventReceiver(){}

	List mTopicList;
};

#endif /* IMQTTEVENTRECEIVER_HPP_ */
