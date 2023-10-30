#include <vector>
#include <iostream>

#include "simple_neuromorphic_toolbox.cpp"

int main() {
	
    // // Define parameters to pass to Neuron class
	// std::vector <Node> links{};
	// std::vector <double> link_weights{0.f, 1.f, 2.f};

    // // Create Neuron class
	// Node n1(links, link_weights);

    // // Print local variables and object variables
	// std::cout << "main_weights: " << link_weights.at(0) << std::endl;
	// std::cout << "class_weights: " << n1.getWeights().at(2) << std::endl;

    // // Create subset of vector and print all elements
    // std::vector<double> class_weights {n1.getWeights()};
    // std::vector<double> sub_weights {std::vector<double>(n1.getWeights().begin() + 1, n1.getWeights().end())};
	// for (size_t i{}; i < sub_weights.size(); i++)	{
	// 	std::cout << "sub_weights: " << sub_weights.at(i) << std::endl;
	// }

	// Link link;
	// link.weight = 1.0;

	std::vector <int> structure_main {2, 2, 2};
	std::cout << structure_main.size();
	Network nn(structure_main);
}
