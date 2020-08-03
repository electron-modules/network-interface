#include <napi.h>
#include <winsock2.h>
#include <windows.h>
#include <wlanapi.h>
#include <iostream>
#include "napi-thread-safe-callback.hpp"

#pragma comment(lib, "wlanapi.lib");

static std::shared_ptr<ThreadSafeCallback> notifyCallbackForJsFn = nullptr;

void OnNotificationCallback(PWLAN_NOTIFICATION_DATA data, PVOID context) {
  char tArg0[50] = "wlan-changed";

  // safe thread call
  notifyCallbackForJsFn -> call([tArg0](Napi::Env env, std::vector<napi_value>& args) {
    // will run in main thread
    args = { Napi::String::New(env, tArg0) };
  });
  if (data != NULL &&
      data->NotificationSource == WLAN_NOTIFICATION_SOURCE_MSM &&
      data->NotificationCode == wlan_notification_msm_signal_quality_change) {
        
  }
}

void RunCallback(const Napi::CallbackInfo& info) {
  HANDLE hClient = NULL;
	DWORD dwMaxClient = 2;  
	DWORD dwCurVersion = 0;
  DWORD dwResult = 0;
  dwResult = WlanOpenHandle(dwMaxClient, NULL, &dwCurVersion, &hClient);
  // if (dwResult != ERROR_SUCCESS) {
  //     std::cerr << "WlanOpenHandle failed with error: " << dwResult << std::endl;
  //     return result;
  // }
  dwResult = WlanRegisterNotification(hClient, WLAN_NOTIFICATION_SOURCE_ACM, TRUE, WLAN_NOTIFICATION_CALLBACK(OnNotificationCallback), NULL, NULL, NULL);
  // if (dwResult != ERROR_SUCCESS) {
  //     std::cerr << "WlanRegisterNotification failed with error: " << dwResult << std::endl;
  //     return result;
  // }
  notifyCallbackForJsFn = std::make_shared<ThreadSafeCallback>(info[0].As<Napi::Function>());
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "addEventLisener"),
              Napi::Function::New(env, RunCallback));
  return exports;
}

NODE_API_MODULE(addon, Init);