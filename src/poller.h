#ifndef SERIAL_PORT_TRIAL_1_POLLER_H
#define SERIAL_PORT_TRIAL_1_POLLER_H

#include <napi.h>
#include <uv.h>
class Poller : public Napi::ObjectWrap<Poller> {
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Poller(const Napi::CallbackInfo & info);
    Napi::Value getFD(const Napi::CallbackInfo & info);
    void poll(const Napi::CallbackInfo & info);
    void onData(const Napi::CallbackInfo & info);
//    void execute();
//    void OnOk();
//    void OnError(const Napi::Error& e);
private:
    static Napi::FunctionReference constructor;
    int fileDscrpt;
    Napi::Function fb;
};
#endif //SERIAL_PORT_TRIAL_1_POLLER_H
