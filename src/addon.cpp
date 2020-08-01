#include <napi.h>
#include <windows.h>
#include <wlanapi.h>
#include <iostream>

#pragma comment(lib, "wlanapi.lib")
// #pragma comment(lib, "ole32.lib")
// #pragma comment(lib,"netapi32"

void OnNotificationCallback(PWLAN_NOTIFICATION_DATA Data, PVOID context) {
  using namespace std;
  cout << "HelloWorld\n";
  if (Data != NULL &&
      Data->NotificationSource == WLAN_NOTIFICATION_SOURCE_MSM &&
      Data->NotificationCode == wlan_notification_msm_signal_quality_change) {
        
  }
}

Napi::String Method(const Napi::CallbackInfo& info) {
	HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;      //    
	DWORD dwCurVersion = 0;
  DWORD dwResult = 0;
  dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
  // if (dwResult != ERROR_SUCCESS) {
  //     std::cerr << "WlanOpenHandle failed with error: " << dwResult << std::endl;
  //     return result;
  // }
  dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_ALL, TRUE, WLAN_NOTIFICATION_CALLBACK(OnNotificationCallback), NULL, NULL, NULL);
  // if (dwResult != ERROR_SUCCESS) {
  //     std::cerr << "WlanRegisterNotification failed with error: " << dwResult << std::endl;
  //     return result;
  // }
  // cout << "HelloWorld\n";
  Napi::Env env = info.Env();
  return Napi::String::New(env, "world");
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "hello"),
              Napi::Function::New(env, Method));
  return exports;
}

NODE_API_MODULE(hello, Init);