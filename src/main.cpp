#include <napi.h>
#include <winsock2.h>
#include <windows.h>
#include <wlanapi.h>
#include <iostream>
#include "napi-thread-safe-callback.hpp"

#pragma comment(lib, "wlanapi.lib");

static std::shared_ptr<ThreadSafeCallback> notifyCallbackForJsFn = nullptr;

void OnNotificationCallback(PWLAN_NOTIFICATION_DATA data, PVOID context) {
  if (data != NULL && data->NotificationSource == WLAN_NOTIFICATION_SOURCE_ACM) {
    switch(data->NotificationCode) {
      case wlan_notification_acm_connection_complete: {
        char tArg0[50] = "wlan_notification_acm_connection_complete";

        // safe thread call
        notifyCallbackForJsFn -> call([tArg0](Napi::Env env, std::vector<napi_value>& args) {
          // will run in main thread
          args = { Napi::String::New(env, tArg0) };
        });
      } break;
      case wlan_notification_acm_disconnected: {
        char tArg0[50] = "wlan_notification_acm_disconnected";

        // safe thread call
        notifyCallbackForJsFn -> call([tArg0](Napi::Env env, std::vector<napi_value>& args) {
          // will run in main thread
          args = { Napi::String::New(env, tArg0) };
        });
      } break;
      case wlan_notification_acm_scan_complete: {
        char tArg0[50] = "wlan_notification_acm_scan_complete";

        // safe thread call
        notifyCallbackForJsFn -> call([tArg0](Napi::Env env, std::vector<napi_value>& args) {
          // will run in main thread
          args = { Napi::String::New(env, tArg0) };
        });
      } break;
    }   
  }
}

void RunCallback(const Napi::CallbackInfo& info) {
  // TODO info[0] is the event name
  notifyCallbackForJsFn = std::make_shared<ThreadSafeCallback>(info[1].As<Napi::Function>());

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
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "addEventListener"), Napi::Function::New(env, RunCallback));
  return exports;
}

NODE_API_MODULE(main, Init);