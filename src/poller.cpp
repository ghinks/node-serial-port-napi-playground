#include "poller.h"
#include <iostream>
#include <napi.h>

Napi::FunctionReference Poller::constructor;

Poller::Poller(const Napi::CallbackInfo &info ) : Napi::ObjectWrap<Poller>(info) {
    Napi::Env env = info.Env();
    Napi::HandleScope scope(env);

    std::cout << "================================" << std::endl;
    fileDscrpt = info[0].As<Napi::Number>().Uint32Value();
}
/*
void Poller::execute() {
    std::cout << "execute" << std::endl;
}

void Poller::OnOk() {
    std::cout << "OnOk" << std::endl;
}

void Poller::OnError(const Napi::Error& e) {
    std::cout << "OnError " << e << std::endl;
}*/

Napi::Object Poller::Init(Napi::Env env, Napi::Object exports) {
 Napi::Function func = DefineClass(env, "Poller", {
         InstanceMethod("getFD", &Poller::getFD),
         InstanceMethod("poll", &Poller::poll),
         InstanceMethod("onData", &Poller::onData)
 });
 constructor = Napi::Persistent(func);
 constructor.SuppressDestruct();
 exports.Set("Poller", func);
 return exports;
};

Napi::Value Poller::getFD(const Napi::CallbackInfo &info){
 int num = this->fileDscrpt;
 return Napi::Number::New(info.Env(), num);
}

void Poller::poll(const Napi::CallbackInfo &info){
    std::cout << "native poll, queue some work" << std::endl;
    onData(info);
}

void Poller::onData(const Napi::CallbackInfo &info){
    std::cout << "native poll, onData" << std::endl;
    Napi::Env env = info.Env();
    Napi::Function cb = info[0].As<Napi::Function>();
    cb.Call(env.Global(), { Napi::String::New(env, "hello world") });
}

Napi::Object Init (Napi::Env env, Napi::Object exports) {
    Poller::Init(env, exports);
    return exports;
}

NODE_API_MODULE(Poller, Init)