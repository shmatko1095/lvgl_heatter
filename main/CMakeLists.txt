idf_component_register(
SRCS main.cpp  
	Application.cpp
	Model.cpp 
	SchedulerApp.cpp
	SpiFfsStorrage.cpp
	SpiFfsStorrage.h	
	IEventReceiver.hpp	
	
	Common/List.hpp
	
	Core/BaseTask.hpp
	Core/Mutex.hpp
	Core/MutexLocker.hpp
	Core/Queue.hpp
	Core/Semaphore.hpp
	Core/SYSDelay.hpp
	Core/SYSPort.cpp
	Core/SYSPort.hpp
	Core/SYSTime.hpp
	
	GuiApp/GuiApp.cpp
	GuiApp/BaseScreen.cpp	
	GuiApp/MainScreen.cpp
	GuiApp/InfoScreen.cpp
	GuiApp/SettingsScreen.cpp
	GuiApp/WifiSettingsScreen.cpp
	GuiApp/TempSetpointContainer.cpp
	GuiApp/res/clock.c	
	GuiApp/res/calendar.c		
	GuiApp/res/shutdown.c	
	GuiApp/res/snowflake.c
	GuiApp/res/more.c
	
	Connection/WifiStorageUl.cpp
	Connection/WifiManager.cpp
	Connection/CoAPApp.cpp	
	Connection/MqttApp.cpp
	Connection/BleApp.cpp	
	
	Modem/esp_modem.c
    Modem/esp_modem_dce_service
    Modem/esp_modem_netif.c
    Modem/esp_modem_compat.c
    Modem/sim800.c
    Modem/sim7600.c
    Modem/bg96.c
        
INCLUDE_DIRS "."
EMBED_TXTFILES Connection/certs/coap_ca.pem 
	Connection/certs/coap_client.crt 
	Connection/certs/coap_client.key
)