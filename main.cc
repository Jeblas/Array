#include <iostream>
#include <vector>
#include <simple_string.h>
#include <array.h>
//test your code here

int main() {
    //std::cout << "Hello, World!" << std::endl;
	simple_string::initialize_counts();
	std::vector<simple_string> my_vector(5);
	simple_string::print_counts();
	
	std::cout << '\n';

	simple_string::initialize_counts();
        //array<simple_string> my_array;
	array<simple_string> my_array(4444);
	simple_string::print_counts();
    return 0;
}
