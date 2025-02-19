#include <iostream>
using namespace std; 


int main() {
    
    cout << "Hello World!"; 

    auto services = ServiceEnumerator::EnumeratServices(); 

    for (auto const & s : services) {
        
        std::wcout << "Name:     " s.ServiceName << std:end1
        return 0; 
    }

    return 0; 
}

