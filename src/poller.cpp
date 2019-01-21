#include "poller.h"
#include <iostream>
#include <napi.h>

Napi::FunctionReference Poller::constructor;

Poller::Poller(const Napi::CallbackInfo &info) : Napi::ObjectWrap<Poller>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);
}

Napi::Object Poller::Init(Napi::Env env, Napi::Object exports) {
 // This method is used to hook the accessor and method callbacks
 Napi::Function func = DefineClass(env, "Poller", {
         InstanceMethod("getFD", &Poller::getFD)
 });

 // Create a peristent reference to the class constructor. This will allow
 // a function called on a class prototype and a function
 // called on instance of a class to be distinguished from each other.
 constructor = Napi::Persistent(func);
 // Call the SuppressDestruct() method on the static data prevent the calling
 // to this destructor to reset the reference when the environment is no longer
 // available.
 constructor.SuppressDestruct();
 exports.Set("Poller", func);
 return exports;
};

Napi::Value Poller::getFD(const Napi::CallbackInfo &info){
 int num = this->fileDscrpt;
 return Napi::Number::New(info.Env(), num);
}

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    Poller::Init(env, exports);
    return exports;
}

NODE_API_MODULE(Poller, Init)