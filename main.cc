#include <iostream>
#include <vector>
#include "simple_string.h"
#include "array.h"

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//NOTE THIS IS NOT A COMPLETE LISTING OF TESTS THAT WILL BE RUN ON YOUR CODE
//Just a sample to help get you started and give you an idea of how i'll be testing
//Above each test gives the counts for std::vector and the solution i've written for your array
//As well as checking totals ensure your array doesn't leak memory
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//comment/uncomment these lines to enable tests
//#define TEST_PUSH_BACK_NEW_VEC
//#define TEST_CLEAR
//#define TEST_PUSH_FRONT_VEC
//#define TEST_PUSH_FRONT_WITH_RESERVE
//#define TEST_POP_BACK
//#define TEST_INITIALIZER_LIST
//#define TEST_POP_FRONT
//#define TEST_INITIALIZER_CONSTRUCTOR
//#define TEST_1
#define TEST_2

using std::vector;
//test your code here

int main() {

#ifdef TEST_CLEAR
    //Vector                    Array
    //Default: 0                Default: 0
    //Create: 0                 Create: 0
    //Copy: 0                   Copy: 0
    //Assign: 0                 Assign: 0
    //Destruct: 2               Destruct: 2
    //Move Construct: 0         Move Construct: 0
    //Move Assign: 0            Move Assign: 0

    {
        std::cout << "Vector" << std::endl;
        simple_string a("Goober");
        vector<simple_string> vec;
        vec.push_back(a);
        vec.push_back(a);
        simple_string::initialize_counts();
        vec.clear();
        simple_string::print_counts();

        std::cout << "Array" << std::endl;
        array<simple_string> arr;
        arr.push_back(a);
        arr.push_back(a);
        simple_string::initialize_counts();
        arr.clear();
        simple_string::print_counts();
    }
#endif

#ifdef TEST_POP_FRONT
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 0               Copy: 0
    //Assign: 0             Assign: 0
    //Destruct: 1           Destruct: 1
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 2        Move Assign: 2

    {
        simple_string a("Goober");
        simple_string b("Gabber");
        simple_string c("Gupper");

        std::cout << "Vector" << std::endl;
        vector<simple_string> vec;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        simple_string::initialize_counts();
        //note: std::vec does not have pop_front
        vec.erase(vec.begin());
        simple_string::print_counts();

        std::cout << "Array" << std::endl;
        array<simple_string> arr;
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        simple_string::initialize_counts();
        arr.pop_front();
        simple_string::print_counts();
    }

#endif

#ifdef TEST_POP_BACK
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 0               Copy: 0
    //Assign: 0             Assign: 0
    //Destruct: 1           Destruct: 1
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 0        Move Assign: 0
    {
        simple_string a("Goober");


        std::cout << "Vector" << std::endl;
        vector<simple_string> vec;
        vec.push_back(a);
        simple_string::initialize_counts();
        vec.pop_back();
        simple_string::print_counts();


        std::cout << "Array" << std::endl;
        array<simple_string> arr;
        arr.push_back(a);
        simple_string::initialize_counts();
        arr.pop_back();
        simple_string::print_counts();
    }
#endif

#ifdef TEST_PUSH_FRONT_WITH_RESERVE
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 1               Copy: 1
    //Assign: 0             Assign: 0
    //Destruct: 0           Destruct: 0
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 0        Move Assign: 0

    {
        simple_string a("Goober");

        simple_string::initialize_counts();
        std::cout << "Vector" << std::endl;
        vector<simple_string> vec;
        vec.reserve(2);
        vec.insert(vec.begin(), a);
        simple_string::print_counts();

        simple_string::initialize_counts();
        std::cout << "Array" << std::endl;
        array<simple_string> arr;
        arr.reserve(2);
        arr.push_front(a);
        simple_string::print_counts();
    }
#endif

#ifdef TEST_PUSH_FRONT_VEC
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 1               Copy: 1
    //Assign: 0             Assign: 0
    //Destruct: 2           Destruct: 2
    //Move Construct: 2     Move Construct: 2
    //Move Assign: 0        Move Assign: 0

    {
        simple_string a;
        simple_string b("Foob");
        std::cout << "Vector" << std::endl;

        vector<simple_string> vec;
        vec.push_back(a);
        vec.push_back(a);
        simple_string::initialize_counts();
        //note std::vector doesn't have a push_front
        vec.insert(vec.begin(), b);
        simple_string::print_counts();

        std::cout << "Array" << std::endl;
        array<simple_string> arr;
        arr.push_back(a);
        arr.push_back(a);
        simple_string::initialize_counts();
        arr.push_front(b);
        simple_string::print_counts();
    }

#endif

#ifdef TEST_PUSH_BACK_NEW_VEC

    //Push back new vec with no reserve
    //
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 1               Copy: 1
    //Assign: 0             Assign: 0
    //Destruct: 0           Destruct: 0
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 0        Move Assign: 0
    {
        simple_string a;

        std::cout << "Vector" << std::endl;
        simple_string::initialize_counts();
        vector<simple_string> vec;
        vec.push_back(a);
        vec.push_back(a);
        vec.push_back(a);
        simple_string::print_counts();

        std::cout << "Array" << std::endl;
        simple_string::initialize_counts();
        array<simple_string> arr;
        arr.push_back(a);
        arr.push_back(a);
        arr.push_back(a);
        simple_string::print_counts();
    }
#endif

#ifdef TEST_INITIALIZER_LIST

    //Test initializer list
    //
    //Vector                  Array
    //Default: 0              Default: 0
    //Create: 0               Create: 0
    //Copy: 4                 Copy: 4
    //Assign: 0               Assign: 0
    //Destruct: 2             Destruct: 2
    //Move Construct: 0       Move Construct: 0
    //Move Assign: 0          Move Assign: 0

    {
        simple_string a;
        simple_string b;
        simple_string c;
 
        std::cout << "Vector" << std::endl;
        simple_string::initialize_counts();
        vector<simple_string> vec({a, b});
        simple_string::print_counts();

        std::cout << "Array" << std::endl;
        simple_string::initialize_counts();
        array<simple_string> arr({a, b});
        simple_string::print_counts();

        std::cout << vec[0] << std::endl;
        std::cout << vec[1] << std::endl;
        std::cout << arr[0] << std::endl;
        std::cout << arr[1] << std::endl;
    }
#endif

#ifdef TEST_INITIALIZER_CONSTRUCTOR

    //Test initializer list
    //
    //Vector                  Array
    //Default: 0              Default: 0
    //Create: 0               Create: 0
    //Copy: 2                 Copy: 2
    //Assign: 0               Assign: 0
    //Destruct: 2             Destruct: 2
    //Move Construct: 0       Move Construct: 0
    //Move Assign: 0          Move Assign: 0

    {
        simple_string a("wasd");
        simple_string b("dsaw");
        simple_string c;
 
        std::cout << "--Vector--" << std::endl;
        vector<simple_string> vec({a, b});
        vec.push_back(c);
        vector<simple_string> vec2;

        simple_string::initialize_counts();
        vector<simple_string> vec1(vec);
        simple_string::print_counts();

        std::cout << "--Array--" << std::endl;
        array<simple_string> arr({a, b});
        arr.push_back(c);
        simple_string::initialize_counts();
        array<simple_string> arr1(arr);
        simple_string::print_counts();
            
        std::cout << vec1[0] << std::endl;
        std::cout << vec1[1] << std::endl;
        std::cout << arr1.front() << std::endl;
        std::cout << arr1.back() << std::endl;
        std::cout << "\a" << std::endl;    

        std::cout << "-------\n";
    
        simple_string::initialize_counts();
        vector<simple_string> test_vec(5);
        vector<simple_string> test_vec1(test_vec);
        //test_vec1 = std::move(test_vec);
        simple_string::print_counts();

        std::cout << "-------\n";
    
        simple_string::initialize_counts();
        array<simple_string> test_arr(2);
        array<simple_string> test_arr1(test_arr);
        test_arr1 = std::move(test_arr);
        simple_string::print_counts();

        array<simple_string> arrwasd(2);
        bool temp_bool = (test_arr.begin()++ == test_arr.end());
        std::cout << temp_bool << std::endl;
        std::cout << "===============\n";


        simple_string::initialize_counts();
        vector<simple_string> t_vec(5);
	auto it_v = t_vec.begin();
	++it_v;
	t_vec.erase(it_v);
        simple_string::print_counts();

        std::cout << "-------\n";
    
        simple_string::initialize_counts();
        array<simple_string> t_arr(5);
	auto it_a = t_arr.begin();
	++it_a;
	t_arr.erase(it_a);
        simple_string::print_counts();

    }    
    
#endif
#ifdef TEST_1
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 0               Copy: 0
    //Assign: 0             Assign: 0
    //Destruct: 1           Destruct: 1
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 0        Move Assign: 0
    {

        simple_string a("Goober");
        simple_string b("Gaaber");
        simple_string c("Geeber");

        std::cout << "Vector" << std::endl;
        vector<simple_string> vec;
	std::cout << vec.capacity() << std::endl;
	vec.push_back(a);
	vec.push_back(c);
	vec.push_back(c);
	std::cout << vec.size() << std::endl;
        simple_string::initialize_counts();
        vec.insert(++(vec.begin()), b);
        simple_string::print_counts();
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << std::endl;
	}


	std::cout << "test" << std::endl;

        std::cout << "Array" << std::endl;
        array<simple_string> arr;
	//std::cout << arr.length() << std::endl;
        arr.push_back(a);
        arr.push_back(c);
        arr.push_back(c);
	std::cout << arr.length() << std::endl;
        simple_string::initialize_counts();
	std::cout << "test"<< std::endl;
        arr.insert(b,++(++arr.begin()));
        simple_string::print_counts();
	for (int i = 0; i < arr.length(); ++i) {
		std::cout << arr[i] << std::endl;
	}

    }
