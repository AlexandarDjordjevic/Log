#include "Log.hpp"

int main(){
    Log::error << "This is error" << endl;
    Log::warning << "This is warning" << endl;
    Log::info << "This is info " << 1.5 << 4 << true << endl;
    return 0;
}