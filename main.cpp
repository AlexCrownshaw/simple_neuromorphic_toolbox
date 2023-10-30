#include <vector>
#include <iostream>

#include "simple_neuromorphic_toolbox.cpp"

int main() {

	std::vector <int> structure {2, 2, 1};
	std::vector <std::vector<double>> inputs {};
	std::vector <std::vector<double>> outputs {};

	std::vector <double> input_vars {0.f, 1.f};

	// Create input and expected output vectors for XOr operation
	for (int i_var {}; i_var < input_vars.size(); i_var++)	{
		for (int j_var {}; j_var < input_vars.size(); j_var++)	{
			// Populate inputs
			inputs.push_back(std::vector <double> {input_vars.at(i_var), input_vars.at(j_var)});

			// Compute XOr output
			outputs.push_back(std::vector <double> {abs(input_vars.at(i_var) - input_vars.at(j_var))});
		}
	}

	Network nn(structure);
	nn.setInputs(inputs);
	nn.setExpOutputs(outputs);
	nn.run(1);

	std::cout << "stop";
}
