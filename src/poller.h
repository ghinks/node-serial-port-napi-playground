#ifndef SERIAL_PORT_TRIAL_1_POLLER_H
#define SERIAL_PORT_TRIAL_1_POLLER_H

#include <napi.h>

class Poller : public Napi::ObjectWrap<Poller>{
public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    Poller(const Napi::CallbackInfo & info);
    Napi::Value getFD(const Napi::CallbackInfo & info);
private:
    static Napi::FunctionReference constructor;
    int fileDscrpt;
};
#endif //SERIAL_PORT_TRIAL_1_POLLER_H
