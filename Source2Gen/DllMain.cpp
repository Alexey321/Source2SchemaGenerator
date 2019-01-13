

#include "Source2Gen.hpp"

using namespace std;

void StartupThread() {
    Source2Gen generator("C:\\Users\\root\\Downloads\\Source2Gen-master\\bin\\Release\\generated");
    generator.GenerateHeaders();
}

int __stdcall DllMain(void* instance, unsigned int reason, void* reserved) {

	StartupThread();
    return 1;
}