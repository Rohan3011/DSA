#include<iostream>
#include<string>


std::string say_hello(std::string name){
	return "Hello " + name;
}

int main() {
    std::cout << "Hello World" << std::endl ;
    std::string name = "";
    std::cin >> name;
    std::cout << say_hello(name) << std::endl; 
}

