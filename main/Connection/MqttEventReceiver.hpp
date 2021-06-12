/*
 * MqttEventReceiver.hpp
 *
 *  Created on: May 28, 2021
 *      Author: f73377
 */

#ifndef IMQTTEVENTRECEIVER_HPP_
#define IMQTTEVENTRECEIVER_HPP_

#include "../Common/List.hpp"
#include <string.h>

class MqttEventReceiver {
public:

	struct MqttTopicDesc {
	public:
		MqttTopicDesc(const char* topicIn, const char* topicOut, int qos) :
			mTopicIn(topicIn), mTopicOut(topicOut), mQos(qos){};
		const char* getTopicIn() {
			return mTopicIn;
		}
		const char* getTopicOut(){
			return mTopicOut;
		}
		int getQos() {
			return mQos;
		}

		List::Item mItem;
	private:
		const char* mTopicIn;
		const char* mTopicOut;
		int mQos;
	};

	MqttEventReceiver() {};

	virtual void onReceive(char* topic, size_t topicLen, char* data, size_t dataLen) = 0;

	void addTopic(MqttTopicDesc& desc) {
		mTopicList.addLast(desc.mItem);
	}

	List getTopicList() {
		return mTopicList;
	}

	bool isSubscribed(char* topic, size_t len) {
		bool result = false;
		List::Itterator itt = mTopicList.getItterator();
		while(itt) {
			MqttTopicDesc* desc = &containerOf(*(itt++), &MqttTopicDesc::mItem);
			if (memcmp(desc->getTopicIn(), topic, len) == 0) {
				result = true;
				break;
			}
		}
		return result;
	}

	List::Item mItem;

protected:
	virtual ~MqttEventReceiver(){}

	List mTopicList;
};

#endif /* IMQTTEVENTRECEIVER_HPP_ */
