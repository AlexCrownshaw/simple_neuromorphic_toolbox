#include <vector>
#include <iostream>

#include "simple_neuromorphic_toolbox.cpp"

int main() {
    // Define parameters to pass to Neuron class
	std::vector <Neuron> links{};
	std::vector <int> link_weights{0, 1, 2};

    // Create Neuron class
	Neuron n1(links, link_weights);

    // Print local variables and object variables
	std::cout << "main_weights: " << link_weights.at(0) << std::endl;
	std::cout << "class_weights: " << n1.weights.at(2) << std::endl;

    // Create subset of vector and print all elements
    std::vector<int> sub_weights {std::vector<int>(n1.weights.begin() + 1, n1.weights.end())};
	for (size_t i{}; i < sub_weights.size(); i++)	{
		std::cout << "sub_weights: " << sub_weights.at(i) << std::endl;
	}
	
}