#endif
#ifdef TEST_2
    //Vector                Array
    //Default: 0            Default: 0
    //Create: 0             Create: 0
    //Copy: 0               Copy: 0
    //Assign: 0             Assign: 0
    //Destruct: 1           Destruct: 1
    //Move Construct: 0     Move Construct: 0
    //Move Assign: 0        Move Assign: 0
    {

        simple_string a("Goober");
        simple_string b("Gaaber");
        simple_string c("Geeber");

        std::cout << "--Vector--" << std::endl;
        simple_string::initialize_counts();
        vector<simple_string> vec(3,b);
        vector<simple_string> vec1(std::move(vec));
//	vec1.reserve(6);
	vec1.push_back(a);
	vec1[0] = vec1[3];
	//vec.insert(vec1.begin(), c);
	//vec.erase(vec1.begin());
        simple_string::print_counts();
	std::cout << vec.size() << std::endl;

        std::cout << "--Array--" << std::endl;
        simple_string::initialize_counts();
        array<simple_string> arr(3,b);
        array<simple_string> arr1(std::move(arr));
	//arr1.reserve(15);
	arr1.push_back(a);
	arr1[0] = arr1.back();
	//arr1.push_front(c);
	//arr1.pop_front();
	//arr.erase(++arr1.begin());
	//arr1.clear();
        simple_string::print_counts();
	std::cout << arr.length() << std::endl;

	auto it = arr1.begin();
	while (it != arr1.end()) {
	    std::cout << *it << std::endl;
	    it++;
	}

    }
#endif

    return 0;
}
