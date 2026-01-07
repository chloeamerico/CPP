#include <vector>
#include <iostream>

int main(void)
{
	std::vector<int> numbers;

	std::cout << "Capacity : " << numbers.capacity() << std::endl;

	for (int i = 0; i < 5; i++)
	{
		numbers.push_back(i);		//pour remplir
		// std::cout << "Capacity : " << numbers.capacity() << std::endl;
		// std::cout << "Element " << i << " : " << numbers[i] << std::endl;


	}
	
	// //pour afficher
	// for (size_t i = 0; i < numbers.size(); i++)
	try
	{
		std::cout << "Element 0 : " << numbers.at(10) << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';

	}

	// std::cout << "Capacity : " << numbers.capacity() << std::endl;
	return (0);
}